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

int main(void) {
    int n;
    char str[500];
    scanf(" %d", &n);
    scanf(" %s", str);
    str[n++] = 'W';

    vector<int> V;

    int cum = 0;
    for(int i=0;i<n;i++) {
        if(str[i] == 'B') {
            cum++;
        } else {
            if(cum > 0) {
                V.pb(cum);
            }
            cum = 0;
        }
    }
    cout << V.size() << endl;
    for(int i=0;i<V.size();i++) {
        cout << V[i] << " ";
    }
    cout << endl;
    return 0;
}
