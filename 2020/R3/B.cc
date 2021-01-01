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

int K, N;
int pts[105];
vector<PII> R;

void process() {
  R.clear();
  scanf(" %d %d", &K, &N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &pts[i]);
  }
  for(int i=0;i+1<N;i++) {
    R.pb(mp(pts[i+1] - pts[i], 0));
  }
  R.pb(mp(K - pts[N-1] + pts[0], 0));
  for(int i=0;i<N;i++) {
    int unused;
    scanf(" %d", &unused);
  }

  if (R.size() < 2) {
    cout << 1 << endl;
    return;
  }

  if (R.size() == 2) {
    cout << 2 + (R[0].first != R[1].first) << endl;
    return;
  }

  for(int i=0;i<R.size();i++) cerr << R[i].first << " ";
  cerr << endl;

  int mm = 0;
  for(int i=1;i<R.size();i++) if(R[i].first < R[mm].first) mm = i;
  cerr << mm << endl;
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
