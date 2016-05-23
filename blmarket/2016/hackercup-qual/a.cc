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
int x[10005], y[10005];

void process(void) {
    scanf(" %d", &N);
    for(int i=0;i<N;i++) {
        scanf(" %d %d", &x[i], &y[i]);
    }
    long long ret = 0;
    for(int i=0;i<N;i++) {
        map<int, int> dd;
        dd.clear();
        for(int j=0;j<N;j++) {
            int dist = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
            dd[dist] += 1;
        }
        for(auto &it : dd) {
            ret += (it.second * (it.second-1)) / 2;
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
