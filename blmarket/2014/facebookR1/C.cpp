#include <iostream>
#include <tuple>
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

int N,M;
char data[510][510];

int maxr[510][510];

int go(int a, int b) {
    if(a >= N || b >= M || data[a][b] == '#') return -1;
    if(maxr[a][b]) return maxr[a][b];
    return maxr[a][b] = max(0, max(go(a+1,b), go(a,b+1))) + 1;
}

int memo[510][510];
int go2(int a, int b) {
    if(memo[a][b] != -1) return memo[a][b];

    int ret = 1;
    if(b+1 < M && data[a][b+1] != '#') {
        ret = max(ret, go2(a,b+1) + 1);
        int aa = a;
        int bb = b+1;
        int mr = maxr[a][bb];
        for(int i=0;;i++) {
            if(bb+1 < M && data[aa][bb+1] != '#') {
                mr = max(mr, maxr[aa][bb+1] + i + 2);
            }
            if(aa == 0 || data[aa-1][bb] == '#') {
                break;
            }
            aa--;
        }
        ret = max(ret, mr);
    }

    if(a+1 < N && data[a+1][b] != '#') {
        ret = max(ret, go2(a+1,b) + 1);
        int aa = a+1;
        int bb = b;
        int mr = maxr[aa][b];
        for(int i=0;;i++) {
            if(aa+1 < N && data[aa+1][bb] != '#') {
                mr = max(mr, maxr[aa+1][bb] + i + 2);
            }
            if(bb == 0 || data[aa][bb-1] == '#') break;
            bb--;
        }
        ret = max(ret, mr);
    }
    cout << a << " " << b << " = " << ret << endl;
    return memo[a][b] = ret;
}

// do time-consuming job here
void solve(int dataId)
{
    memset(maxr, 0, sizeof(maxr));
    memset(memo, -1, sizeof(memo));
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            go(i, j);
            cout << maxr[i][j] << " ";
        }
        cout << endl;
    }

    printf("Case #%d: %d\n", dataId, go2(0, 0));
}

// do data input here. don't use stdin methods in solve function.
void process(int dataId)
{
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) {
        scanf(" %s", data[i]);
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
        close(pipefd[1]); // close write end, i'll only read
        outfds[dataId] = mp(pid, pipefd[0]);
    }
    else
    {
        if(close(pipefd[0]) == -1) perror("close");
        if(dup2(pipefd[1], 1) == -1) perror("dup2");
        if(close(pipefd[1]) == -1) perror("close");
        solve(dataId);
        // fprintf(stderr, "%d\n", dataId);
        exit(0); // force exit
    }
}


