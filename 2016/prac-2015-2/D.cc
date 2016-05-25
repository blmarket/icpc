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
int total = 0;

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
      if(check(i, j) != data[i][j]) {
        return;
      }
    }
    total ++;
    //for(int i=0;i<r;i++) {
    //  for(int j=0;j<c;j++) cout << data[i][j] << " ";
    //  cout << endl;
    //}
    //cout << endl;
    return;
  }
  if(b == c) {
    go(a+1, 0);
    return;
  }
  
  if(a) {
    data[a][b] = -1;
    int tmp = check(a-1, b);
    if(tmp+1 == data[a-1][b]) {
      data[a][b] = data[a-1][b];
      go(a, b+1);
      return;
    }

    if(tmp == data[a-1][b]) {
      for(int i=1;i<=3;i++) if(i != data[a-1][b]) {
        data[a][b] = i;
        go(a,b+1);
      }
    }
    return;
  }

  for(int i=1;i<=3;i++) {
    data[a][b] = i;
    go(a,b+1);
  }
}

void process() {
  scanf(" %d %d", &r, &c);
  total = 0;
  go(0,0);
  cout << total << endl;

  int gen[10] = {0};
  // except 3.
  // gen[1] = 1; // use only 2.
  if((c%6) == 0) {
    // 222211
    // 211222
    gen[2] += 6;
  }
  if((c%3) == 0) {
    // 221
    // 221
    gen[2] += 3;
  }
  // 2212 
  // 1212
  // 1222
  if((c%4) == 0) {
    gen[3] += 4;
  }

  const LL mod = 1e9 + 7;

  LL dyna[205][4] = {0};
  dyna[100][0] = 1;
  dyna[100][1] = 1;
  for(int i=101;i<=100+r;i++) {
    dyna[i][0] += dyna[i-2][1];
    dyna[i][1] += dyna[i-1][0];

    dyna[i][2] += dyna[i-2][3];
    if((c%6) == 0) {
      dyna[i][3] += (dyna[i-2][0] * 2 + dyna[i-2][2] * 9) % mod;
    } else if((c%3) == 0) {
      dyna[i][3] += (dyna[i-2][0] + dyna[i-2][2] * 3) % mod;
    } else if((c%4) == 0) {
      dyna[i][3] += (dyna[i-3][0] + dyna[i-3][2] * 4) % mod;
    }
  }

  LL ret = dyna[100+r][0] + dyna[100+r][1] + dyna[100+r][2] + dyna[100+r][3];
  ret %= mod;
  cout << ret << endl;
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
