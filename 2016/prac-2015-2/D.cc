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

int r,c;
int data[10][10];

int ret;

int get(int a, int b) {
    if(a<0 || b<0 || a>=r || b>=c) return -1;
    return data[a][b];
}

bool good(int a, int b) {
    if(a<0 || b<0 || a>=r || b>=c) return true;
    int cnt = 0;
    for(int i=0;i<4;i++) {
        if(get(a+dx[i], b+dy[i]) == data[a][b]) cnt++;
    }
    return cnt == data[a][b];
}

void go(int a, int b) {
    cerr << a << " " << b << endl;
    if(a == r) {
        ret++;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) cout << data[i][j] << " ";
            cout << endl;
        }
        return;
    }
    if(b == c) {
        go(a+1, 0);
        return;
    }

    for(int i=1;i<=3;i++) {
        data[a][b] = i;
        if(!(good(a-1,b) && good(a,b-1))) {
            continue;
        }
        go(a, b+1);
    }
}

void process() {
    ret = 0;
    scanf(" %d %d", &r, &c);
    go(0, 0);
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
