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

#define MULTI 2

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef tuple<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int N,K;
VI V, V2;
VI primes;

// do time-consuming job here
void solve(int dataId)
{
    int base = 0;
    V2.clear();
    for(int i=0;i<N;i++) {
        int t1 = (V[i] + (K-1)) / K;
        if(t1 == 0) t1 = 1;
        base += t1 * K - V[i];
        if(t1 == 1) continue;
        V2.pb((V[i] + (K-1)) / K);
    }

    function<int(int, int)> calc_price = [&](int now, int prime) -> int {
        return ((now + (prime-1)) / prime * prime) - now;
    };

    int n1 = size(primes);
    int cost[300][300];
    vector<PII> flows[300];

    function<bool(int, int)> get_flow = [&](int a, int b) -> bool {
        for(int i=0;i<size(flows[a]);i++) {
            if(get<0>(flows[a][i]) == b) return get<1>(flows[a][i]);
        }
        return false;
    };

    function<void(int, int, int)> mod_flow = [&](int a, int b, int c) {
        for(int i=0;i<size(flows[a]);i++) {
            if(get<0>(flows[a][i]) == b) {
                get<1>(flows[a][i]) += c;
                return;
            }
        }
        flows[a].pb(mp(b,c));
    };

    memset(cost, 0, sizeof(cost));

    for(int i=0;i<size(V2);i++) {
        for(int j=0;j<size(primes);j++) {
            mod_flow(n1, j, 1);
            cost[n1][j] = calc_price(V2[i], primes[j]);
            cost[j][n1] = -cost[n1][j];
        }
        n1++;
    }
    for(int i=0;i<size(V2);i++) {
        mod_flow(n1, size(primes)+i, 1);
    }
    int src = n1;
    n1++;
    for(int i=0;i<size(primes);i++) {
        mod_flow(i, n1, 1);
    }
    int sink = n1;
    n1++;

    auto try_flow = [&]() -> int {
        VI mincost(n1, 99999);
        VI back(n1, -1);

        queue<int> Q;
        mincost[src] = 0;
        Q.push(src);
        while(!Q.empty()) {
            int pos = Q.front();
            cout << pos << " " << mincost[pos] << " " << size(flows[pos]) << endl;
            Q.pop();
            for(int i=0;i<size(flows[pos]);i++) {
                int a, b;
                tie(a,b) = flows[pos][i];
                if(!b) continue;
                int nc = mincost[pos] + cost[pos][a];
                cout << "nc = "<< nc << " " << mincost[a] << endl;
                if(mincost[a] > nc) {
                    mincost[a] = nc;
                    back[a] = pos;
                    Q.push(pos);
                }
            }
        }
        cout << mincost[sink] << endl;
        return 0;
    };

    for(int i=0;i<size(V2);i++) {
        base += try_flow();
    }
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
        if(size(primes) > 200) break;
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


