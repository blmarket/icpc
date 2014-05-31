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

int W, H, N;
bool used[105][505];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

vector<int> links[150000];
bool visit[150000];
int sink = 149999;

int vnode(int x, int y) {
    return (x * 505 + y) * 2;
}

void xx(int a) {
    int x = (a / 2) / 505;
    int y = (a / 2) % 505;
    cout << x << " " << y << " " << (a%2) << endl;
}

bool try_flow(int a) {
    xx(a);
    if(a == sink) return true;
    if(visit[a]) return false;
    visit[a] = true;

    for(int i=0;i<size(links[a]);i++) {
        int nn = links[a][i];
        if(try_flow(nn)) {
            swap(links[a][i], links[a].back());
            links[a].pop_back();
            links[nn].pb(a);
            return true;
        }
    }
    return false;
}

void solve(int dataId)
{
    printf("Case #%d: ", dataId);

    for(int i=0;i<W;i++) {
        for(int j=0;j<H;j++) if(!used[i][j]) {
            int v1 = vnode(i, j);
            links[v1].pb(v1+1);
            for(int k=0;k<4;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
                links[v1+1].pb(vnode(nx, ny));
            }
        }
    }

    for(int i=0;i<W;i++) {
        cout << vnode(i, H+1)+1 << " ";
        links[vnode(i, H+1)+1].pb(sink);
    }
    cout << endl;

    int ret = 0;
    for(int i=0;i<W;i++) {
        memset(visit, 0, sizeof(visit));
        ret += try_flow(vnode(i, 0));
    }
    cout << ret << endl;
}

void process(int dataId)
{
    cin >> W >> H >> N;
    memset(used, 0, sizeof(used));
    for(int i=0;i<N;i++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        for(int j=x0;j<=x1;j++) {
            for(int k=y0;k<=y1;k++) {
                used[j][k] = true;
            }
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


