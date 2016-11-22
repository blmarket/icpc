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
char str[105];

int main(void) {
  scanf(" %d", &n);
  scanf(" %s", str);

  string ret;

  for(int i=0;i<n;i++) {
    bool first = true;
    while(i+2 < n && str[i] == 'o' && str[i+1] == 'g' && str[i+2] == 'o') {
      if(first) ret += "***";
      i += 2;
      first = false;
    }
    cerr << i << " " << str[i] << endl;
    if(!first) {
      i++;
      continue;
    }
    ret += str[i];
  }
  cout << ret << endl;
  return 0;
}
