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
        if(i-A >= 0) S[i-A] += S[i];
        if(i-B >= 0) S[i-B] += S[i];
        S[i] = 0;
      }
      if(S[i] < U[i]) {
        fail=true;
        break;
      }
      if(i-A >= 0) S[i-A] += S[i] - U[i];
      if(i-B >= 0) S[i-B] += S[i] - U[i];
      S[i] = U[i];
    }
    if(!fail) {
      cout << i << endl;
      for(int j=0;j<S.size();j++) {
        cerr << S[j] << " ";
      }
      cerr << endl;
      return;
    }
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
