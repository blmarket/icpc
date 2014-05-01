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
typedef vector<long long> VLL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, L;
long long arr1[200], arr2[200];

long long go(VLL &v1, VLL &v2) {
    long long ret = 0;

    for(int i=0;i<L;i++) {
        VLL n1[2], n2[2];
        n1[0].clear(); n1[1].clear();
        n2[0].clear(); n2[1].clear();
        int c1 = 0, c2 = 0;
        for(int j=0;j<v1.size();j++) {
            n1[(v1[j]>>i)&1].pb(v1[j]);
            n2[(v2[j]>>i)&1].pb(v2[j]);
            c1 += (v1[j]>>i)&1;
            c2 += (v2[j]>>i)&1;
        }
        cerr << i << " : " << c1 << " " << c2 << " " << v1.size() << endl;

        if(c1 != c2 && c1 != (v1.size()-c2)) return -1;

        if(c1 == c2) {
            ret = go(n1[0], n2[0]) | go(n1[1], n2[1]) | ret;
        }

        if(c1 == (v1.size() - c2)) {
            long long tmp = go(n1[0], n2[1]) | go(n1[1], n2[0]) | (1LL << i);
            if(tmp == -1) return ret;
            if(ret == -1 || __builtin_popcount(tmp) < __builtin_popcount(ret)) {
                ret = tmp;
            }
        }
        return ret;
    }
    return -1;
}

void solve(int dataId)
{
    printf("Case #%d: ", dataId);
    sort(arr1, arr1+N);
    sort(arr2, arr2+N);

    bool same = true;
    for(int i=0;i<N;i++) {
        if(arr1[i] != arr2[i]) {
            same = false;
            break;
        }
    }
    if(same) {
        printf("0\n");
        return;
    }

    vector<long long> V1(arr1, arr1+N), V2(arr2, arr2+N);
    long long ret = go(V1, V2);
    cout << ret << endl;
    for(int i=0;i<size(V1);i++) {
        cout << (V1[i] ^ ret) << " ";
    }
    cout << " : ";
    for(int i=0;i<size(V2);i++) cout << V2[i] << " ";
    cout << endl;
    if(ret == -1) {
        cout << "NOT POSSIBLE" << endl;
        return;
    }
    cout << __builtin_popcount(ret) << endl;
}

void process(int dataId)
{
    scanf("%d %d", &N, &L);

    auto reads = [&](long long *arr) {
        char tmp[1024];
        for(int i=0;i<N;i++) {
            scanf(" %s", tmp);
            long long tmp2 = 0;
            for(int j=0;j<L;j++) if(tmp[j] == '1') {
                tmp2 |= (1LL<<j);
            }
            arr[i] = tmp2;
        }
    };

    reads(arr1);
    reads(arr2);
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


