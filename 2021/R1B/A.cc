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

bool check(long long h, long long m, long long s) {
  long long d = h * 12 - m;
  for(int i=0;i<11;i++) {
    if ((d%11) == 0) {
      d /= 11;
      break;
    } else {
      d += ROUND;
    }
  }

  long long h2 = (((h-d) % ROUND) + ROUND) % ROUND;
  long long m2 = ((m2-d) % ROUND) + ROUND;
  long long s2 = ((s2-d) % ROUND) + ROUND;

  if(((h2*12) % ROUND) == (m2 % ROUND) && ((h2*720) % ROUND) == (s2 % ROUND)) {
    long long t1 = h2 % HOUR_TICK;
    long long t2 = t1 % (60 * NANO);
    long long t3 = t2 % NANO;
    cout << h2 / HOUR_TICK << " " << t1 / (60 * NANO) << " " << t2 / NANO << " " << t3 << endl;
    return true;
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
