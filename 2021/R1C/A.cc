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
  int now = 1;
  for(auto &it: V) {
    if (now > it) continue;
    R.push_back(it - now);
    now = it + 1;
  }
  R.push_back(K + 1 - now);

  int cur = R[0] + R.back();
  for(int i=1;i+1<R.size();i++) {
    int tmp = max(R[0], R.back()) + (R[i]+1)/2;
    if(cur < tmp) cur = tmp;
    tmp = R[i];
    if(cur < tmp) cur = tmp;
    for(int j=i+1;j+1<R.size();j++) {
      tmp = (R[i]+1)/2 + (R[j]+1)/2;
      if(cur < tmp) cur = tmp;
    }
  }

  printf("%.12lf\n", (double)cur / K);
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
