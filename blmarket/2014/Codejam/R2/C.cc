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
PII back[105][505];
bool used[105][505];
bool visit[105][505];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool try_flow(int x, int y) {
    cout << x << "," << y << endl;
    if(x == -1 || y == -1) return false;
    if(y == H-1 && used[x][y] == false) {
        used[x][y] = true;
        return true;
    }
    if(visit[x][y]) return false;
    visit[x][y] = true;

    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;

        int px, py;
        tie(px, py) = back[nx][ny];
        if(!used[nx][ny] || try_flow(px, py)) {
            used[nx][ny] = true;
            back[nx][ny] = mp(x, y);
            cout << " <- " << x << " " << y << " ";
            return true;
        }
    }
    return false;
}

void solve(int dataId)
{
    printf("Case #%d: ", dataId);
    int ret = 0;
    for(int i=0;i<W;i++) {
        back[i][0] = mp(-1, -1);
        memset(visit, 0, sizeof(visit));
        if(try_flow(i, 0)) ret++;
        cout << endl;
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
                back[j][k] = mp(-1, -1);
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


