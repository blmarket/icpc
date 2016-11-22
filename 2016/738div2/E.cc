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

int n, m;
int ret = 0;
int nz[200005];

int main(void) {
  scanf(" %d %d", &n, &m);
  m--;
  for(int i=0;i<n;i++) {
    int a;
    scanf(" %d", &a);
    if(i == m && a != 0) {
      ret++;
      a = 0;
    }
    if(i != m && a == 0) {
      a = 500000;
    }
    nz[i] = a;
  }
  sort(nz, nz + n);
  for(int i=1;i<n;i++) {
    int diff = nz[i] - nz[i-1] - 1;
    if(diff <= 0) continue;
    if(diff > n - i) diff = n - i;
    ret += diff;
    n -= diff;
  }
  cout << ret << endl;
  return 0;
}
