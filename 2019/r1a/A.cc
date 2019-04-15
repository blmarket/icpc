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

int r, c;
bool used[25][25];

void enumerate(int a, int b, auto fn) {
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) if(!used[i][j]) {
      if(i == a || j == b) continue;
      if(i+j == a+b || i-j == a-b) continue;
      fn(i, j);
    }
  }
}

void process() {
  scanf(" %d %d", &r, &c);

  for(int trial=0;trial<100;trial++) {
    memset(used, 0, sizeof(used));
    int cx = rand() % r;
    int cy = rand() % c;
    used[cx][cy] = 1;
    enumerate(cx, cy, [&](int x, int y) {
        cerr << cx << " " << cy << endl;
        });
  }
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
