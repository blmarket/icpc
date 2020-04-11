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

set<int> rows[100005], cols[100005];
int r, c;
VVI board;

LL sum = 0;

bool iter() {
  VVI b2(r, VI(c, 0));
  VVI b3(r, VI(c, 0));
  for(int i=0;i<r;i++) {
    if(rows[i].size() <= 1) continue;
    auto it = rows[i].begin();
    auto jt = it;
    ++it;
    for(;it != rows[i].end();++it) {
      b3[i][*it]++;
      b2[i][*it] += board[i][*jt];
      b3[i][*jt]++;
      b2[i][*jt] += board[i][*it];
      jt = it;
    }
  }

  for(int i=0;i<c;i++) {
    if(cols[i].size() <= 1) continue;
    auto it = cols[i].begin();
    auto jt = it;
    ++it;
    for(;it != cols[i].end();++it) {
      b3[*it][i]++;
      b2[*it][i] += board[*jt][i];
      b3[*jt][i]++;
      b2[*jt][i] += board[*it][i];
      jt = it;
    }
  }

  bool ret = false;
  for(int i=0;i<r;i++) {
    auto it = rows[i].begin();
    while(it != rows[i].end()) {
      sum += board[i][*it];
      cerr << i << " " << *it << " " << board[i][*it] << " " << b3[i][*it] << " " << b2[i][*it];
      if(board[i][*it] * b3[i][*it] < b2[i][*it]) {
        cerr << " X" << endl;
        cols[*it].erase(i);
        rows[i].erase(it++);
        ret = true;
      } else {
        cerr << endl;
        ++it;
      }
    }
  }
  cerr << sum << " " << ret << endl;
  return ret;
}

void process() {
  sum = 0;
  scanf(" %d %d", &r, &c);
  board = VVI(r, VI(c, 0));
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) scanf(" %d", &board[i][j]);
  }

  for(int i=0;i<r;i++) {
    rows[i].clear();
    for(int j=0;j<c;j++) {
      rows[i].insert(j);
    }
  }

  for(int i=0;i<c;i++) {
    cols[i].clear();
    for(int j=0;j<r;j++) {
      cols[i].insert(j);
    }
  }

  while(iter());
  cout << sum << endl;
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
