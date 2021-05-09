#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, K;
vector<int> V;
vector<int> R;

void process() {
  scanf(" %d %d", &N, &K);
  V.resize(N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &V[i]);
  }
  sort(V.begin(), V.end());
  R.clear();
  int cur = 1;
  for(auto &it: V) {
    if (cur > it) continue;
    R.push_back(it - cur);
    cur = it + 1;
  }
  R.push_back(K + 1 - cur);

  for(auto &it: R) {
    cout << it << " ";
  }
  cout << endl;
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
