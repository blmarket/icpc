#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, A, B;
vector<int> U;

void process() {
  scanf(" %d %d %d", &N, &A, &B);
  U.resize(N+1);
  for(int i=1;i<=N;i++) {
    scanf(" %d", &U[i]);
  }

  for(int i=N;;i++) {
    vector<int> S = vector<int>(i+1, 0);
    S[i] = 1;
    bool fail = false;
    for(int j=i;j>=0;j--) {
      if(U.size() <= j) {
        if(j-A >= 0) S[j-A] += S[j];
        if(j-B >= 0) S[j-B] += S[j];
        S[j] = 0;
        continue;
      }
      if(S[j] < U[j]) {
        fail=true;
        break;
      }
      if(j-A >= 0) S[j-A] += S[j] - U[j];
      if(j-B >= 0) S[j-B] += S[j] - U[j];
      S[j] = U[j];
    }
    if(fail) continue;
    cout << i << endl;
    for(int j=0;j<U.size();j++) {
      cerr << S[j] << "/" << U[j] << " ";
    }
    cerr << endl;
    return;
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
