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
u128 D[2][128][128][128];

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

map<pair<vector<int>, vector<int>>, u128> memo;

// 998407356219981937709017954393800

u128 count(const vector<int> &n, const vector<int> &tgt) {
  auto key = make_pair(n, tgt);
  if(memo.count(key)) return memo[key];

  memset(D, 0, sizeof(D));
  D[0][0][0][0] = 1;

  int cur = 0, nex = 1;
  for(int i=0;i<8;i++) {
    bool at = i & 4;
    bool bt = i & 2;
    bool ct = i & 1;
    for(int j=0;j<n[i];j++) {
      memset(D[nex], 0, sizeof(D[0]));
      for(int a=0;a<Q;a++) {
        for(int b=0;b<Q;b++) {
          for(int c=0;c<Q;c++) {
            D[nex][a+at][b+bt][c+ct] += D[cur][a][b][c];
            D[nex][a+!at][b+!bt][c+!ct] += D[cur][a][b][c];
          }
        }
      }
      cur = !cur;
      nex = 1-cur;
    }
  }

  return memo[key] = D[cur][tgt[0]][tgt[1]][tgt[2]];
}

void process() {
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
    return;
  }

  vector<int> n(8, 0);
  for(int i=0;i<Q;i++) {
    int at = V[0].second[i] == 'T';
    int bt = V[1].second[i] == 'T';
    int ct = V[2].second[i] == 'T';
    n[at * 4 + bt * 2 + ct] += 1;
  }

  cout << str(count(n, vector<int> { V[0].first, V[1].first, V[2].first })) << endl;

  for(int i=0;i<Q;i++) {
    int at = V[0].second[i] == 'T';
    int bt = V[1].second[i] == 'T';
    int ct = V[2].second[i] == 'T';
    n[at * 4 + bt * 2 + ct] -= 1;
    cout 
      << str(count(n, vector<int> { V[0].first - at, V[1].first - bt, V[2].first - ct })) 
      << " "
      << str(count(n, vector<int> { V[0].first - !at, V[1].first - !bt, V[2].first - !ct })) 
      << endl;
    n[at * 4 + bt * 2 + ct] += 1;
  }
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
