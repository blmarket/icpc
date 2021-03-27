#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N;
int arr[105];

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) scanf(" %d", &arr[i]);

  int ret = 0;
  for(int i=0;i<N;i++) {
    for(int j=i;j<N;j++) {
      if(arr[j] == i+1) {
        ret += j-i+1;
        reverse(arr + i, arr+j+1);
        break;
      }
    }
  }
  cout << ret << endl;
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
