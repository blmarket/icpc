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

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

class ForkSolver {
public:
    vector<pair<pid_t,int> > outfds;
    void solve(int dataId);
} solver;

void solve(int dataId)
{
    // do solve data here
    cerr << 0 << endl;
    printf("0\n",dataId);
}

void process(int dataId)
{
    // do read data here
}

int main(void)
{
    int N;
    cin >> N;
    solver.outfds.resize(N+1);
    for(int i=1;i<=N;i++)
    {
        process(i);
        solver.solve(i);
    }
    for(int i=1;i<=N;i++)
    {
        cerr << i << " " << solver.outfds[i].first << "," << solver.outfds[i].second << endl;
        int status;
        char buffer[8192];
        waitpid(solver.outfds[i].first, &status, 0);
        cerr << "status = " << status << endl;
        ssize_t sz;
        while(sz = read(solver.outfds[i].second, buffer, sizeof(buffer)))
        {
            cerr << "Read " << sz << endl;
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

void ForkSolver::solve(int dataId)
{
    int pipefd[2];

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


