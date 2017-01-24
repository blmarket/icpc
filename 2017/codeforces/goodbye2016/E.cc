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
const int BIG = -1;

void merge(auto &s1, auto &s2, auto &r) {
  for(int i=0;i<5;i++) for(int j=i;j<5;j++) r[i][j] = BIG;
  for(int i=0;i<5;i++) {
    for(int j=i;j<5;j++) if(s1[i][j] != BIG) {
      for(int k=j;k<5;k++) if(s2[j][k] != BIG) {
        if(r[i][k] == BIG || r[i][k] > s1[i][j] + s2[j][k]) r[i][k] = s1[i][j] + s2[j][k];
      }
    }
  }
}

int main(void) {
  scanf(" %d %d", &n, &q);
  scanf(" %s", seq);

  for(int i=0;i<n;i++) {
    for(int j=0;j<5;j++) {
      matrix[POS+i][j][j] = 0;
      for(int k=j+1;k<5;k++) matrix[POS+i][j][k] = BIG;
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

  for(int i=POS-1;i>0;i--) {
    merge(matrix[i*2], matrix[i*2+1], matrix[i]);
  }

  for(int i=0;i<q;i++) {
    int s, e;
    scanf(" %d %d", &s, &e);
    s--;
    int t1[5][5], t2[5][5];
    memcpy(t1, matrix[POS + s], sizeof(t1));
    for(int j=s+1;j<e;j++) {
      merge(t1, matrix[POS+j], t2);
      memcpy(t1, t2, sizeof(t1));
    }
    for(int i=0;i<5;i++) {
      for(int j=0;j<5;j++) printf("%8d ", t1[i][j]);
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
