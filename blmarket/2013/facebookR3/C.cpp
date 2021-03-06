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
#ifndef __cplusplus
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#else
#define foreach(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#endif

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 
template<typename T> void setmin(T &a, const T &b) { if(a>b) a=b; }

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

void tarjan(int N, vector<int> &cnts, const function<bool(int, int)> &chk) 
{
    cnts.clear();
    vector<int> index(N, -1);
    vector<int> lowlink(N, -1);

    int idx = 0;
    vector<int> S;
    
    std::function<bool(int)> sconnect = [&](int a) {
        index[a] = lowlink[a] = idx++;
        S.pb(a);

        bool ret = true;
        for(int i=0;i<N;i++) if(chk(a,i)) {
            if(index[i] == -1) {
                if(sconnect(i)) {
                    ret = false;
                }
                setmin(lowlink[a], lowlink[i]);
            } else {
                bool found = false;
                for(int j=0;j<size(S);j++) if(S[j] == i) {
                    setmin(lowlink[a], index[i]);
                    found = true;
                    break;
                } 
                if(!found) ret = false;
            }
        }

        if(index[a] == lowlink[a]) {
            int cnt = 0;
            while(true) {
                int b = S.back();
                cnt++;
                S.pop_back();
                if(b == a) break;
            }
            if(ret) {
                cnts.pb(cnt);
            }
            return ret;
        }
        return false;
    };

    for(int i=0;i<N;i++) if(index[i] == -1) {
        sconnect(i);
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

    vector<int> cnts;
    tarjan(N, cnts, [&](int a, int b) {
            return (R[a][b] > cut);
            });

    cerr << K << " : ";
    for(int i=0;i<size(cnts);i++) {
        cerr << cnts[i] << " ";
    }
    cerr << endl;

    sort(cnts.begin(), cnts.end());
    if(size(cnts) < K) return size(cnts);

    int tsum = 0;
    LL ret = cut;
    for(int i=0;i<K;i++) {
        ret += (LL)cnts[i] * C;
        tsum += cnts[i];
    }

    if(sol == -1 || sol > ret) sol = ret;

    cerr << cut << " " << size(cnts) << " = " << ret << " " << sol << endl;

    if(tsum == K) {
        return N;
    }

    return size(cnts);
}

void go2(int s, int e, int si, int ei) {
    if(si == ei) return;
    if(s+1 == e) return;
    int m = (s+e)/2;
    int mi = go(values[m]);

    if(mi >= K) {
        go2(s, m, si, mi);
    }
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
