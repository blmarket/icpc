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
typedef tuple<int, int, int> TI;

struct TI_hash : public unary_function<TI, size_t> {
  size_t operator()(const TI &k) const {
    return hash<int>()(get<0>(k)) ^ hash<int>()(get<1>(k)) ^ hash<int>()(get<2>(k));
  }
};

template<typename T> int size(const T &a) { return a.size(); } 

int n;
int v[4005];
int r[4005];

unordered_map<TI, int, TI_hash> memo;

int go(int a, int b, int c) {
  TI tmp = make_tuple(a,b,c);
  if(memo.count(tmp)) return memo[tmp];
  return memo[tmp] = -1;
}

int main(void) {
  scanf(" %d", &n);
  r[0] = 0;
  for(int i=0;i<n;i++) {
    scanf(" %d", &v[i]);
    r[i+1] = r[i] + v[i];
  }

  cout << go(0, n, 1) << endl;
  return 0;
}
