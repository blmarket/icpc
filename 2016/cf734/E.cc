#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int n;
int c[200005];
int r[200005];

int root(int a) {
    return r[a] == a ? a : (r[a] = root(r[a]));
}

int main(void) {
    scanf(" %d", &n);
    for(int i=1;i<=n;i++) scanf(" %d", &c[i]);
    for(int i=1;i<=n;i++) r[i] = i;
    for(int i=1;i<n;i++) {
        int a,b;
        scanf(" %d %d", &a, &b);
        if(c[a] == c[b]) {
            r[root(a)] = root(b);
        }
    }

    for(int i=1;i<=n;i++) cout << r[root(i)] << " " ;
    cout << endl;
    return 0;
}
