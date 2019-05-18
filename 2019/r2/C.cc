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

int N;
vector<PII> V;

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    V.pb(a, b);
  }
  for(int i=0;i<N;i++) {
    for(int j=i+1;j<N;j++) {
      int a = V[j].first - V[i].first;
      int b = V[j].second - V[i].second;
      if(a >= 0 && b >= 0) continue;
      if(a <= 0 && b <= 0) continue;
      cerr << a << " " << b << endl;
    }
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
