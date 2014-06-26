#include <iostream>
#include <sys/wait.h>
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
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int n;
vector<vector<string> > opt;
int mincost[30];

void process(int a) {
    memset(mincost, -1, sizeof(mincost));
    mincost[a] = 0;

    while(true) {
        bool again = false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<size(opt[i]);j++) {
                const string &a = opt[i][j];

                int maxx = -1;
                for(int k=0;k<size(a);k++) {
                    int tt = a[k] - 'a';
                    if(mincost[tt] == -1) {
                        maxx = -1;
                        break;
                    }
                    maxx = max(maxx, mincost[tt]);
                }
                // if(i == 2 && j == 0) {
                //     cout << a << " " << maxx << endl;
                // }
                if(maxx == -1) continue;

                maxx += 1;
                if(mincost[i] == -1 || mincost[i] > maxx) {
                    mincost[i] = maxx;
                    again = true;
                }
            }
        }
        if(!again) break;
    }
    for(int i=0;i<n;i++) cout << mincost[i] << " ";
    cout << endl;
}

int main(void) {
    scanf(" %d", &n);
    opt.resize(n);
    for(int i=0;i<n;i++) {
        int m;
        scanf(" %d", &m);
        char tmp[1024];
        for(int j=0;j<m;j++) {
            scanf(" %s", tmp);
            opt[i].pb(tmp);
        }
    }

    for(int i=0;i<n;i++) {
        process(i);
    }

    return 0;
}
