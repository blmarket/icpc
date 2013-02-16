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

    for(int i=1;i<N;i++) {
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

set<int> S[1120];
void visit(int cut, int a) {
    if(S[a].size() != 0) return;
    S[a].insert(a);
    for(int i=0;i<N;i++) if(i != a) {
        if(R[a][i] > cut) {
            S[a].insert(i);
            visit(cut, i);
            foreach(it, S[i]) {
                S[a].insert(*it);
            }
        }
    }
}

LL go(int cut) {
    cerr << "cut = " << cut << endl;
    for(int i=0;i<N;i++) {
        visit(cut, i);
        cerr << i << " : ";
        foreach(it, S[i]) {
            cerr << *it << " ";
        }
        cerr << endl;
    }
    return 0;
}

void process(void) {
    input();

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    cerr << endl;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cerr << R[i][j] << " ";
        }
        cerr << endl;
    }

    LL ret = -1;
    for(int i=0;i<size(values);i++) {
        LL tmp = go(values[i]);
        if(ret == -1 || ret > tmp) ret = tmp;
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
