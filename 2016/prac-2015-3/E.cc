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

int N,D;
int v[5005];

void process() {
  scanf(" %d %d", &N, &D);
  for(int i=0;i<N;i++) {
    scanf(" %d", &v[i]);
  }

  LL ret = 0;
  while(D) {
    auto dist = [&](int a) {
      if(a >= D) return v[a] - v[a-D];
      else return v[a] - v[a+D];
    };

    auto add = [&](int a, int b) {
      a -= (b*2);
      while(a < N) {
        for(int i=0;i<b;i++) {
          if(a + i >= 0 && a+i < N) {
            v[a+i] += 1;
          }
        }
        a += b*2;
      }
    };

    for(int i=1;i<=D*2;i++) {
      while(true) {
        int d0 = dist(i-1);
        int d1 = dist(i);

        if(d1 < d0) {
          // cerr << i << " " << d0 << " " << d1 << " " << D << endl;
          ret++;
          add(i, D);
        } else break;
      }
    }
    D /= 2;
  }
  
  for(int i=1;i<N;i++) {
    if(v[i] != v[0]) {
      cout << "CHEATERS!" << endl;
      return;
    }
  }
  cout << ret << endl;
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ",i);
    process();
  }
  return 0;
}
