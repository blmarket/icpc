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

int main(void) {
    scanf("%d %d", &N, &M);
    V.clear();
    for(int i=0;i<M;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        if(b < a) b += N;
        V.pb(mp(a,b));
    }
    sort(V.begin(), V.end());
    for(int i=0;i<size(V);i++) {
        cout << V[i].first << "," << V[i].second << endl;
        while(i+1 < size(V)) {
            if(V[i+1].second > V[i].second) break;
            V.erase(V.begin() + i+1);
        }
    }

    return 0;
}
