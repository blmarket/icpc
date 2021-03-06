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

map<tuple<int, int,int>, int> memo;
int N, P;
int v[4];

int go(const tuple<int, int, int> &s) {
  if(memo.count(s)) return memo[s];
  int a,b,c;
  tie(a,b,c) = s;
  int ret = 0;
  if(a >= 4) {
    int tmp = go(make_tuple(a-4, b, c)) + 1; 
    ret = max(ret, tmp);
  }
  if(c >= 4) {
    int tmp = go(make_tuple(a, b, c-4)) + 1; 
    ret = max(ret, tmp);
  }
  if(b >= 2) {
    int tmp = go(make_tuple(a, b-2, c)) + 1; 
    ret = max(ret, tmp);
  }
  if(a && c) {
    int tmp = go(make_tuple(a-1, b, c-1)) + 1; 
    ret = max(ret, tmp);
  }
  if(b && a >= 2) {
    int tmp = go(make_tuple(a-2, b-1, c)) + 1; 
    ret = max(ret, tmp);
  }
  if(b && c >= 2) {
    int tmp = go(make_tuple(a, b-1, c-2)) + 1; 
    ret = max(ret, tmp);
  }

  if(ret == 0 && (a || b || c)) {
    ret = 1;
  }

  return memo[s] = ret;
}

void process() {
  scanf(" %d %d", &N, &P);
  memset(v, 0, sizeof(v));
  memo.clear();
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
    ret += go(make_tuple(v[1], v[2], v[3]));
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
