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

map<set<int>, bool> memo;

int types[205];
vector<int> inside[205];
int N;
vector<int> ret;

int keys[205];
bool go(set<int> &cur) {
    if(memo.count(cur)) return memo[cur];

    bool chk = false;
    for(int i=0;i<N;i++) if(cur.count(i) == 0) {
        chk = true;
        if(keys[types[i]]) {
            keys[types[i]]--;
            cur.insert(i);
            for(int j=0;j<size(inside[i]);j++) {
                keys[inside[i][j]]++;
            }
            bool tmp = go(cur);
            if(tmp) {
                ret.pb(i);
                return true;
            }
            for(int j=0;j<size(inside[i]);j++) {
                keys[inside[i][j]]--;
            }
            cur.erase(i);
            keys[types[i]]++;
        }
    }
    if(!chk) return true;
    return false;
}

void process(void) {
    memo.clear();
    int ik;
    scanf("%d %d", &ik, &N);
    memset(keys, 0, sizeof(keys));
    for(int i=0;i<ik;i++) {
        int tmp;
        scanf("%d", &tmp);
        ++keys[tmp];
    }

    for(int i=0;i<N;i++) {
        int tmp;
        scanf("%d %d", &types[i], &tmp);
        inside[i].resize(tmp);
        for(int j=0;j<tmp;j++) {
            scanf("%d", &inside[i][j]);
        }
    }

    set<int> S;
    ret.clear();
    if(go(S)) {
        for(int i=size(ret)-1;i>=0;i--) {
            cout << ret[i]+1 << " ";
        }
        cout << endl;
    } else {
        printf("IMPOSSIBLE\n");
    }
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
