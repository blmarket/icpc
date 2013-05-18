#include <iostream>
#include <cstdio>
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

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const char dd[] = { 'W', 'S', 'E', 'N' };

int move(int a, int x, int y) {
    if(a == 0) return 0;
    int tt = abs(x) + abs(y);
    int maxx = a*(a+1)/2;

    if((tt&1) != (maxx&1) || maxx < tt) return -1;

    for(int i=0;i<4;i++) {
        int nx = x + a * dx[i];
        int ny = y + a * dy[i];
        
        if(move(a-1, nx, ny) != -1) {
            cout << dd[i];
            return i;
        }
    }
}

void process(void) {
    int x,y;
    scanf("%d %d", &x, &y);
    for(int i=1;;i++) {
        cout << i << " : " << move(i,x,y) << endl;
        if(move(i, x, y) != -1) return;
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
