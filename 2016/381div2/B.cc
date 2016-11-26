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

int n,m;
int v[105];

int main(void) {
  scanf(" %d %d",&n, &m);
  for(int i=0;i<n;i++) scanf(" %d", &v[i]);
  LL ret = 0;
  for(int i=0;i<m;i++) {
    int a,b;
    scanf(" %d %d", &a, &b);
    int tmp = 0;
    for(int j=a;j<=b;j++) {
      tmp += v[j-1];
    }
    if(tmp > 0) ret += tmp;
  }
  cout << ret << endl;
  

  return 0;
}
