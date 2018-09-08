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

void process() {
  scanf(" %lld", &n);
  if(chk1(n)) {
    printf("1 %lld\n", n);
  }
  printf("2 ? ?\n");
}

int main() {
  int t;
  scanf(" %d", &t);
  for(int i=0;i<t;i++) {
    process();
  }
}
