#include <sys/wait.h>
#include <algorithm>
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

template<typename T> int size(const T &a) { return a.size(); } 

vector<string> names;

void solve(int dataId)
{
  int mcnt = -1;
  int mp = -1;
  sort(names.begin(), names.end());
  for(int i=0;i<size(names);i++) {
    string &a = names[i];
    set<char> C;
    C.insert(a.begin(), a.end());
    C.erase(' ');
    for(auto &c : C) {
      if(c < 'A' || c > 'Z') {
        cerr << "invalid character " << (int)c << endl;
      }
    }
    int cnt = C.size();
    // cerr << names[i] << " " << cnt << endl;
    if (mcnt < cnt) {
      mcnt = cnt;
      mp = i;
    }
  }
  printf("Case #%d: %s\n", dataId, names[mp].c_str());
}

void process(int dataId)
{
  int N;
  scanf(" %d", &N);
  names.resize(N);
  char buf[1024];
  buf[0] = 0;
  fgets(buf, 1024, stdin);
  for(int i=0;i<N;i++) {
    fgets(buf, 1024, stdin);
    buf[strlen(buf)-1]=0;
    names[i] = buf;
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
        fprintf(stderr, "##%d\n", dataId);
        exit(0); // force exit
    }
}


