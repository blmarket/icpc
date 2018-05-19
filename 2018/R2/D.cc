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
int mark[25][25];

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void col(int a, int b) {
  mark[a][b] = 2;
  for(int i=0;i<4;i++) {
    int x = a+ dx[i];
    int y = b + dy[i];
    if(mark[x][y] == 1) col(x,y);
  }
}

int chry(string &pat, int aa, int bb) {
  memset(mark, 0, sizeof(mark));
  int cnt = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      int idx = (i < aa ? 2 : 0) + (j < bb ? 1 : 0);
      if(board[i][j] == pat[idx]) {
        mark[i][j] = 1;
        cnt++;
      }
    }
  }
  if(cnt == 0) return 0;

  bool tmp = false;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) if(mark[i][j] == 1) {
      if(tmp) return -1;
      tmp = true;
      col(i, j);
    }
  }
  return cnt;
}

void check(string pat) {
  if(known.count(pat)) return;
  known.insert(pat);
  // fprintf(stderr, "%s\n", pat.c_str());

  for(int i=0;i<=N;i++) {
    for(int j=0;j<=M;j++) {
      int tmp = chry(pat, i, j);
      if(tmp == -1) continue;
      if(ret < tmp) {
        fprintf(stderr, "%s %d %d\n", pat.c_str(), i, j);
        for(int k=0;k<N;k++) {
          for(int l=0;l<M;l++) {
            if(mark[k][l]) fprintf(stderr, "%c", board[k][l]); else fprintf(stderr, " ");
          }
          fprintf(stderr, "\n");
        }
        fprintf(stderr, "\n");
        ret = tmp;
      }
    }
  }
}

void process() {
  known.clear();
  ret = 1;

  scanf(" %d %d", &N, &M);
  for(int i=0;i<N;i++) {
    scanf(" %s", board[i]);
  }

  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      string pat;
      if(i+1 < N && j+1 < M) {
        pat = string() + board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1];
        check(pat);
      }
      if(i+1 < N) {
        pat = string() + board[i][j] + board[i][j] + board[i+1][j] + board[i+1][j];
        check(pat);
      }
      if(j+1 < M) {
        pat = string() + board[i][j] + board[i][j+1] + board[i][j] + board[i][j+1];
        check(pat);
      }
    }
  }
  check(string(4, 'B'));
  check(string(4, 'W'));

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
