#include <sys/wait.h>
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
typedef pair<LL, LL> PLL;

template<typename T> int size(const T &a) { return a.size(); } 

int R,C;
int H[55][55];
int HH[55][55];
int ret = 0;

const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};

void chk(int a, int b) {
  int minn = 5000;
  for(int i=0;i<4;i++) {
    minn = min(minn, H[a+dx[i]][b+dy[i]]);
  }
  if (minn < HH[a][b]) {
    minn = HH[a][b];
  }
  H[a][b] = minn;
}

void solve(int dataId)
{
  R--;
  C--;
  for(int i=1;i<R;i++) for(int j=1;j<C;j++) H[i][j] = 5005;
  for(int a=0;a<5000;a++) {
    for(int i=1;i<R;i++) {
      for(int j=1;j<C;j++) {
        chk(i, j);
      }
    }
  }

  ret = 0;
  for(int i=1;i<R;i++) {
    for(int j=1;j<C;j++) {
      ret += H[i][j] - HH[i][j];
    }
  }

  printf("Case #%d: %d\n", dataId, ret);
}

void process(int dataId)
{
  scanf(" %d %d", &R, &C);
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      scanf(" %d", &H[i][j]);
      HH[i][j] = H[i][j];
    }
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
        fflush(stdin);
        // solver._solve(i);
        solve(i);
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


