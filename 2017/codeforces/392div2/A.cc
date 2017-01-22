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
  scanf(" %d", &n);
  int v[105];
  int maxx = 0;
  int sum = 0;
  for(int i=0;i<n;i++) {
    scanf(" %d", &v[i]);
    sum += v[i];
    maxx = max(maxx, v[i]);
  }

  cout << maxx * n - sum << endl;
}
