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
int V[100005];
bool visit[100005];

LL dyna[100005];
LL combi[20][20];

int go(int a) {
  if(visit[a]) return 0;
  visit[a] = true;
  return go(V[a]) + 1;
}

LL getH(int a, int b) {
  return combi[a+b-1][b];
}

const LL mod = 1e9 + 9;

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &V[i]);
    V[i]--;
  }
  memset(visit, 0, sizeof(visit));

  LL ret = 1;
  int sz = 0;

  for(int i=0;i<N;i++) {
    if(visit[i] == false) {
      int tmp = go(i);

      ret = (ret * dyna[tmp]) % mod;
      ret = (ret * getH(sz, tmp-1)) % mod;

      sz += tmp-1;
    }
  }
  cout << ret << endl;
}

int main(void) {
  dyna[1] = 1;
  for(int i=2;i<=100000;i++) {
    LL tmp = i;
    tmp *= (i-1);
    tmp /= 2;
    tmp %= mod;
    tmp *= dyna[i-1];
    tmp %= mod;
    dyna[i] = tmp;
  }

  for(int i=0;i<20;i++) {
    combi[i][0] = combi[i][i] = 1;
    for(int j=1;j<i;j++) {
      combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]) % mod;
    }
  }

    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
    return 0;
}
