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

template<typename T> int size(const T &a) { return a.size(); } 

VI childs[50005];
int idx[50005];
int last[50005];

bool flag[50005];
int n,q;

void process(void) {
    scanf("%d %d", &n, &q);
    for(int i=1;i<=n;i++) childs[i].clear();

    for(int i=0;i<n-2;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        childs[a].pb(b);
    }

    childs[1].pb(2);
    auto build_prefix = [&]() {
        int tmp = 0;
        function<void(int)> go = [&](int pos) {
            idx[pos] = tmp++;
            for(int c : childs[pos]) {
                go(c);
            }
            last[pos] = tmp;
        };
        go(1);
    };
    build_prefix();

    for(int i=1;i<=n;i++) {
        cout << i << " : " << idx[i] << " " << last[i] << endl;
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
}
