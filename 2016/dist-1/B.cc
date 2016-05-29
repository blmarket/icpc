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
  long long nodes = NumberOfNodes();
  long long my_id = MyNodeId();
  long long best_so_far = 0LL;
  for (long long i = 0; i < N; ++i) {
    for (long long j = 0; j < N; ++j) {
      if (j % nodes == my_id) {
        long long candidate = GetNumber(i) - GetNumber(j);
        if (candidate > best_so_far) {
          best_so_far = candidate;
          PutLL(MASTER_NODE, candidate);
          Send(MASTER_NODE);
        }
      }
    }
  }
  PutLL(MASTER_NODE, DONE);
  Send(MASTER_NODE);

  if (my_id == MASTER_NODE) {
    long long global_best_so_far = 0;
    for (int node = 0; node < nodes; ++node) {
      long long received_candidate = 0;
      while (true) {
        Receive(node);
        received_candidate = GetLL(node);
        if (received_candidate == DONE) {
          break;
        }
        if (received_candidate > global_best_so_far) {
          global_best_so_far = received_candidate;
        }
      }
    }
    printf("%lld\n", global_best_so_far);
  }
  return 0;
}
