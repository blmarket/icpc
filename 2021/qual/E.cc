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
int sc[105][10005];

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
    int it = diff[i].second;
    for(int j=0;j<100;j++) {
      sc[j][i+1] = sc[j][i] + (ans[j][it] == '1');
    }
  }

  vector<pair<int, int>> solved;
  for(int i=0;i<100;i++) {
    solved.push_back({-sc[i][10000], i});
  }
  sort(solved.begin(), solved.end());
  for(int i=0;i<10;i++) {
    cout << solved[i].first << " " << solved[i].second << endl;
  }

  for(int i=0;i<10000;i++) {
    cout << (sc[58][i] > sc[68][i]);
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
