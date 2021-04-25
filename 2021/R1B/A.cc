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
  for(int i=0;i<3600;i++) {
  }

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

  // cerr << h << " " << m << " " << s << " = " << d << endl;

  if (((h-d) * 12) % ROUND == (m-d)%ROUND && ((h-d) * 720) % ROUND == (s-d)%ROUND) {
    return h-d;
  }
  if (((h+d) * 12) % ROUND == (m+d)%ROUND && ((h+d) * 720) % ROUND == (s+d)%ROUND) {
    return h+d;
  }
  return -1;
}

bool check(long long h, long long m, long long s) {
  for(int j=0;j<12;j++) {
    for(int i=0;i<3600;i++) {
      int mm = (i / 60);
      int ss = (i % 60);

      long long h2 = h - i * NANO - j * HOUR_TICK;
      long long m2 = m - i * NANO * 12;
      long long s2 = s - i * NANO * 720;

      long long d = h2 * 12 - m2;
      for(int i=0;i<11;i++) {
        if ((d%11) == 0) {
          d /= 11;
          break;
        } else {
          d += NANO;
        }
      }

      h2 = (((h2-d) % ROUND) + ROUND) % ROUND;
      m2 = (((m2-d) % ROUND) + ROUND) % ROUND;
      s2 = (((s2-d) % ROUND) + ROUND) % ROUND;

      if((h2*12) % ROUND == m2 && (h2*720) == s2 % ROUND) {
        cout << j << " " << mm << " " << ss << " " << ((-d % NANO) + NANO) % NANO << endl;
        return true;
      }
    }
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
