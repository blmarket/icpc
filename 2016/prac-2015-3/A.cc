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
int ret[1000005];

int sa[1000005];
int sl[1000005];
int sr[1000005];
int sp;

int lleft;

void go(int a, int left, int right) {
  for(int i=0;i<1000005;i++) ret[i] = 0;
  sp = 0;
  sa[sp] = a;
  sl[sp] = left;
  sr[sp] = right;
  sp++;

  for(int ii=0;ii<sp;ii++) {
    tie(a, left, right) = make_tuple(sa[ii], sl[ii], sr[ii]);

    cerr << a << " " << left << " " << right << endl;

    if(left >= right) continue;

    ret[left - S[0] + D]++;
    ret[right - S[0] + D]--;

    vector<int> &cs = childs[a];

    for(int i=0;i<size(cs);i++) {
      int ci = cs[i];

      int nl = max(left, S[ci] - D);
      int nr = min(right, S[ci]);

      sa[sp] = ci;
      sl[sp] = nl;
      sr[sp] = nr;
      sp++;
    }
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
  int acc = 0;
  for(int i=0;i<=D;i++) {
    acc += ret[i];
    maxx = max(maxx, acc);
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
