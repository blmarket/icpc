#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, Q;

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
  sort(V.begin(), V.end());
  cout << V[N-1].second << " " << V[N-1].first << "/1" << endl;
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
