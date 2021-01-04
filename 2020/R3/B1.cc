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
int T[20];

void process() {
  scanf(" %d %d", &K, &N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &T[i]);
  }
  for(int i=0;i<N;i++) {
    int unused; scanf(" %d", &unused);
  }

  int nn = (1 << (K*2));
  cout << nn << endl;
  for(int i=0;i<nn;i++) {
    vector<int> pts = VI();
    for(int j=0;j<N*2;j++) if ((1<<j) & i) {
      pts.pb(j);
    }

    int assign[20];
    int jj = 0;
    for(int j=0;j<size(pts);j++) {
      while(jj < N && pts[j] >= T[jj]) {
        jj++;
      }
      assign[j] = (jj % N);
      cerr << pts[j] << ":" << assign[j] << " ";
    }
    cerr << endl;
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
