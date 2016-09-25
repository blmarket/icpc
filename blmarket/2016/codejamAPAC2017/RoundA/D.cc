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

LL M;
int N;
vector<PLL> V[15];
vector<PLL> ret1, ret;

void build(int s, int e, LL cost, LL power) {
  cerr << " " << s << " " << e << " " << cost << " " << power << endl;
  if(s == e) {
    ret.pb(mp(cost, power));
  }
  auto &v = V[s];
  build(s+1, e, cost, power);
  for(int i=0;i<size(v);i++) {
    cost += v[i].first;
    power += v[i].second;
    build(s+1, e, cost, power);
  }
}

void solve(int dataId)
{
  int N2 = N/2;
  ret.clear();
  build(0, N2, 0, 0);
  ret1 = ret;
  build(N2, N, 0, 0);

  cerr << ret.size() << " " << ret1.size() << endl;
}

void read_block(int a) {
  V[a].clear();
  int K, L;
  LL A[15], C[15];
  scanf(" %d %d", &K, &L);
  for(int i=0;i<K;i++) {
    scanf(" %lld", &A[i]);
  }
  for(int i=0;i+1<K;i++) {
    scanf(" %lld", &C[i]);
  }

  for(int i=L+1;i<K;i++) {
    LL cost = C[i-1];
    LL power = A[i] - A[i-1];
    V[a].pb(mp(cost, power));
  }
}

void process(int dataId)
{
  scanf(" %lld %d", &M, &N);
  for(int i=0;i<N;i++) {
    read_block(i);
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


