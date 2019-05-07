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
#include <random>

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

int N = 10;
int mat[55][55];

int main(void) {
  memset(mat, 0, sizeof(mat));
  for(int i=0;i<N;i++) {
    mat[i][(i+1)%N] = 2;
    mat[(i+1)%N][i] = 2;
  }

  mt19937 rnd;
  cout << rnd() << endl;

  return 0;
}
