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

  auto create_mid = [&](int left, int right, int target) -> unordered_set<LL> {
    unordered_map<int, unordered_set<LL> > t1, t2;
    int mid = (left + right) / 2;

    auto gen = [&](int a, int b) {
      unordered_map<int, unordered_set<LL> > ret;
      int sz = b-a;
      for(int i=0;i<(1<<sz);i++) {
        LL tmp = 0;
        for(int j=0;j<sz;j++) if((i>>j)&1) {
          tmp += w[j];
        }
        ret[tmp % nn].insert(tmp);
      }
      return ret;
    };
    t1 = gen(left, mid);
    t2 = gen(mid, right);

    unordered_set<LL> ret;

    each(it, t1) {
      auto &tmp = t2[(target - it.first + nn) % nn];
      each(jt, tmp) {
        each(kt, it.second) {
          ret.insert(jt + kt);
        }
      }
    }
    return ret;
  };

  unordered_set<LL> t1 = create_mid(0, N/2, my), t2 = create_mid(N/2, N, (sum - my + nn) % nn);
  if(t1.count(sum) || t2.count(sum)) {
    PutLL(0, 1);
    Send(0);
    return 0;
  }

  each(it, t1) {
    each(jt, t2) {
      if(it + jt == sum) {
        PutLL(0, 1);
        Send(0);
      }
    }
  }

  PutLL(0, 0);
  Send(0);

  if(my == 0) {
    for(int i=0;i<nn;i++) {
      Receive(i);
      if(GetLL(i)) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
