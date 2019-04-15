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
vector<string> words;
int ret = 0;

char chr(const string &w, int pos) {
  if(pos < w.size()) return w[pos];
  return 0;
}

int go(int pos, int s, int e) {
  cerr << pos << " " << s << " " << e << endl;
  if(s+1 >= e) return e-s;
  int ss = s;
  int carry = 0;
  for(int i=s;i<e;i++) {
    if(i>s && chr(words[i-1], pos) != chr(words[i], pos)) {
      carry += go(pos+1, ss, i);
      ss = i;
      continue;
    }

    if(words[i].size() <= pos) {
      carry += go(pos+1, ss, i);
      ss = i + 1;
      continue;
    }
  }
  carry += go(pos+1, ss, e);

  if(!pos) return 0;
  if(carry >= 2) {
    ret++;
    carry -= 2;
    cerr << words[s].substr(0, pos) << endl;
  }
  return carry;
}

void process() {
  scanf(" %d", &n);
  words.clear();
  ret = 0;
  for(int i=0;i<n;i++) {
    char tmp[1024];
    scanf(" %s", tmp);
    int len = strlen(tmp);
    reverse(tmp, tmp + len);
    words.pb(tmp);
  }
  sort(words.begin(), words.end());
  for(auto w: words) {
    cerr << w << " ";
  }
  cerr << endl;
  go(0, 0, n);
  cout << ret << endl;
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
