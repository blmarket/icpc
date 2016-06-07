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

int N, D;
vector<int> S, M;
vector<int> childs[1000005];

void get(vector<int> &V) {
  int S,A,C,R;
  V.clear();
  scanf(" %d %d %d %d", &S, &A, &C, &R);
  V.pb(S);
  while(V.size() < N) {
    LL b = V.back();
    b = (b * A + C) % R;
    V.pb(b);
  }
}

LL debug = 0;
int ret[3000000];
int lleft;

void add(int left, int right, int i=1, int l1 =0, int r1 = 1048576) {
  if(right <= l1 || r1 <= left) return;
  if(left <= l1 && right >= r1) {
    ret[i] += 1;
    return;
  }
  int mid = (l1 + r1) / 2;
  add(left, right, i*2, l1, mid);
  add(left, right, i*2+1, mid, r1);
}

void go(int a, int left, int right) {
  cerr << ++debug << endl;
  if(left > right) return;

  add(left - S[0] + D, right - S[0] + D + 1);

  for(int i=left;i<=right;i++) ret[i - S[0] + D]++;
  vector<int> &cs = childs[a];
  for(int i=0;i<size(cs);i++) {
    int ci = cs[i];

    int nl = max(left, S[ci] - D);
    int nr = min(right, S[ci]);

    go(ci, nl, nr);
  }
}

void process(void) {
  scanf(" %d %d", &N, &D);
  for(int i=0;i<N;i++) {
    childs[i].clear();
  }
  get(S);
  get(M);
  for(int i=1;i<N;i++) {
    M[i] = (M[i] % i);
    childs[M[i]].pb(i);
  }

  lleft = S[0] - D;
  go(0, S[0]-D, S[0]);
  int maxx = 0;
  for(int i=0;i<=D;i++) {
    maxx = max(maxx, ret[i]);
  }
  cout << maxx << endl;
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    cerr << i << endl;
    printf("Case #%d: ",i);
    process();
  }
  return 0;
}
