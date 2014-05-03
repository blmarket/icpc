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

int ff[55][55];
int tt[55][55];
vector<bool> visited;

ostringstream ost;

bool solvable(vector<int> &stack) {
    memcpy(tt, ff, sizeof(tt));
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) if(tt[i][k]) {
            for(int j=0;j<n;j++) if(tt[k][j]) {
                tt[i][j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++) if(!visited[i]) {
        bool good = false;
        for(int j=0;j<size(stack);j++) {
            if(tt[stack[j]][i]) { good = true; break; }
        }
        if(!good) return false;
    }
    return true;
}

void go(int a, vector<int> &stack) {
    ost << label[a];
    visited[a] = true;
    stack.pb(a);

    vector<pair<int, PII> > candis;
    vector<bool> copy_visited = visited;

    vector<int> V = stack;
    while(V.size()) {
        for(int i=0;i<n;i++) if(!copy_visited[i]) if(ff[V.back()][i]) {
            copy_visited[i] = true;
            candis.pb(mp(label[i], mp(i, size(V))));
        }
        V.pop_back();
        if(!solvable(V)) break;
    }

    if(candis.size() == 0) return;
    sort(candis.begin(), candis.end());
    int npos = candis[0].second.first;
    int nstack = candis[0].second.second;
    stack.resize(nstack);

    ff[stack.back()][npos] = 0;
    ff[npos][stack.back()] = 0;

    go(npos, stack);
}

void solve(int dataId)
{
    printf("Case #%d: ", dataId);

    for(int i=0;i<n;i++) {
        for(int j=0;j<size(links[i]);j++) {
            ff[i][links[i][j]] = 1;
        }
    }

    int minlabel = 999999;
    int mm = -1;
    for(int i=0;i<n;i++) {
        if(minlabel > label[i]) {
            minlabel = label[i];
            mm = i;
        }
    }

    vector<int> V;
    visited.clear();
    visited.resize(n+1);
    ost.clear();
    go(mm, V);
    cout << ost.str() << endl;
}

void process(int dataId)
{
    cin >> n >> m;
    for(int i=0;i<n;i++) links[i].clear();
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


