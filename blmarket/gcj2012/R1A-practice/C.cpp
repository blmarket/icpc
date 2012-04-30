#include <iostream>
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

#ifndef MULTI
#define MULTI 1
#endif

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

struct frac {
    frac(int a,int b, bool f, int c, int d)
    {
        up = a;
        down = b;
        flag = f;
        pa = c;
        pb = d;
    }

    int up, down;
    bool flag;
    int pa, pb;

    bool operator<(const frac &rhs) const
    {
        return (long long)up * rhs.down < (long long)down * rhs.up;
    }
};

ostream& operator<<(ostream& ost, const frac &rhs)
{
    return ost << (double)rhs.up / rhs.down << " : " << rhs.flag << " " << rhs.pa << "-" << rhs.pb;
}

int n;
int spd[55], pos[55];
vector<int> links[55];

vector<frac> meet;

void addcol(int a,int b) // faster, slower
{
    int dspd = spd[a] - spd[b];
    if(pos[a] <= pos[b] - 5)
    {
        int dist = pos[b]-5-pos[a];
        meet.pb(frac(dist, dspd, false, a ,b));
    }
    if(pos[a] < pos[b] + 5)
    {
        int dist = pos[b] + 5 - pos[a];
        meet.pb(frac(dist, dspd, true, a ,b));
    }
}

void solve(int dataId)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++) 
        {
            if(abs(pos[i] - pos[j]) < 5) // already overlapping
            {
                links[i].pb(j);
                links[j].pb(i);
            }
            if(spd[i] != spd[j])
            {
                if(spd[i] > spd[j]) addcol(i,j);
                else addcol(j,i);
            }
        }
    }
    
    sort(meet.begin(), meet.end());
    for(int i=0;i<size(meet);i++)
    {
        cout << meet[i] << endl;
    }
}

void process(int dataId)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char a;
        int b,c;
        scanf(" %c %d %d",&a,&b,&c);
        spd[i] = b;
        pos[i] = c;
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


