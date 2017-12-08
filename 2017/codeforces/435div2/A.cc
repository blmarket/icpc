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

bool has[105];

int main(void) {
  int n,x;
  scanf(" %d %d", &n, &x);
  int ret = 0;
  for(int i=0;i<n;i++) {
    int tmp;
    scanf(" %d", &tmp);
    if(tmp == x) ret++;
    has[tmp] = true;
  }
  for(int i=0;i<x;i++) {
    if(!has[i]) ret++;
  }
  cout << ret << endl;
  return 0;
}
