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

int master[50005];
bool flag[50005];
int n,q;

bool goup(int a) {
    if(a == 1 || a == 2) return flag[a];
    return flag[a] ^ goup(master[a]);
}

void process(void) {
    scanf("%d %d", &n, &q);
    for(int i=0;i<n;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        master[b] = a;
    }

    memset(flag, 0, sizeof(flag));
    flag[1] = true;

    for(int i=0;i<q;i++) {
        char cmd;
        int a, b;
        scanf(" %c %d", &cmd, &a);
        if(cmd == 'T') {
            flag[a] = !flag[a];
            continue;
        } else {
            scanf("%d", &b);
            if(goup(a) == goup(b)) {
                cout << "Ally" << endl;
            } else {
                cout << "Enemy" << endl;
            }
        }
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
