#include <iostream>
#include <functional>
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
char pat[50][105];
char prefix[10005];
char suffix[105];

bool add1(char *s, char *e) {
  for(int i=0;i<105;i++) {
    if(s == e) return true;
    if(prefix[i] != 0 && prefix[i] != *s) return false;
    prefix[i] = *s;
    s++;
  }
  return false;
}

bool add2(char *s, char *e) {
  for(int i=0;i<105;i++) {
    if(s == e) return true;
    if(suffix[i] != 0 && suffix[i] != *s) return false;
    suffix[i] = *s;
    s--;
  }
  return false;
}

void process() {
  scanf(" %d", &n);
  for(int i=0;i<n;i++) {
    scanf(" %s", pat[i]);
  }
  memset(prefix, 0, sizeof(prefix));
  memset(suffix, 0, sizeof(suffix));
  for(int i=0;i<n;i++) {
    int l = strlen(pat[i]);
    for(int j=0;j<l;j++) {
      if(pat[i][j] == '*') {
        if(!add1(pat[i], pat[i] + j)) {
          cout << "*" << endl;
          return;
        }
        break;
      }
    }
    for(int j=l-1;j>=0;j--) {
      if(pat[i][j] == '*') {
        if(!add2(pat[i] + l - 1, pat[i] + j)) {
          cout << "*" << endl;
          return;
        }
        break;
      }
    }
  }
  reverse(suffix, suffix + strlen(suffix));

  string ret = prefix;

  for(int i=0;i<n;i++) {
    int l = strlen(pat[i]);
    for(int j=0;j<l;j++) if(pat[i][j] != '*') ret += pat[i][j];
  }

  ret += suffix;
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
