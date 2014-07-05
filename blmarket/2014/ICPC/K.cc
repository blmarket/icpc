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

int N, M;
vector<PII> V;
vector<int> J;

int main(void) {
    scanf("%d %d", &N, &M);
    V.clear();
    for(int i=0;i<M;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        V.pb(mp(a,b));
    }
    sort(V.begin(), V.end());

    for(int i=0;i<size(V);i++) {
        int tmp = upper_bound(V.begin(), V.end(), mp(V[i].second+1, N+1)) - V.begin() - 1;
        cout << V[i].first << "," << V[i].second << " = " << tmp << endl;
        if(tmp == -1) {
            J[i] = 0;
            continue;
        }

        if(V[i].second < V[i].first) {
            J[i] = tmp + N - i;
        } else {
            J[i] = tmp - i;
        }
        cout << i << " " << J[i] << endl;
    }
    return 0;
}
