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

char A[100005];
char B[100005];

void process() {
  scanf(" %s", A);
  scanf(" %s", B);

  int L = strlen(A);
  int it = 0;
  for(int i=0;i<L;i++) {
    if(A[i] == B[it]) {
      ++it;
    }
    if(B[it] == 0) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
    return 0;
}
