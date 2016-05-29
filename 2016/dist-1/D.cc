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

#include "crates.h"

const LL mod = 1e9 + 7;

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes();

    LL N = GetNumStacks();
    LL ls = N * my / nn;
    LL rs = N * (my+1) / nn;

    LL sum = 0;
    for(LL i=ls;i<rs;i++) {
      sum += GetStackHeight(i + 1);
    }
    PutLL(0, sum);
    Send(0);

    if(my == 0) {
      LL total = 0;
      vector<LL> sums;
      for(int i=0;i<nn;i++) {
        Receive(i);
        sums.pb(GetLL(i));
        total += sums.back();
      }
      cerr << "HERE" << endl;
      LL tail = total % N;

      LL left = 0;
      for(int i=0;i<nn;i++) {
        LL ll = N * i / nn;
        LL rr = N * (i+1) / nn;
        LL esti = total / N * (rr - ll) + max(0LL, min(rr, tail) - ll);

        PutLL(i, esti);
        PutLL(i, left);
        PutLL(i, left + sums[i] - esti);
        Send(i);
      }
    }

    Receive(0);
    LL esti = GetLL(0);
    LL left = GetLL(0);
    LL right = GetLL(0);

    LL oneh = esti / (rs-ls);
    LL tail = esti % (rs-ls);
    
    LL moves = 0;
    for(LL i=0;i<rs-ls;i++) {
      LL cur = GetStackHeight(i + ls + 1);
      LL req = oneh + (i < tail);

      moves += 1 + 2 * abs(left + cur - req);
      moves %= mod;
    }

    PutLL(0, moves);
    Send(0);
    if(my == 0) {
      LL total = 0;
      for(int i=0;i<nn;i++) {
        Receive(i);
        total += GetLL(i);
      }
      total %= mod;
      cout << total << endl;
    }

    return 0;
}
