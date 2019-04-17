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

int T, N, M;

int cs[] = { 16,9,5,7,11,13,17 };

bool process() {
  int rs[7];

  for(int i=0;i<7;i++) {
    for(int j=0;j<18;j++) printf("%d ", cs[i]);
    printf("\n");
    fflush(stdout);
    int sum = 0;
    for(int j=0;j<18;j++) {
      int tmp;
      scanf(" %d", &tmp);
      sum += tmp;
    }
    sum %= cs[i];
    rs[i] = sum;
  }

  for(auto it: rs) {
    cerr << it << " ";
  }
  cerr << endl;

  printf("1\n");
  fflush(stdout);
  int judge_response;
  scanf(" %d", &judge_response);
  if(judge_response == -1) return false;
  return true;
}

int main(void) {
    scanf(" %d %d %d", &T, &N, &M);
    for(int i=1;i<=T;i++) {
      if(!process()) return 0;
    }
    return 0;
}
