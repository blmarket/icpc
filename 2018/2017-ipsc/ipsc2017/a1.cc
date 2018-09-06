#include <iostream>

using namespace std;

void process() {
  int r,c;
  scanf(" %d %d", &r, &c);
  printf("%d\n", r);
  for(int i=0;i<r;i++) {
    printf("%d %d\n", i, i);
  }
}

int main() {
  int t;
  scanf(" %d", &t);
  for(int i=0;i<t;i++) {
    process();
  }
}
