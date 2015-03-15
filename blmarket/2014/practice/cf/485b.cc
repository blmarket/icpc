#include <iostream>
#include <algorithm>
#include <functional>
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

int n;

vector<int> x,y;

int main(void) {
    cin >> n;
    x.resize(n); y.resize(n);
    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long tt = max(x.back() - x[0], y.back() - y[0]);
    cout << tt*tt << endl;
    return 0;
}
