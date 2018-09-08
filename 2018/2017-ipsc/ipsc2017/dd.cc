#include <iostream>
#include <algorithm>
#include <vector>

#define PII pair<int, int>
#define pb emplace_back
#define mp make_pair

using namespace std;

long long n;

bool chk1(long long v) {
  bool used[10] = {false};
  while(v) {
    if(used[v % 10]) return false;
    used[v % 10] = true;
    v /= 10;
  }
  return true;
}

bool enumerate(long long cur, bool used[10]) {
  if(cur > n) return false;
  cerr << n << " " << cur << " " << n - cur << endl;
  if(chk1(n - cur)) {
    printf("2 %lld %lld\n", n-cur, cur);
    return true;
  }
  for(int i=0;i<10;i++) if(!used[i]) { 
    used[i] = true;
    if(enumerate(cur * 10 + i, used)) return true;
    used[i] = false;
  }
  return false;
}

void process() {
  scanf(" %lld", &n);
  if(chk1(n)) {
    printf("1 %lld\n", n);
  }
  bool used[10] = {false};
  for(int i=1;i<10;i++) {
    used[i] = true;
    if(enumerate(i, used)) {
      return;
    }
    used[i] = false;
  }
  printf("FAIL\n");
}

int main() {
  int t;
  scanf(" %d", &t);
  for(int i=0;i<t;i++) {
    process();
  }
}
