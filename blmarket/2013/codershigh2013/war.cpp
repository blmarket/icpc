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
template<typename T> std::function<T> wrapper(std::function<T> &a) { return a; }

#define SZ 65536

VI childs[50005];
int idx[50005];
int last[50005];
bool colors[SZ*2];
bool final[SZ*2];

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

    final[1] = true;

    function<void(int)> xoxo = [&](int pos) {
        int a = idx[pos], b = last[pos];
        // cout << "flip " << a << " " << b << endl;
        function<void(int,int,int)> go = [&](int pos, int left, int right) {
            if(right <= a || left >= b) return;
            if(final[pos] && left >= a && right <= b) { // in the range.
                colors[pos] = !colors[pos];
                return;
            }

            if(final[pos]) { // it was final.
                final[pos*2] = final[pos*2+1] = true;
                colors[pos*2] = colors[pos*2+1] = colors[pos];
                final[pos] = false;
            }

            go(pos*2, left, (left+right)/2);
            go(pos*2+1, (left+right)/2, right);

            if(final[pos*2] && final[pos*2+1] && colors[pos*2] == colors[pos*2+1]) {
                final[pos] = true;
                colors[pos] = colors[pos*2];
            }
        };

        go(1, 0, SZ);
    };
    xoxo(2);

    function<int(int)> get = [&](int hehe) -> int {
        function<int(int,int,int)> go = [&](int pos, int left, int right) -> int {
            if(final[pos]) {
                // cout << hehe << " -> " << left << " : " << right << " -> " << colors[pos] << endl;
                return colors[pos];
            }
            if(hehe < (left+right)/2) return go(pos*2, left, (left+right)/2);
            return go(pos*2+1, (left+right)/2, right);
        };
        return go(1, 0, SZ);
    };

    for(int i=0;i<q;i++) {
        // for(int i=1;i<SZ*2;i++) {
        //     cout << colors[i] << "(" << final[i] << ") ";
        // }
        // cout << endl;
        char cmd;
        int a,b;
        scanf(" %c %d", &cmd, &a);
        if(cmd == 'T') {
            xoxo(a);
        } else {
            scanf("%d", &b);
            cout << (get(idx[a]) == get(idx[b]) ? "Ally" : "Enemy") << endl;
        }
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
