#include <iostream>
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

int N, L;
int V[100005];
vector<PII> rem;

void process() {
  scanf(" %d %d", &N, &L);
  rem.clear();
  int sum = 0;
  for(int i=0;i<L;i++) {
    scanf(" %d", &V[i]);
    sum += V[i];
    int tmp = V[i] * 2 % (2 * N);
    if(tmp >= N) {
      rem.pb(mp(N, V[i]));
      continue;
    }
    rem.pb(mp((N - tmp + 1) / 2, V[i]));
  }
  int ret = 0;
  int remain = N - sum;
  sort(rem.begin(), rem.end());
  for(int i=0;i<size(rem);i++) {
    if(remain >= rem[i].first) {
      remain -= rem[i].first;
      rem[i].second += rem[i].first;
    } else {
      rem[i].second += remain;
      remain = 0;
    }
    ret += ((rem[i].second * 200) / N + 1) / 2;
  }
  cout << ret << endl;
}

int main(void) {
  int T;

  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ", i);
    process();
  }
  return 0;
}
