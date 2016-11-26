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

long long n,a,b,c;

int main(void) {
    scanf(" %lld %lld %lld %lld", &n, &a, &b, &c);
    LL mincost = -1;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<4;k++) {
	if((n+i+j*2+k*3) % 4) continue;
	LL tmp = a *i + b*j + c*k;
	if(mincost < 0 || mincost > tmp) mincost = tmp;
    }
    cout << mincost << endl;
}
