#include <iostream>
#include <algorithm>
#include <vector>

#define PII pair<int, int>
#define pb emplace_back
#define mp make_pair

using namespace std;

vector<PII> output;
int dp[105][105];

void process() {
  int r,c;
  scanf(" %d %d", &r, &c);
  while(r>0 && c>0) {
    if(r == c) {
      output.pb(make_pair(r-1,c-1));
      r--;c--;
      continue;
    }
    if(r > c + 1) {
      output.pb(make_pair(r-1, 0));
      r -= 2;
      continue;
    }
    if(c > r + 1) {
      output.pb(make_pair(0, c-1));
      c-=2;
      continue;
    }
    if(r == 1 && c == 2) {
      output.pb(mp(0, 0));
      output.pb(mp(0, 1));
      break;
    }
    if(r == 2 && c == 1) {
      output.pb(mp(0, 0));
      output.pb(mp(1, 0));
      break;
    }
    output.pb(make_pair(r-1,c-1));
    r--;c--;
  }
  printf("%d\n", output.size());
  for(int i=0;i<output.size();i++) {
    printf("%d %d\n", output[i].first, output[i].second);
  }
}

int main() {
  dp[1][1] = 1;
  dp[1][2] = 2;
  dp[2][1] = 2;
  dp[2][2] = 2;
  for(int i=3;i<=100;i++) {
    for(int j=3;j<=100;j++) {
    }
  }
  int t;
  scanf(" %d", &t);
  for(int i=0;i<t;i++) {
    process();
  }
}
