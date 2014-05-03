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

long long A,B,K;

long long memo[2][2][2][40];

long long go(bool lta, bool ltb, bool ltk, int pos) {
    cout << lta << " " << ltb << " " << ltk << " " << pos << endl;
    if(pos == -1) return 1;

    long long &ret = memo[lta][ltb][ltk][pos];
    cout << ret << endl;
    if(ret != -1) return ret;

    int cur = (1 << pos);
    ret = 0;

    // can take 1 from A
    if(lta || (A&cur)) {
        // take 1 from B
        if(ltb || (B & cur)) {
            if(ltk || (K & cur)) {
                ret += go(lta, ltb, ltk, pos - 1);
            }
        }

        ret += go(lta, ltb || (B & cur), ltk || (K & cur), pos - 1);
    }

    if(ltb || (B & cur)) {
        ret += go(lta || (A & cur), ltb, ltk || (K & cur), pos - 1);
    }

    ret += go(lta || (A & cur), ltb || (B & cur), ltk || (K & cur), pos - 1);

    return ret;
}

void solve(int dataId)
{
    memset(memo, -1, sizeof(memo));
    printf("Case #%d: ", dataId);
    cout << go(false, false, false, 1<<30) << endl;
}

void process(int dataId)
{
    cin >> A >> B >> K;
    A--; B--; K--;
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


