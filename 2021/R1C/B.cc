#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

const long long MAX = 2000000000000000000LL;

string s;
long long cur;

void process() {
  cin >> s;
  sscanf(s.c_str(), "%lld", &cur);
  long long ret = max(12LL, cur * 2);
  for(long long i = 10;i<cur;i*=10) {
    for(int j=1;j<10;j--) {
      go(i-j);
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
