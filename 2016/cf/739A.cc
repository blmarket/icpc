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

int main(void) {
  scanf(" %d %d", &n, &m);
  int minlen = n;
  for(int i=0;i<m;i++) {
    int a,b;
    scanf(" %d %d", &a, &b);
    a = b-a + 1;
    minlen=min(minlen, a);
  }

  cout << minlen << endl;
  for(int i=0;i<n;i++) {
    cout << (i % minlen) << " ";
  }
  cout << endl;
  return 0;
}
