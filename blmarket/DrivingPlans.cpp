#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

vector<PII> links[2005];
bool hasz[2005];
int md1[2005], md2[2005];

map<int, long long> memo;

long long mod = 1000000009;

long long nways(int a) {
    if(memo.count(a)) return memo[a];
    long long ret = 0;

    for(int i=0;i<size(links[a]);i++) {
        int n, d;
        tie(n, d) = links[a][i];
        if(md2[n] + d == md2[a]) {
            ret += nways(n);
            if(ret > mod) ret %= mod;
        }
    }

    return memo[a] = ret;
}

void calcmd(int *mindist, int sp) {
    memset(mindist, -1, sizeof(int) * 2005);
    priority_queue<PII> Q;
    mindist[sp] = 0;
    Q.push(mp(0, sp));
    while(!Q.empty()) {
        int dist, pos;
        tie(dist, pos) = Q.top();
        Q.pop();
        dist = -dist;

        if(mindist[pos] != dist) continue;

        for(int i=0;i<size(links[pos]);i++) {
            int n, d;
            tie(n, d) = links[pos][i];
            int nd = dist + d;
            if(mindist[n] == -1 || mindist[n] > nd) {
                mindist[n] = nd;
                Q.push(mp(-nd, n));
            }
        }
    }
}

class DrivingPlans 
{
public:
    int count(int N, vector <int> A, vector <int> B, vector <int> C) 
    {		
        memset(hasz, 0, sizeof(hasz));
        for(int i=0;i<2005;i++) links[i].clear();

        for(int i=0;i<size(A);i++) {
            if(C[i] == 0) {
                hasz[A[i]] = hasz[B[i]] = true;
            }
            links[A[i]].pb(mp(B[i], C[i]));
            links[B[i]].pb(mp(A[i], C[i]));
        }

        calcmd(md1, 1);
        calcmd(md2, N);

        if(md1[N] == -1) return 0;

        for(int i=1;i<=N;i++) {
            if(md1[i] + md2[i] == md1[N] && hasz[i]) return -1;
        }

        memo.clear();
        memo[N] = 1;
        return nways(1);
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
