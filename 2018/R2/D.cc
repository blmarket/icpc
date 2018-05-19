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

int N,M;
char board[25][25];
set<string> known;
int ret;

void check(string pat) {
  if(known.count(pat)) return;
  known.insert(pat);
  fprintf(stderr, "%s\n", pat.c_str());
}

void process() {
  known.clear();
  ret = 0;

  scanf(" %d %d", &N, &M);
  for(int i=0;i<N;i++) {
    scanf(" %s", board[i]);
  }

  for(int i=0;i+1<N;i++) {
    for(int j=0;j+1<M;j++) {
      string pat = string() + board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1];
      check(pat);
    }
  }
  check(string(4, 'B'));
  check(string(4, 'W'));
  if(M == 1) {
    for(int i=0;i+1<N;i++) {
      string pat = string() + board[i][0] + board[i][0] + board[i+1][0] + board[i+1][1];
      check(pat);
    }
  }
  if(N == 1) {
    for(int i=0;i+1<M;i++) {
      string pat = string() + board[0][i] + board[0][i+1] + board[0][i] + board[0][i+1];
      check(pat);
    }
  }

  printf("%d\n", ret);
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
