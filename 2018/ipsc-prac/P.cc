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

void solve(int a, int b) {
  char chr = 'a';
  int cnt = b*b / a;
  int tmp = 0;
  char board[1024];
  board[b] = 0;
  for(int i=0;i<b;i++) {
    for(int j=0;j<b;j++) {
      board[j] = chr;
      tmp++;
      if(tmp == cnt) {
        chr++;
        tmp = 0;
      }
    }
    cout << board << endl;
  }
}

int main(void) {
  int t;
  scanf(" %d", &t);
  for(int i=0;i<t;i++) {
    int a;
    scanf(" %d", &a);
    for(int j=1;j<=a;j++) {
      if((j*j) % a == 0) {
        cout << j << endl;
        solve(a, j);
        break;
      }
    }
  }
  return 0;
}
