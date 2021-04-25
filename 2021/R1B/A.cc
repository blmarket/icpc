#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

const long long HOUR_TICK = 60LL * 60 * 1e9;

long long inp[3];

bool check2(long long h, long long m, long long s) {
  while(h < 0) {
    h += HOUR_TICK;
    m += HOUR_TICK;
    s += HOUR_TICK;
  }
  while(h > HOUR_TICK) {
    h -= HOUR_TICK;
    m -= HOUR_TICK;
    s -= HOUR_TICK;
  }

  if (h * 12 == m && h * 720 == s) return true;
  return false;
}

bool check(long long h, long long m, long long s) {
  for(int i=0;i<12;i++) {
    long long ht = h - HOUR_TICK * i;
    if (check2(ht, m, s)) return true;
  }
  return false;
}

void process() {
  scanf(" %lld %lld %lld", &inp[0], &inp[1], &inp[2]);
  if (check(inp[0], inp[1], inp[2])) return;
  if (check(inp[0], inp[2], inp[1])) return;
  if (check(inp[1], inp[0], inp[2])) return;
  if (check(inp[1], inp[2], inp[0])) return;
  if (check(inp[2], inp[0], inp[1])) return;
  if (check(inp[2], inp[1], inp[0])) return;
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
