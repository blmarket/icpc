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

#include "oops.h"

#define MASTER_NODE 7
#define DONE -1

int main(void) {
  long long N = GetN();
  long long nn = NumberOfNodes();
  long long my = MyNodeId();

  LL ls = N * my / nn;
  LL rs = N * (my+1) / nn;

  LL minn, maxx;
  minn = maxx = GetNumber(ls);
  for(LL i=ls;i<rs;i++) {
    LL tmp = GetNumber(i);
    minn = min(minn, tmp);
    maxx = max(maxx, tmp);
  }

  PutLL(0, minn);
  PutLL(0, maxx);
  Send(0);

  if(my == 0) {
    for(int i=0;i<nn;i++) {
      Receive(i);
      LL tmp = GetLL(i);
      minn = min(minn, tmp);
      tmp = GetLL(i);
      maxx = max(maxx, tmp);
    }
    cout << maxx - minn << endl;
  }
  return 0;
}
