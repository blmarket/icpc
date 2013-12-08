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

#define mp make_tuple
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

// set concurrent running childs. set 1 to debug.
#define MULTI 1

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef tuple<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int N,K;
VI V, V2;
VI primes;

vector<int> used;

int go(int pos, int sv, int cut) {
    if(pos == size(V2)) {
        return 0;
    }
    if(sv < V2[pos]) sv = V2[pos];

    cout << pos << " " << sv << endl;

    int ret = cut;
    for(int i=0;i<min(cut, 10);i++, sv++) {
        int tmp = sv;
        bool gogo = true;
        for(int j=0;j<size(primes);j++) {
            if((tmp % primes[j]) == 0 && used[j]) {
                gogo = false;
                break;
            }
            while((tmp % primes[j])) {
                tmp /= primes[j];
            }
        }
        if(!gogo) {
            continue;
        }
        tmp = sv;
        for(int j=0;j<size(primes);j++) {
            if((tmp % primes[j]) == 0) {
                used[j] = 1;
            }
        }
        int chk = go(pos+1, sv + 1, ret) + sv - V2[pos];
        if(ret > chk) ret = chk;

        for(int j=0;j<size(primes);j++) {
            if((tmp % primes[j]) == 0) {
                used[j] = 0;
            }
        }
    }
    cout << pos << " " << sv << " = " << ret << endl;
    return ret;
}

// do time-consuming job here
void solve(int dataId)
{
    int base = 0;
    bool haszero = false;
    V2.clear();
    for(int i=0;i<N;i++) {
        int t1 = (V[i] + (K-1)) / K;
        if(t1 == 0) {
            if(haszero) t1 = 1;
            haszero = true;
        }
        base += t1 * K - V[i];
        if(t1 <= 1) continue;
        V2.pb((V[i] + (K-1)) / K);
    }
    if(size(V2) && haszero) base += K;

    sort(V2.begin(), V2.end());
    for(int i=0;i<size(V2);i++) {
        cerr << V2[i] << " ";
    }
    cerr << endl;

    used = vector<int>(size(primes), 0);
    if(size(V2)) base += go(0, V2[0], 10000) * K;

    printf("Case #%d: %d\n", dataId, base);
}

// do data input here. don't use stdin methods in solve function.
void process(int dataId)
{
    cin >> N >> K;
    V.clear();
    for(int i=0;i<N;i++) {
        int tmp;
        cin >> tmp;
        V.pb(tmp);
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
    primes.pb(2);
    for(int i=3;i<20000;i+=2) {
        bool kk = false;
        for(int j=0;j<size(primes);j++) {
            if((i % primes[j]) == 0) { kk = true; break; }
        }
        if(!kk) primes.pb(i);
        if(size(primes) > 120) break;
    }
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


