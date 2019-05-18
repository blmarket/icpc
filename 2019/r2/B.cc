#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int ms[21];

void process() {
  int d;
  for(int i=1;i<=100;i++) {
    scanf(" %d", &d);
    if(d == -1) {
      cerr << "wrong" << endl;
      exit(0);
    }
    if(d == 100) {
      printf("20 100\n");
      fflush(stdout);
      break;
    }
    if(d >= 80) {
      printf("%d 0\n", d - 79);
      fflush(stdout);
      int n;
      scanf(" %d", &n);
      for(int j=0;j<n;j++) {
        int tmp;
        scanf(" %d", &tmp);
      }
      cerr << (d-79) << " " << n << endl;
      continue;
    }
    int v = (d % 19) + 1;
    printf("%d %d\n", v, 100 - ((d-1) / 19));
    fflush(stdout);
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
    return 0;
}
