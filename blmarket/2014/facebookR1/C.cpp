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

bool r[2][510][510];
const int dx[2][2] = { { 1, 0 }, { -1, 0 } };
const int dy[2][2] = { { 0, 1 }, { 0, -1 } };

void run(int x, int y, int m) {
    r[m][x][y] = true;
    for(int i=0;i<2;i++) {
        int nx = x + dx[m][i];
        int ny = y + dy[m][i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M || data[nx][ny] == '#') continue;
        if(!r[m][nx][ny]) run(nx, ny, m);
    }
}

// do time-consuming job here
void solve(int dataId)
{
    memset(r, 0, sizeof(r));
    run(0, 0, 0);
    run(N-1, M-1, 1);

    int ret = 0;
    for(int i=1;i<N-1;i++) {
        for(int j=0;j<M;j++) if(r[1][i][j]) {
            for(int k=j+1;k<M;k++) {
                if(data[i][k] == '#') break;
                if(r[0][i][k]) ret = max(ret, k-j);
            }
        }
    }

    for(int i=1;i<M-1;i++) {
        for(int j=0;j<N;j++) if(r[1][j][i]) {
            for(int k=j+1;k<N;k++) {
                if(data[k][i] == '#') break;
                if(r[0][k][i]) ret = max(ret, k-j);
            }
        }
    }

    cout << ret << endl;

    printf("Case #%d: %d\n", dataId, N+M-1+ret);
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
        fprintf(stderr, "%d\n", dataId);
        exit(0); // force exit
    }
}


