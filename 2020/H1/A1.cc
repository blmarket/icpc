#include <iostream>
#include <functional>
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

int N, K, W;
LL L[1000005];
LL H[1000005];

void read_data(LL L[]) {
  for(int i=1;i<=K;i++) {
    scanf(" %d", &L[i]);
  }
  long long a,b,c,d;
  scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
  for(int i=K+1;i<=N;i++) {
    L[i] = (a * L[i-2] + b * L[i-1] + c) % d;
  }
}

void process() {
  scanf(" %d %d %d", &N, &K, &W);
  read_data(L);
  read_data(H);
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
