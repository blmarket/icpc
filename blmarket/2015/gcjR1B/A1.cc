#include <iostream>
#include <unistd.h>
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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

long long target;
map<long long, int> cnts;

long long rev(long long a) {
    ostringstream sout;
    sout << a;
    string tmp = sout.str();
    reverse(tmp.begin(), tmp.end());
    istringstream sin(tmp);
    sin >> a;
    return a;
}

void solve(int dataId)
{
    cnts.clear();
    printf("Case #%d: ", dataId);
    cnts[1] = 1;
    queue<LL> Q;
    Q.push(1);

    while(!Q.empty()) {
        LL tmp = Q.front();
        int cc = cnts[tmp];
        Q.pop();
        auto addif = [&](long long v) -> bool {
            if(cnts.count(v) == 0) {
                cnts[v] = cc+1;
                Q.push(v);
            }
            return v == target;
        };
        if(addif(tmp+1)) break;
        if(addif(rev(tmp))) break;
    }

    for(auto it : cnts) {
        long long tmp = rev(it.first);
        if(cnts.count(tmp) && cnts[tmp] == it.second - 1) {
            cout << it.first << "=" << it.second << endl;
        }
    }

    cout << cnts[target] << endl;
}

void process(int dataId)
{
    cin >> target;
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
        while((sz = read(solver.outfds[i].second, buffer, sizeof(buffer))))
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
        nchilds++;
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


