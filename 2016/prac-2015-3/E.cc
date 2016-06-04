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
  while(D) {
    for(int i=1;i<=D*2;i++) {
      int d0 = v[i-1] - v[(i+D-1)%N];
      int d1 = v[i] - v[(i+D)%N];
      cerr << i << " " << d0 << " " << d1 << " " << i+D << endl;
    }
    break;
  }
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
