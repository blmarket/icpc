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

int N;
char r[2][1005];

void process(void) {
    scanf(" %d", &N);
    scanf(" %s", r[0]);
    scanf(" %s", r[1]);

    r[0][N] = r[1][N] = 'X';
    N++;

    int p[2] = {0,0};
    int ret = 0;
    for(int i=0;i<N;i++) {
        // cout << i << " " << ret << " " << p[0] << " " << p[1] << endl;
        if(r[0][i] == '.' && r[1][i] == '.') {
            if(p[0]>=0) p[0]++;
            if(p[1]>=0) p[1]++;
            continue;
        }
        
        if(r[0][i] == r[1][i]) {
            if(p[0] <= 0 && p[1] <= 0) {
                p[0] = p[1] = 0;
                continue;
            }
            if(p[0] <= 1 || p[1] <= 1) {
                ret++;
                p[0] = p[1] = 0;
                continue;
            }
            ret += 2;
            p[0] = p[1] = 0;
            continue;
        }

        if(r[1][i] == 'X') {
            swap(p[0], p[1]);
        }

        if(p[1] != -1) p[1]++;
        if(p[0] <= 0) { // no guard needed
        } else {
            ret++;
            if(p[0] == 1) {
                p[1] = -1;
            }
        }
        p[0] = 0;

        if(r[1][i] == 'X') {
            swap(p[0], p[1]);
        }
    }
    cout << ret << endl;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
