#include <iostream>
#include <algorithm>
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

#include "winning_move.h"

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes();

    LL N = GetNumPlayers();
    vector<LL> v;
    for(int i=0;i<N;i++) {
      LL tmp = GetSubmission(i);
      if((tmp % nn) == my) {
        v.pb(tmp);
      }
    }

    cerr << v.size() << endl;

    sort(v.begin(), v.end());
    for(int i=0;i<N;i++) {
      if(i == 0 || v[i] != v[i-1]) {
        if(i+1 >= N || v[i+1] != v[i]) {
          PutLL(0, v[i]);
          Send(0);
          goto end;
        }
      }
    }
    PutLL(0, 0);
    Send(0);
end:
    if(my == 0) {
      LL ret = 0;
      for(int i=0;i<nn;i++) {
        Receive(i);
        LL tmp = GetLL(i);
        if(tmp == 0) continue;
        if(ret == 0 || ret > tmp) ret = tmp;
      }
      cout << ret << endl;
    }

    return 0;
}
