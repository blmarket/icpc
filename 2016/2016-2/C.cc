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

int r,c;
int n;
vector<PII> gates;
vector<pair<PII, PII> > pairs;

int data[20][20];

PII move(int a, int b, int cc) {
  if(a == -1 || b == -1 || a==r || b==c) return mp(a,b);

  switch(data[a][b] * 4 + cc) {
    case 0:
      return move(a, b-1, 1);
    case 1:
      return move(a+1, b, 0);
    case 2:
      return move(a, b+1, 3);
    case 3:
      return move(a-1, b, 2);

    case 4:
      return move(a, b+1, 3);
    case 5:
      return move(a-1, b, 2);
    case 6:
      return move(a, b-1, 1);
    case 7:
      return move(a+1, b, 0);
  }
}

bool chk() {
  for(int i=0;i<size(pairs);i++) {
    PII a = pairs[i].first;
    PII b;
    if(a.first == -1) {
      b = move(0, a.second, 0);
    } else if(a.second == c) {
      b = move(a.first, c-1, 1);
    } else if(a.first == r) {
      b = move(r-1, a.second, 2);
    } else {
      b = move(a.first, 0, 3);
    }
    // cout << a.first << " " << a.second << " - " << b.first << " " << b.second << endl;
    if(b != pairs[i].second) return false;
  }

  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      printf("%c", data[i][j] ? '\\' : '/');
    }
    printf("\n");
  }
  return true;
}

bool go(int a, int b) {
  if(a == r) {
    return chk();
  }
  if(b == c) {
    return go(a+1, 0);
  }
  data[a][b] = 1;
  if(go(a,b+1)) return true;
  data[a][b] = 0;
  return go(a,b+1);
}

void process() {
  scanf(" %d %d", &r, &c);
  n = (r+c)*2;

  gates.clear();
  for(int i=0;i<c;i++) gates.pb(mp(-1, i));
  for(int i=0;i<r;i++) gates.pb(mp(i, c));
  for(int i=c-1;i>=0;i--) gates.pb(mp(r, i));
  for(int i=r-1;i>=0;i--) gates.pb(mp(i, -1));

  pairs.clear();
  for(int i=0;i<n/2;i++) {
    int a,b;
    scanf(" %d %d", &a, &b);
    a--;b--;
    pairs.pb(mp(gates[a], gates[b]));
  }

  go(0, 0);
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d:\n",i);
    process();
  }
  return 0;
}
