#include <iostream>
#include <unordered_map>
#include <algorithm>
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
#include <message.h>

#define mp make_pair
#define pb push_back
#define each(it, v) for(auto &it: v)
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

#include "majority.h"

int main(void) {
  int nn = NumberOfNodes() - 1;
  int my = MyNodeId();
  LL N = GetN();

  if (my == nn) {
    vector<LL> cs;
    for(int i=0;i<nn;i++) {
      Receive(i);
      cs.emplace_back(GetLL(i));
      cs.emplace_back(GetLL(i));
    }

    sort(cs.begin(), cs.end());
    cs.erase(unique(cs.begin(), cs.end()), cs.end());
    each(it, cs) {
      if (it == -1) continue;
      for(int i=0;i<nn;i++) {
        PutLL(i, it);
        Send(i);
      }
      LL cnt = 0;
      for(int i=0;i<nn;i++) {
        Receive(i);
        cnt += GetLL(i);
      }
      if(cnt > N / 2) {
        cout << it << endl;
        goto end;
      }
    }
    cout << "NO WINNER" << endl;

end:
    for(int i=0;i<nn;i++) {
      PutLL(i, -1);
      Send(i);
    }
    return 0;
  }

  LL ls = N * my / nn;
  LL rs = N * (my + 1) / nn;

  vector<LL> v;
  for(LL i = ls; i < rs;i++) {
    v.pb(GetVote(i));
  }

  sort(v.begin(), v.end());
  cerr << v.size() << endl;

  LL c1,c2;
  if(size(v) == 0) {
    c1 = c2 = -1;
  } else if(size(v) == 1) {
    c1 = c2 = v[0];
  } else {
    c1 = v[size(v)/2 - 1];
    c2 = v[size(v)/2];
  }

  cerr << c1 << " " << c2 << endl;

  PutLL(nn, c1);
  PutLL(nn, c2);
  Send(nn);

  while(true) {
    Receive(nn);
    LL t1 = GetLL(nn);
    if(t1 == -1) break;
    LL cnt = 0;
    each(it, v) cnt += (it == t1);
    PutLL(nn, cnt);
    Send(nn);
  }
  return 0;
}
