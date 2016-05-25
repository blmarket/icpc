#include <iostream>
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

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
const char *dd = "^<>v";

int r,c;
vector<string> v;

bool testmove(int a, int b, int d) {
    while(a>=0 && b>=0 && a<r && b<c) {
        a += dx[d];
        b += dy[d];
        if(v[a][b] != '.') return 0;
    }
}

int chk(int a, int b) {
    int d;
    for(d=0;d<4;d++) if(v[a][b] == dd[d]) break;

    if(testmove(a,b,d)) return 0;

    for(int i=0;i<4;i++) {
        if(testmove(a,b,i)) return 1;
    }
    return -1;
}

void process() {
    scanf(" %d %d", &r, &c);
    char tmp[1024];
    for(int i=0;i<r;i++) {
        scanf(" %s", tmp);
        v.pb(tmp);
    }
    cerr << "HERE" << endl;

    int ret = 0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(v[i][j] != '.') {
                int tmp = chk(i,j);
                if(tmp == -1) {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
                ret += tmp;
            }
        }
    }
    cout << ret << endl;
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
