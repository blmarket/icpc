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

void visit(int cut, int a, set<int> &res) {
    if(res.count(a)) return;
    res.insert(a);

    for(int i=0;i<N;i++) if(i != a) {
        if(R[a][i] > cut) {
            visit(cut, i, res);
        }
    }
}

LL go(int cut) {
    set<int> S[1120];
    for(int i=0;i<N;i++) S[i].clear();

    for(int i=0;i<N;i++) {
        visit(cut, i, S[i]);
    }

    vector<int> cnts;
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

        cerr << i << " : ";
        foreach(it, S[i]) {
            cerr << *it << " ";
        }
        cerr << endl;
    }

    if(size(cnts) < K) return -1;
    sort(cnts.begin(), cnts.end());
    LL ret = cut;
    for(int i=0;i<K;i++) {
        ret += (LL)cnts[i] * C;
    }

    cerr << cut << " = " << ret << endl;

    return ret;
}

void process(void) {
    input();

    cout << "input done" << endl;

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    LL ret = -1;
    for(int i=0;i<size(values);i++) {
        LL tmp = go(values[i]);
        cout << values[i] << " = " << tmp << endl;
        if(ret == -1 || ret > tmp) ret = tmp;
        if(tmp > ret) break;
    }
    cout << ret << endl;
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
