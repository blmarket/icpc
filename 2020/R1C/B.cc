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

int U;
vector<pair<LL, string> > V;

void process() {
  scanf(" %d", &U);
  for(int i=0;i<1e4;i++) {
    LL t1;
    char t2[100];
    scanf(" %lld %s", &t1, t2);
    V.pb(mp(t1, t2));
  }

  map<char, int> C[20];
  for(int i=0;i<U;i++) {
    for(int j=0;j<1e4;j++) {
      // cout << V[j].second << endl;
      const string &s = V[j].second;
      if (s.size() <= i) continue;
      // C[i][s[s.size()-1-i]] += 1;
      C[i][s[i]] += 1;
    }
    for(auto &it: C[i]) cout << it.first << " " << it.second << endl;
    cout << endl;
  }

  vector<pair<int, char> > cs;
  for(auto &it: C[0]) {
    cs.pb(mp(it.second, it.first));
  }
  sort(cs.rbegin(), cs.rend());
  for(auto &it: C[1]) {
    if(C[0].find(it.first) == C[0].end()) {
      cout << it.first;
      break;
    }
  }
  for(auto &it: cs) {
    cout << it.second;
  }
  cout << endl;
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
