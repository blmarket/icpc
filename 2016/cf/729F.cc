#include <iostream>
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

int N;

struct state {
  int L, R;
  int k;
  bool turn;

  LL key() {
    return L + (LL) N * R + (LL) N * N * k + (LL) N*N*N*turn;
  }
};

unordered_map<LL, int> memo;
int v[100005];

int main(void) {
  scanf(" %d", &N);
  return 0;
}
