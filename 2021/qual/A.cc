#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, C;
int arr[105];

void process() {
  scanf(" %d %d", &N, &C);
  for(int i=0;i<N;i++) arr[i] = i+1;

  for(int i=N-2;i>=0;i--) {
    int mx = min(N - i, C);
    reverse(arr+i, arr+i+mx);
    C -= mx;
  }

  if(C) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  
  for(int i=0;i<N;i++) cout << arr[i] << " ";
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
