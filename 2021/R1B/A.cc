#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

const long long NANO = 1e9;
const long long HOUR_TICK = 60LL * 60 * NANO;
const long long ROUND = HOUR_TICK * 12;

long long inp[3];

long long check2(long long h, long long m, long long s) {
  cout << h << " " << m << " " << s << endl;
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
  m = ((m % ROUND) + ROUND) % ROUND;
  s = ((s % ROUND) + ROUND) % ROUND;

  long long d = h * 12 - m;
  for(int i=0;i<11;i++) {
    if ((d%11) == 0) {
      d /= 11;
      break;
    } else {
      d += ROUND;
    }
  }

  if (((h+d) * 12) % ROUND == (m+d) && ((h+d) * 720) % ROUND == (s+d)) {
    cout << h+d << endl;
    return h+d;
  }
  return -1;
}

bool check(long long h, long long m, long long s) {
  for(int i=0;i<12;i++) {
    long long ht = h - HOUR_TICK * i;
    long long tmp = check2(ht, m, s);
    if (tmp != -1) {
      cout << i << " " << (tmp / NANO / 60) << " " << (tmp / NANO) % 60 << " " << tmp % NANO;
      return true;
    }
  }
  return false;
}

void process() {
  scanf(" %lld %lld %lld", &inp[0], &inp[1], &inp[2]);
  if (check(inp[2], inp[1], inp[0])) return;
  if (check(inp[0], inp[1], inp[2])) return;
  if (check(inp[0], inp[2], inp[1])) return;
  if (check(inp[1], inp[0], inp[2])) return;
  if (check(inp[1], inp[2], inp[0])) return;
  if (check(inp[2], inp[0], inp[1])) return;
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
