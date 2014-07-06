#include <iostream>
#include <algorithm>
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

int n, m;
int J[100005];
vector<PII> V;

int go(int a) {
    int ret = 0;
    int sum = 0;
    while(sum < n) {
        sum += J[a];
        a = (a + J[a] - 1) % n + 1;
        ret++;
    }
    return ret;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(b < a) b += n;
        V.pb(mp(a,b));
    }
    sort(V.begin(), V.end());
    
    int reach = V[0].second + 1;
    int it = 1;
    for(int i=V[0].first;i <= n;i++) {
        while(V[it].first <= i) {
            reach = max(reach, V[it].second + 1);
            it++;
        }
        J[i] = max(0, reach - i);
    }

    reach -= n;
    for(int i=1;i<=reach;i++) {
        J[i] = max(J[i], reach - i);
    }

    for(int i=1;i<=n;i++) {
        cout << J[i] << " ";
        if(J[i] == 0) {
            cout << "impossible" << endl;
            return 0;
        }
    }

    int ret = go(1+J[1]);
    int fj = J[1];
    for(int i=2;i<fj;i++) {
        if(J[i-1] + i - 1 == J[i] + i) continue;
        int tmp = go(i);
        if(ret > tmp) ret = tmp;
    }
    cout << ret << endl;
    return 0;
}
