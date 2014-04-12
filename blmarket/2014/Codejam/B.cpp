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

int RR, CC, M;
int ret[55][55];

bool go(int R, int C, int free) {
    if(free == 0) return true;

    if(C == 1) {
        if(free == 1) {
            return false;
        }
        for(int i=0;i<free;i++) {
            ret[i][0] = 1;
        }
        ret[0][0] = 2;
        return true;
    } else if(C == 2) {
        if(free % 2 == 1) return false;
        if(free == 2) return false;
        for(int i=0;i<free/2;i++) {
            ret[i][0] = ret[i][1] = 1;
        }
        ret[0][0] = 2;
        return true;
    }
    cout << "FREE = " << free << endl;

    if(free < 4 || free == 5 || free == 7) return false;
    ret[0][0] = ret[0][1] = ret[1][0] = ret[1][1] = 1;
    free -= 4;
    if(free == 0) return true;
    ret[2][0] = ret[2][1] = 1;
    free -= 2;
    if(free == 0) return true;
    ret[0][2] = ret[1][2] = 1;
    free -= 2;
    if(free == 0) return true;
    if(free % 2 == 1) {
        ret[2][2] = 1;
        free--;
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) cout << ret[i][j] << " ";
        cout << endl;
    }
    cout << free << endl;

    for(int i=3;i<R;i++) {
        if(free == 0) return true;
        ret[i][0] = ret[i][1] = 1;
        free -= 2;
    }
    for(int i=3;i<C;i++) {
        if(free == 0) return true;
        ret[0][i] = ret[1][i] = 1;
        free -= 2;
    }
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) cout << ret[i][j] << " ";
        cout << endl;
    }
    cout << free << endl;

    if(free == 0) return true;
    for(int i=2;i<R;i++) {
        for(int j=2;j<C;j++) {
            if(ret[i][j]) {
                ret[i][j] = 1;
                free--;
                if(free == 0) break;
            }
        }
        if(free == 0) break;
    }
    return true;
}

void solve(int dataId)
{
    printf("Case #%d:\n", dataId);
    memset(ret, 0, sizeof(ret));
    if(RR < CC) {
        if(go(CC, RR, RR*CC - M) == false) {
            printf("Impossible\n");
            return;
        }
        ret[0][0] = 2;
        for(int i=0;i<RR;i++) {
            for(int j=0;j<CC;j++) {
                switch(ret[j][i]) {
                    case 0:
                        printf("*");
                        break;
                    case 1:
                        printf(".");
                        break;
                    case 2:
                        printf("c");
                        break;
                }
            }
            printf("\n");
        }
    } else {
        if(go(RR, CC, RR*CC - M) == false) {
            printf("Impossible\n");
            return;
        }
        ret[0][0] = 2;
        for(int i=0;i<RR;i++) {
            for(int j=0;j<CC;j++) {
                switch(ret[i][j]) {
                    case 0:
                        printf("*");
                        break;
                    case 1:
                        printf(".");
                        break;
                    case 2:
                        printf("c");
                        break;
                }
            }
            printf("\n");
        }
    }
}

// read data input.
void process(int dataId)
{
    cin >> RR >> CC >> M;
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


