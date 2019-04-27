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
#include <cmath>

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

int N, P;
double range[25010];

void process() {
  scanf(" %d %d", &N, &P);
  range[0] = 0;
  for(int i=1;i<25010;i++) range[i] = -1;
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    if(a > b) swap(a,b);
    P -= a*2 + b*2;

    int r1 = a*2;
    double r2 = 2 * hypot(a, b);

    for(int j=25010;j>=r1;j--) {
      if(range[j - r1] >= 0) range[j] = max(range[j], range[j-r1] + r2);
    }
  }

  for(int i=0;i<250;i++) cerr << i << "," << range[i] << " ";
  cerr << endl;
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
