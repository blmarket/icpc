#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

string ans[105];

void process() {
  for(int i=0;i<100;i++) {
    char buf[10005];
    scanf(" %s", buf);
    ans[i] = buf;
  }

  pair<int, int> diff[10005];
  for(int i=0;i<10000;i++) {
    int cnt = 0;
    for(int j=0;j<100;j++) if(ans[j][i] == '1') ++cnt;
    diff[i] = {cnt, i};
  }
  sort(diff, diff + 10000);

  for(int i=0;i<10000;i++) {
    cout << ans[99][diff[i].second];
  }
  cout << endl;
}

int main(void) {
    int T;
    scanf(" %d", &T);
    int P;
    scanf(" %d", &P);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
