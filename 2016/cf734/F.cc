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
int b[200005];
int c[200005];
int s[200005];

int main(void) {
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", &b[i]);
    for(int i=0;i<n;i++) scanf(" %d", &c[i]);
    for(int i=0;i<n;i++) s[i] = b[i] + c[i];

    int minn = s[0];
    for(int i=0;i<n;i++) minn = min(minn, s[i]);

    for(int i=0;i<n;i++) {
        s[i] -= minn;
        if((s[i] % n) != 0) {
            cout << "-1" << endl;
            return 0;
        }
        s[i] /= n;
    }

    for(int i=0;i<n;i++) cout << s[i] << " ";
    cout << endl;

    return 0;
}
