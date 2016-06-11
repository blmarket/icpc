#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, L;
vector<string> G;
string B;

void solve() {
    int maxc = 0;
    int m1 = 0;
    each(it, G) {
        if(it == B) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        char now = '0';
        int cnt = 0;
        int c1 = 0;
        for(int j=0;j<L;j++) {
            if(it[j] == '1') c1++;
            if(now == '0' && it[j] != now) {
                cnt++;
            }
            now = it[j];
        }
        maxc = max(maxc, cnt);
        m1 = max(m1, c1);
    }

    cout << "10?";
    for(int i=0;i<60;i++) cout << "10";

    cout << " " << string(L-1, '?') << endl;
}

void process() {
    scanf(" %d %d", &N, &L);
    char buf[1024];
    for(int i=0;i<N;i++) {
        scanf(" %s", buf);
        G.pb(buf);
    }
    scanf(" %s", buf);
    B = buf;
    solve();
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
