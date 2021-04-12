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
u128 bin[128][128];
unordered_map<int, unordered_map<int, unordered_map<int, u128>>> D[2];

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

  D[0].clear();
  D[0][0][0][0] = 1;

  for(int i=0;i<8;i++) {
    bool af = i & 4;
    bool bf = i & 2;
    bool cf = i & 1;
    int cur = i%2;
    int nex = 1-cur;
    D[nex].clear();
    for (const auto &at: D[cur]) {
      for (const auto &bt: at.second) {
        for (const auto &ct: bt.second) {
          for(int k=0;k<=n[i];k++) {
            int na = at.first + k * af + (n[i] - k) * !af;
            int nb = bt.first + k * bf + (n[i] - k) * !bf;
            int nc = ct.first + k * cf + (n[i] - k) * !cf;
            D[nex][na][nb][nc] += ct.second * bin[n[i]][k];
          }
        }
      }
    }
  }

  return memo[key] = D[0][tgt[0]][tgt[1]][tgt[2]];
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
  memset(bin, 0, sizeof(bin));
  for(int i=0;i<=120;i++) {
    bin[i][0] = bin[i][i] = 1;
    for(int j=1;j<i;j++) {
      bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
    }
  }

  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ", i);
    process();
  }
  return 0;
}
