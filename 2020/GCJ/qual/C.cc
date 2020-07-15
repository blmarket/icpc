#include <iostream>
#include <functional>
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

int t, b;
vector<PII> bs[10][2];

int query(int pos) {
  // cerr << pos << endl;
  printf("%d\n", pos);
  fflush(stdout);
  int r1;
  scanf(" %d", &r1);
  // cerr << pos << " " << r1 << endl;
  return r1;
}

bool process() {
  // cerr << "start " << t << " " << b << endl;
  bs[0][0].clear();
  bs[0][1].clear();
  int it = 0;
  for(int j=0;j<10;j++) {
    for(int i=0;i<5;i++) {
      int r1 = query(it+1);
      int r2 = query(b-it);
      bs[j][r1 ^ r2].pb(mp(it + 1, r1));
      it = (it + 1) % (b / 2);
    }
  }
  for(int j=0;j<5;j++) {
    int cnt = 10;
    if(bs[0][0].size() > 0) {
      int r1 = query(bs[0][0][0].first);
      cnt--;
      if(r1 != bs[0][0][0].second) {
        for(auto &it : bs[0][0]) it.second = 1 - it.second;
      }
    }
    if(bs[0][1].size() > 0) {
      int r1 = query(bs[0][1][0].first);
      cnt--;
      if(r1 != bs[0][1][0].second) {
        for(auto &it : bs[0][1]) it.second = 1 - it.second;
      }
    }
    for(int i=1;i<10;i++) {
      if(cnt && bs[i][0].size() > 0) {
        int r1 = query(bs[i][0][0].first);
        cnt--;
        if(r1 != bs[i][0][0].second) {
          for(auto &it : bs[i][0]) {
            it.second = 1 - it.second;
          }
        }
        for(auto &it : bs[i][0]) {
          bs[0][0].pb(it);
        }
        bs[i][0].clear();
      }
      if(cnt && bs[i][1].size() > 0) {
        int r1 = query(bs[i][1][0].first);
        cnt--;
        if(r1 != bs[i][1][0].second) {
          for(auto &it : bs[i][1]) {
            it.second = 1 - it.second;
          }
        }
        for(auto &it : bs[i][1]) {
          bs[0][1].pb(it);
        }
        bs[i][1].clear();
      }
      if(!cnt) break;
    }
    while(cnt--) {
      query(1);
    }
  }
  int ret[105];
  memset(ret, 0, sizeof(ret));
  for(auto &it: bs[0][0]) {
    // cerr << it.first << "=" << it.second << " ";
    ret[it.first] = it.second;
    ret[b + 1 - it.first] = it.second;
  }
  // cerr << endl;
  for(auto &it: bs[0][1]) {
    // cerr << it.first << "X" << it.second << " ";
    ret[it.first] = it.second;
    ret[b + 1 - it.first] = 1 - it.second;
  }
  // cerr << endl;
  for(int i=1;i<=b;i++) {
    cout << ret[i];
  }
  cout << endl;
  char verdict[10];
  scanf(" %s", verdict);
  return verdict[0] == 'Y';
}

int main(void) {
  scanf("%d %d", &t, &b);
  for(int i=0;i<t;i++) {
    if(!process()) break;
  }
  return 0;
}
