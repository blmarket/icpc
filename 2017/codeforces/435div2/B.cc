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
int deg[100005];
PII edges[100005];

int main(void) {
  int n;
  scanf(" %d", &n);
  for(int i=0;i<n-1;i++) {
    int a,b;
    scanf(" %d %d", &a, &b);
    if(a>b) swap(a,b);
    edges[i] = mp(a,b);
  }
  sort(edges, edges + n - 1);
  for(int i=0;i<n-1;i++) {
    int a,b;
    tie(a,b) = edges[i];
    cerr << a << " " << b << endl;
    if(flag[a] == flag[b]) flag[b] = !flag[a];
    deg[a]++;
    deg[b]++;
  }

  int nt[2] = {0,0};
  for(int i=1;i<=n;i++) {
    cerr << flag[i] << " ";
    nt[flag[i]]++;
  }
  cerr << endl;

  long long ret = 0;
  for(int i=1;i<=n;i++) {
    cerr << i << " " << flag[i] << " " << deg[i] << " " << nt[!flag[i]] - deg[i] << endl;
    int oth = nt[!flag[i]] - deg[i];
    ret += oth;
  }
  cout << ret/2 << endl;
  return 0;
}
