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

int N, K;

struct tri {
    string tag;
    tri *child[26] = {0};
    int nc = 0;
    int cost[305];
    bool leaf = false;

    tri() {
        memset(cost, -1, sizeof(cost));
        cost[0] = 0;
    }

    void calc() {
        if (leaf) {
            cost[1] = 1;
        }
        for(int i=0;i<26;i++) {
            if(!child[i]) continue;
            child[i]->calc();
            for(int j=min(nc + leaf, K);j>=1;j--) {
                for(int k=0;k<=j;k++) {
                    if(cost[k] < 0 || child[i]->cost[j-k] < 0) continue;
                    int tmp = cost[k] + 2 + child[i]->cost[j-k];
                    if(cost[j] < 0 || cost[j] > tmp) cost[j] = tmp;
                }
            }
        }
        //cout << tag << " ";
        //for(int i=1;i<=K;i++) {
        //    cout << cost[i] << " ";
        //}
        //cout << endl;
    }

    void cleanup() {
        for(int i=0;i<26;i++) if(child[i]) {
            child[i]->cleanup();
            delete child[i];
        }
    }
};

tri *root;

void build(char *cur, tri *tr) {
    if(*cur == 0) {
        tr->leaf = true;
        return;
    }
    tr->nc++;
    int idx = *cur - 'a';
    if(tr->child[idx] == 0) {
        tr->child[idx] = new tri();
        tr->child[idx]->tag = tr->tag + *cur;
    }
    build(cur + 1, tr->child[idx]);
}

void solve(int dataId)
{
    printf("Case #%d: ", dataId);
    root->calc();
    cout << root->cost[K] << endl;
}

void process(int dataId)
{
    scanf(" %d %d", &N, &K);

    root = new tri();

    char tmp[100005];
    for(int i=0;i<N;i++) {
        scanf(" %s", tmp);
        build(tmp, root);
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


