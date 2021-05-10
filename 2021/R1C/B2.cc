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

long long tgt;

long long conc(long long cur, long long v) {
  long long tmp = v;
  while(tmp) {
    cur *= 10;
    tmp /= 10;
  }
  return cur + v;
}

long long n2() {
  long long s = 1LL;
  long long e = 1000000001LL;

  while(s+1 < e) {
    long long m = (s+e) / 2;
    long long tmp = conc(conc(0LL, m), m+1);
    if (tmp > tgt) {
      e = m;
    } else {
      s = m;
    }
  }
  return conc(conc(0, e), e+1);
}

long long n3() {
  long long ret = MAX;
  for(int i=1;i<1000000;i++) {
    long long tmp = i;
    for(int j=i+1;;j++) {
      tmp = conc(tmp, j);
      if(tmp > tgt) {
        if(ret > tmp) ret = tmp;
        break;
      }
    }
  }
  return ret;
}

void process() {
  scanf(" %lld", &tgt);
  long long t1 = n2();
  long long t2 = n3();
  cout << min(t1, t2) << endl;
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
