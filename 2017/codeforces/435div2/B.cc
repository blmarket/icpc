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

bool flag[100005];
vector<int> links[100005];
int nt[2];

void go(int a, int p) {
  for(auto it: links[a]) {
    if(it == p) continue;
    flag[it] = !flag[a];
    nt[flag[it]]++;
    go(it, a);
  }
}

int main(void) {
  int n;
  scanf(" %d", &n);
  for(int i=0;i<n-1;i++) {
    int a,b;
    scanf(" %d %d", &a, &b);
    links[a].pb(b);
    links[b].pb(a);
  }

  nt[0]++;
  go(1, -1);

  long long ret = 0;
  for(int i=1;i<=n;i++) {
    int oth = nt[!flag[i]] - links[i].size();
    ret += oth;
  }
  cout << ret/2 << endl;
  return 0;
}
