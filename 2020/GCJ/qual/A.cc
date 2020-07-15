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

int n;
int board[105][105];
int board2[105][105];

void process() {
  scanf(" %d", &n);
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      scanf(" %d", &board[i][j]);
      board2[j][i] = board[i][j];
    }
  }

  VI tgt(n);
  for(int i=0;i<n;i++) tgt[i] = i+1;

  int t = 0;
  int c1 = 0, c2 = 0;
  for(int i=0;i<n;i++) t += board[i][i];
  for(int i=0;i<n;i++) {
    sort(board[i], board[i] + n);
    c1 += (VI(board[i], board[i] + n) != tgt);
    sort(board2[i], board2[i] + n);
    c2 += (VI(board2[i], board2[i] + n) != tgt);
  }
  cout << t << " " << c1 << " " << c2 << endl;
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
