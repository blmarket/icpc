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
int data[1024];

bool visit[1024];

int go(int s, int p, int a) {
    if(visit[a]) {
        if(s==a || a == p) return 0;
        return -9999;
    }
    visit[a] = true;
    return go(s, a, data[a]) + 1;
}

void process(void) {
    scanf(" %d", &N);
    for(int i=0;i<N;i++) {
        scanf(" %d", &data[i]);
        data[i]--;
    }

    int ret = 0;
    for(int i=0;i<N;i++) {
        memset(visit, 0, sizeof(visit));
        int tmp = go(i, -1, i);
        cerr << i << " " << tmp << endl;
        if(ret < tmp) ret = tmp;
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
