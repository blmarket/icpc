#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <message.h>

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

#include "load_balance.h"

int main(void) {
  int my = MyNodeId();
  int nn = NumberOfNodes();

  int N = GetN();

  vector<LL> w;
  LL sum = 0;
  for(int i=0;i<N;i++) {
    w.pb(GetWeight(i));
    sum += w.back();
  }

  if (sum % 2) {
    if (my == 0) {
      cout << "IMPOSSIBLE" << endl;
    }
    return 0;
  }

  sum /= 2;

  auto create_mid = [&](int left, int right, int target) -> unordered_set<LL>&& {
    unordered_set<LL> &&ret;
    return ret;
  };

  unordered_set<LL> t1 = create_mid(0, N/2, my), t2 = create_mid(N/2, N, (sum - my + nn) % nn);

  return 0;
}
