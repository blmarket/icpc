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
  map<char, int> pos;
  int cnt[4] = {0};
  char str[105];
  scanf(" %s", str);
  int n = strlen(str);
  for(int i=0;i<n;i++) {
    if(str[i] != '!') {
      pos[str[i]] = i % 4;
    } else {
      cnt[i%4] += 1;
    }
  }

  cout << cnt['R'] << " " << cnt['B'] << " " << cnt['Y'] << " " << cnt['G'] << endl;
}
