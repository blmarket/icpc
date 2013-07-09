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

long long sol(long long n) {
    long long xs = 0;
    for(int i=1;i<=n;i++) {
        xs ^= i;
    }
    if(xs == 0) {
        return 0;
    }
    if(xs == 1) {
        return n;
    }
    cout << n << " " << xs << endl;
    return 0;
}

int main(void)
{
    long long n;
    // cin >> n;
    for(int i=1;i<=100;i++) {
        sol(i);
    }
    // cout << n*(n+1)/2 << " " << sol() << endl;
    return 0;
}
