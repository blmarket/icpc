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

#include "rps.h"

unordered_map<int, PII> memo;

PII go(PII a, PII b) {
  if(a.first == b.first) return a;
  if(a.first==0) {
    if(b.first==2) return b;
    return a;
  }
  if(a.first==1) {
    if(b.first==2) return a;
    return b;
  }
  if(a.first==2) {
    if(b.first==0) return a;
    return b;
  }
}

PII dumb(int mask, int sz) {
  PII data[30];
  for(int i=0;i<sz;i++) {
    data[sz+i] = mp((mask % 3), i);
    mask /= 3;
  }
  for(int i=sz*2-1;i>=3;i-=2) {
    data[i/2] = go(data[i], data[i-1]);
  }
  return data[1];
}

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes();
    LL N = GetN();
    LL NN = (1LL<<N);
    if(nn > 8) nn = 8;
    if(NN < 8) nn = 1;
    if(my >= nn) return 0;

    LL ls = NN * my / nn;
    LL rs = NN * (my+1) / nn;
    int sz = rs - ls;

    PII buff[1024768];
    int it = max(1, sz / 8);

    int mask = 0;
    int step = 0;
    for(LL i=ls;i<rs;i++) {
      mask *= 3;
      char move = GetFavoriteMove(i);

      if(move == 'R') mask += 1;
      if(move == 'S') mask += 2;
      step++;

      if(step == 8) {
        PII tmp;
        if (memo.count(mask)) {
          tmp = memo[mask];
        } else {
          tmp = memo[mask] = dumb(mask, step);
        }
        tmp.second = (i - step + tmp.second);
        buff[it++] = tmp;
        step = 0;
        mask = 0;
      }
    }
    if(step) {
      buff[1] = dumb(mask, step);
      buff[1].second = (ls + buff[1].second);
    }

    while(it >= 3) {
      buff[it/2] = go(buff[it], buff[it-1]);
      it -= 2;
    }
    cerr << buff[1].first << " " << buff[1].second << endl;
    PutLL(0, buff[1].first);
    PutLL(0, buff[1].second);
    Send(0);

    if(my == 0) {
      for(int i=0;i<nn;i++) {
        int t1, t2;
        Receive(i);
        t1 = GetLL(i);
        t2 = GetLL(i);
        buff[nn+i] = mp(t1, t2);
      }
      for(int i=nn*2-1;i>=3;i-=2) {
        buff[i/2] = go(buff[i], buff[i-1]);
      }
      cout << buff[1].second << endl;
    }

    return 0;
}
