#include <iostream>
#include <algorithm>
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

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N,K,C;
int R[1120][1120];
LL f1[1120 * 1120], f2[1120 * 1120];
vector<int> values;

void input(void) {
    int x1,a1,b1,m1;
    int x2,a2,b2,m2;

    scanf("%d %d %d", &N, &K, &C);
    scanf("%d %d %d %d", &x1, &a1, &b1, &m1);
    scanf("%d %d %d %d", &x2, &a2, &b2, &m2);

    f1[0] = x1; f2[0] = x2;

    for(int i=1;i<N*(N+1);i++) {
        f1[i] = (f1[i-1] * a1 + b1) % m1;
        f2[i] = (f2[i-1] * a2 + b2) % m2;
    }

    values.clear();
    values.pb(0);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) if(i != j) {
            if(i > j) R[i][j] = f1[i * (i-1) / 2 + j];
            if(j > i) R[i][j] = f2[j * (j-1) / 2 + i];
            values.pb(R[i][j]);
        }
    }
}

bool chk[1120];
void visit(int cut, int a, set<int> &res) {
    if(chk[a]) return;
    chk[a] = true;
    res.insert(a);

    for(int i=0;i<N;i++) if(i != a && chk[i] == false) {
        if(R[a][i] > cut) {
            visit(cut, i, res);
        }
    }
}

LL sol;

int go(int cut) {
    if(sol != -1 && cut > sol) return N+1;
    set<int> S[1120];
    for(int i=0;i<N;i++) S[i].clear();

    for(int i=0;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(R[i][j] > cut && R[j][i] > cut) {
                S[i] = S[j];
                break;
            }
        }
        if(S[i].size()) continue;
        memset(chk, 0, sizeof(chk));
        visit(cut, i, S[i]);
    }

    vector<int> cnts;
    cnts.clear();
    bool useless[1120];
    memset(useless, 0, sizeof(useless));
    for(int i=0;i<N;i++) {
        if(useless[i]) continue;
        foreach(it, S[i]) {
            if(S[*it].count(i) == 0) {
                useless[i] = true;
                break;
            }
        }
        if(useless[i]) continue;
        cnts.pb(S[i].size());

        foreach(it, S[i]) useless[*it] = true;
    }

    sort(cnts.begin(), cnts.end());
    if(size(cnts) < K) return size(cnts);

    LL ret = cut;
    for(int i=0;i<K;i++) {
        ret += (LL)cnts[i] * C;
    }

    if(sol == -1 || sol > ret) sol = ret;

    cerr << cut << " " << size(cnts) << " = " << ret << " " << sol << endl;

    return size(cnts);
}

void go2(int s, int e, int si, int ei) {
    if(si == ei) return;
    if(s+1 == e) return;
    int m = (s+e)/2;
    int mi = go(values[m]);

    go2(s, m, si, mi);
    go2(m, e, mi, ei);
}

void process(void) {
    input();
    sol = -1;

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    int s = 0; int e = size(values) - 1;
    int si = go(values[s]); int ei = go(values[e]);
    go2(s, e, si, ei);
    cout << sol << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}
