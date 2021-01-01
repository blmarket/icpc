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
vector<int> R;

void process() {
  R.clear();
  scanf(" %d %d", &K, &N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &pts[i]);
  }
  for(int i=0;i+1<N;i++) {
    R.pb(pts[i+1] - pts[i]);
  }
  R.pb(K - pts[N-1] + pts[0]);
  for(int i=0;i<N;i++) {
    int unused;
    scanf(" %d", &unused);
  }
  for(int i=0;i<R.size();i++) cout << R[i] << " ";
  cout << endl;

  int mm = 0;
  for(int i=1;i<R.size();i++) if(R[i] < R[mm]) mm = i;
  cout << mm << endl;
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
