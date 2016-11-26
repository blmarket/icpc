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

int n;
int v[200005];
int p[200005];
int d[200005];
int c[200005];

int main(void) {
  scanf(" %d", &n);
  for(int i=0;i<n;i++) scanf(" %d", &v[i]);
  for(int i=1;i<n;i++) {
    int a,b;
    scanf(" %d %d", &a, &b);
    p[i] = a-1;
    d[i] = b;
  }

  for(int i=1;i<n;i++) {
    int tmp = i;
    int dd = v[i];
    while(tmp) {
      dd -= d[tmp];
      tmp = p[tmp];
      if(dd < 0) break;
      c[tmp]++;
    }
  }

  for(int i=0;i<n;i++) cout << c[i] << " ";
  cout << endl;

  return 0;
}
