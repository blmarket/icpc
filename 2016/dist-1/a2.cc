#include <message.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cmath>
#include "oops.h"

typedef long long ll;
using namespace std;


void solve() {
  const int id = MyNodeId();
  const int M = NumberOfNodes();
  const int N = GetN();

  const int l = N * id / M;
  const int r = N * (id + 1) / M;

  ll ma = (ll)-1e19;
  ll mi = (ll)1e19;
  for (int i = l; i < r; ++i) {
    ll v = GetNumber(i);
    ma = max(ma, v);
    mi = min(mi, v);
  }

  PutLL(0, ma);
  PutLL(0, mi);
  Send(0);
}

int main() {
  solve();
  if (MyNodeId() == 0) {
    ll ma = (ll)-1e19;
    ll mi = (ll)1e19;
    for (int id = 0; id < NumberOfNodes(); ++id) {
      Receive(id);
      ma = max(ma, GetLL(id));
      mi = min(mi, GetLL(id));
    }
    cout << ma - mi << endl;
  }
}
