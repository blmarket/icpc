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

vector<LL> V;
int N, D;

void process() {
  V.clear();
  scanf(" %d %d", &N, &D);
  for(int i=0;i<N;i++) {
    LL tmp;
    scanf(" %lld", &tmp);
    V.pb(tmp);
  }
  sort(V.begin(), V.end());
  int ret = D-1;
  for(int i=0;i+D<N;i++) {
    if(V[i] == V[i+D-1]) {
      cout << 0 << endl;
      return;
    }
  }
  for(int i=0;i<N;i++) {
    if(i+2 < N && V[i] == V[i+1]) {
      cout << 1 << endl;
      return;
    }
    for(int j=i+1;j<N;j++) {
      if(V[j] == V[i]*2) {
        cout << 1 << endl;
        return;
      }
    }
  }
  cout << D-1 << endl;
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
