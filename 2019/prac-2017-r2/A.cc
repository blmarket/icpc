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

int N, P;
int v[4];

void process() {
  scanf(" %d %d", &N, &P);
  memset(v, 0, sizeof(v));
  for(int i=0;i<N;i++) {
    int tmp;
    scanf(" %d", &tmp);
    v[tmp % P]++;
  }
  int ret = v[0];
  if(P == 2) {
    ret += v[1] / 2;
    if(v[1]%2) ret++;
  } else if(P == 3) {
    int t1 = min(v[1], v[2]);
    ret += t1; v[1] -= t1; v[2] -= t1;
    ret += (v[1] / 3) + (v[2] / 3);
    if((v[1]%3) || (v[2]%3)) ret++;
  } else if(P == 4) {
    cerr << v[1] << " " << v[2] << " " << v[3] << endl;
    int t1 = min(v[1], v[3]);
    ret += t1; v[1] -= t1; v[3] -= t1;
    int r1 = v[1] + v[3];
    ret += v[2] / 2; v[2] %= 2;
    if(v[2] && r1 >= 2) {
      ret++; v[2] = 0; r1 -= 2;
    }
    ret += r1 / 3; r1 %= 3;
    if(r1 || v[2]) ret++;
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
