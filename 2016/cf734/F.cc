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
int d[200005];

int nb[40];

int main(void) {
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d", &b[i]);
    for(int i=0;i<n;i++) scanf(" %d", &c[i]);
    int s = 0;
    for(int i=0;i<n;i++) s = b[i] + c[i];

    if (s%(2*n)) {
        cout << "-1" << endl;
        return 0;
    }
    s /= 2*n;

    for(int i=0;i<n;i++) {
        d[i] = (b[i] + c[i] - s);
        cerr << d[i] << endl;
        if(d[i] % n) {
            cout << "-1" << endl;
            return 0;
        }
        d[i] /= n;

        int tmp = d[i];
        for(int j=0;tmp;j++) {
            nb[j] += (tmp & 1);
            tmp /= 2;
        }
    }

    for(int i=0;i<n;i++) {
        int tmp = d[i];
        int na = 0;
        for(int j=0;tmp;j++) {
            if(tmp & 1) {
                na += (1<<j) * n;
            }
        }

        cerr << na << " " << b[i] << endl;
        if(b[i] != na) {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=0;i<n;i++) cout << d[i] << " ";
    cout << endl;

    return 0;
}
