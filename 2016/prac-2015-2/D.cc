#include <iostream>
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

int r,c;
int data[10][10];

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int check(int a, int b) {
  int cnt = 0;
  if(a) cnt += data[a][b] == data[a-1][b];
  if(a+1 < r) cnt += data[a][b] == data[a+1][b];
  cnt += data[a][(b+c-1)%c] == data[a][b];
  cnt += data[a][(b+1)%c] == data[a][b];
  return cnt;
}

void go(int a, int b) {
  if(a == r) {
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
      if(check(i, j) == data[i][j]) {
        return;
      }
    }
    for(int i=0;i<r;i++) {
      for(int j=0;j<c;j++) cout << data[i][j] << " ";
      cout << endl;
    }
    cout << endl;
    return;
  }
  if(b == c) {
    go(a+1, 0);
    return;
  }

  if(a) {
  }

  for(int i=1;i<=3;i++) {
    data[a][b] = i;
    go(a,b+1);
  }
}

void process() {
  scanf(" %d %d", &r, &c);
  go(0, 0);
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
