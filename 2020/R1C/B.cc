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
vector<pair<int, string> > V;

void process() {
  scanf(" %d", &U);
  for(int i=0;i<1e4;i++) {
    int t1;
    char t2[100];
    scanf(" %d %s", &t1, t2);
    V.pb(mp(t1, t2));
  }

  for(int i=0;i<U;i++) {
    map<char, int> C;
    for(int j=0;j<1e4;j++) {
      cout << V[j].second << endl;
      // C[V[j].second[0]] += 1;
    }
    for(auto &it: C) {
      cout << it.first << " " << it.second << endl;
    }
    cout << endl;
  }
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
