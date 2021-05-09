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
  for(int i=1;i<cur;i++) {
    long long buf = 0;
    for(int j=i;;j++) {
      int k = j;
      while(k) {
        buf *= 10;
        if (buf > MAX) break;
        k /= 10;
      }
      if (buf > MAX) break;
      buf += j;
      if (buf > cur) {
        if(ret > buf) ret = buf;
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
