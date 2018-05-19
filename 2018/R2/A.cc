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

int N;
int V[105];

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &V[i]);
  }

  if(V[0] == 0 || V[N-1] == 0) {
    printf("IMPOSSIBLE\n");
    return;
  }

  int s = 0;
  for(int i=0;i<N;i++) {
    if(!V[i]) continue;
    cerr << s << " " << s+V[i] << " " << i << endl;
    s += V[i];
  }
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
