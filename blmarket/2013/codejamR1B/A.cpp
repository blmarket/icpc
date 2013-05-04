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

int A,N;
int V[105];

int checkit(int a) {
    vector<int> data;
    for(int i=0;i<N;i++) if(i != a) {
        data.pb(V[i]);
    }

    int ret = 0;
    int cur = A;
    for(int i=0;i<size(data);i++) {
        while(cur <= data[i]) {
            cur += (cur - 1);
            ret++;
        }
        cur += data[i];
    }

    return ret;
}

void process(void) {
    scanf("%d %d", &A, &N);
    for(int i=0;i<N;i++) scanf("%d", &V[i]);

    sort(V,V+N);
    int ret = checkit(-1);

    for(int i=0;i<N;i++) {
        int tmp = checkit(i) + 1;
        if(ret > tmp) ret = tmp;
    }
    cout << ret << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        // cerr << i << endl;
    }
}
