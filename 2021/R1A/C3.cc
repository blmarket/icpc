#include <bits/stdc++.h>

using namespace std;
using u128 = __int128_t;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, Q;

string str(u128 v) {
  if(v == 0) {
    return "0";
  }
  string ret;
  while(v) {
    ret += '0' + (v % 10);
    v /= 10;
  }
  reverse(ret.begin(), ret.end());
  return move(ret);
}

void process() {
  cout << "HERE" << endl;
  vector<pair<int, string>> V;
  scanf(" %d %d", &N, &Q);
  char buf[1024];
  for(int i=0;i<N;i++) {
    int tmp;
    scanf(" %s %d", buf, &tmp);
    V.push_back({tmp, buf});
  }

  for(int i=0;i<N;i++) {
    if(V[i].first < Q - V[i].first) {
      V[i].first = Q-V[i].first;
      for(auto &it: V[i].second) {
        if(it == 'T') it = 'F'; else it = 'T';
      }
    }
  }

  if (N < 3) {
    sort(V.begin(), V.end());
    cout << V[N-1].second << " " << V[N-1].first << "/1" << endl;
  }
  cout << "HERE" << endl;

  u128 D[2][128][128][128];
  memset(D, 0, sizeof(D));
  D[0][0][0][0] = 1;
  for(int i=0;i<Q;i++) {
    cout << i << endl;
    int cur = i%2;
    int nex = 1-cur;
    memset(D[nex], 0, sizeof(D[0]));
    for(int a=0;a<=i;a++) {
      bool at = V[0].second[i] == 'T';
      for(int b=0;b<=i;b++) {
        bool bt = V[1].second[i] == 'T';
        for(int c=0;c<=i;c++) {
          bool ct = V[2].second[i] == 'T';
          D[nex][a+at][b+bt][c+ct] += D[cur][a][b][c];
          D[nex][a+!at][b+!bt][c+!ct] += D[cur][a][b][c];
        }
      }
    }
  }
  int cur = Q%2;
  cout << str(D[cur][V[0].first][V[1].first][V[2].first]) << endl;
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        cout << i << endl;
        process();
    }
    return 0;
}
