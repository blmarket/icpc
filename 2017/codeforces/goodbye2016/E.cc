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

int n, q;
char seq[200005];
int matrix[524288][5][5];
const int POS = 262144;

void merge(auto &s1, auto &s2, auto &r) {
  memset(r, 0, sizeof(r));
}

int main(void) {
  scanf(" %d %d", &n, &q);
  scanf(" %s", seq);

  for(int i=0;i<n;i++) {
    for(int j=0;j<5;j++) {
      matrix[POS+i][j][j] = 0;
      for(int k=j+1;k<5;k++) matrix[POS+i][j][k] = 1000000;
    }
    if(seq[i] == '2') {
      matrix[POS+i][0][0] = 1;
      matrix[POS+i][0][1] = 0;
    }
    if(seq[i] == '0') {
      matrix[POS+i][1][1] = 1;
      matrix[POS+i][1][2] = 0;
    }
    if(seq[i] == '1') {
      matrix[POS+i][2][2] = 1;
      matrix[POS+i][2][3] = 0;
    }
    if(seq[i] == '6') {
      matrix[POS+i][3][3] = 1;
      matrix[POS+i][4][4] = 1;
    }
    if(seq[i] == '7') {
      matrix[POS+i][3][4] = 0;
    }
  }

  for(int i=0;i<q;i++) {
  }
  return 0;
}
