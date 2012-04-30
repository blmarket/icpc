#include <iostream>
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

#define MULTI 1

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int n,m;
double prob[100005];

void solve(int dataId)
{
    double ret = 1 + n;
    double tot = 1;
    for(int i=0;i<m;i++)
    {
        tot *= prob[i];
        double esti = tot * (m-1-i + n-1-i) + (1-tot) * (m-1-i+n-1-i+n+1);
        if(esti < ret) ret = esti;
    }
    printf("Case #%d: %.12lf\n", dataId, ret + 1);
}

void process(int dataId)
{
    cin >> m >> n;
    for(int i=0;i<m;i++)
        cin >> prob[i];
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
                outsz = write(0, buffer + iter, sz - iter);
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
        close(pipefd[0]);
        dup2(pipefd[1], 0);
        close(pipefd[1]);
        solve(dataId);
        exit(0); // force exit
    }
}


