#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define MULTI 2

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int n, m;
int label[55];
vector<int> links[55];

void solve(int dataId)
{
    printf("Case #%d: ", dataId);

    vector<int> V;
    for(int i=0;i<n;i++) V.pb(i);

    string ret;
    do {
        ostringstream ost;
        ost << label[V[0]];
        vector<int> stak;
        stak.pb(V[0]);
        for(int i=1;i<size(V);i++) {
            ost << label[V[i]];
            while(stak.size() > 0){
                vector<int> &l = links[stak.back()];
                if(find(l.begin(), l.end(), V[i]) != l.end()) {
                    break;
                }
                stak.pop_back();
            }
            if(stak.size() == 0) break;
            stak.pb(V[i]);
        }
        if(stak.size() == 0) continue;
        string tmp = ost.str();
        if(ret == "" || ret > tmp) ret = tmp;
    } while(next_permutation(V.begin(), V.end()));
    cout << ret << endl;
}

void process(int dataId)
{
    cin >> n >> m;
    for(int i=0;i<n;i++) links[i+1].clear();
    for(int i=0;i<n;i++) cin >> label[i];
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        links[a].pb(b);
        links[b].pb(a);
    }
}

class ForkSolver {
public:
    ForkSolver() : nchilds(0) { }

    vector<pair<pid_t,int> > outfds;
    void _solve(int dataId);
    int nchilds;
} solver;

int main(void)
{
    int N;
    cin >> N;
    solver.outfds.resize(N+1);
    for(int i=1;i<=N;i++)
    {
        process(i);
        solver._solve(i);
    }
    for(int i=1;i<=N;i++)
    {
        int status;
        char buffer[8192];
        waitpid(solver.outfds[i].first, &status, 0);
        ssize_t sz;
        while(sz = read(solver.outfds[i].second, buffer, sizeof(buffer)))
        {
            ssize_t iter = 0, outsz;

            while(iter != sz)
            {
                outsz = write(1, buffer + iter, sz - iter);
                if(outsz == -1)
                {
                    perror("write");
                    exit(-1);
                }
                iter += outsz;
            }
        }
    }
}

void ForkSolver::_solve(int dataId)
{
    int pipefd[2];

    while(nchilds >= MULTI)
    {
        int status = 0;
        int ret = waitpid(-1, &status, 0);
        if(ret == -1)
            perror("waitpid");
        else
            nchilds--;
    }

    pipe(pipefd);
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(-1);
    }

    if(pid) // I'm parent!
    {
        close(pipefd[1]); // close write end, i'll only read
        outfds[dataId] = mp(pid, pipefd[0]);
    }
    else
    {
        if(close(pipefd[0]) == -1) perror("close");
        if(dup2(pipefd[1], 1) == -1) perror("dup2");
        if(close(pipefd[1]) == -1) perror("close");
        solve(dataId);
        fprintf(stderr, "%d\n", dataId);
        exit(0); // force exit
    }
}


