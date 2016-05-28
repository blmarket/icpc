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

int N;
bool data[10][10];
bool visit[10];
int back[10];

bool try_flow(int s, int mask) {
  if(visit[s]) return false;
  visit[s] = true;
  for(int i=0;i<N;i++) if(data[mask][i] && data[s][i]) {
    if(back[i] == -1 || try_flow(back[i], mask)) {
      back[i] = s;
      return true;
    }
  }
  return false;
}

bool chk() {
  for(int i=0;i<N;i++) {
    int total = 0;
    for(int j=0;j<N;j++) {
      total += data[i][j];
    }
    if(total == 0) return false;
    int cnt = 0;
    memset(back, -1, sizeof(back));
    for(int j=0;j<N;j++) if(j != i) {
      memset(visit, 0, sizeof(visit));
      if (try_flow(j, i)) {
        cnt++;
      }
    }
    // cerr << i << " " << total << " " << cnt << endl;
    if(cnt == total) return false;
  }

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) cout << data[i][j];
    cout << endl;
  }
  
  return true;
}

int go(int a, int b) {
  if(a == N) {
    if(chk()) return 0;
    return -1;
  }
  if(b == N) {
    return go(a+1, 0);
  }
  if(data[a][b] == 1) return go(a,b+1);
  data[a][b] = 1;
  int tmp = go(a,b+1) + 1;
  data[a][b] = 0;
  if(tmp == -1) {
    return -1;
  }
  int tmp2 = go(a, b+1);
  cout << a << " " << b << " " << tmp2 << " " << tmp << endl;
  if(tmp2 == -1 || tmp2 > tmp) tmp2 = tmp;
  return tmp2;
}

void process() {
  scanf(" %d" ,&N);
  char buf[30];
  for(int i=0;i<N;i++) {
    scanf(" %s", buf);
    for(int j=0;j<N;j++) {
      data[i][j] = buf[j] == '1';
    }
  }

  cout << go(0, 0) << endl;
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ",i);
    process();
  }
  return 0;
}
