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

int n;
bool mm[55][55];

void process() {
  scanf(" %d", &n);
  memset(mm, 0, sizeof(mm));
  for(int i=0;i<n;i++) {
    mm[i][i] = 1;
  }
  for(int i=0;i+1<n;i++) {
    mm[i][i+1] = 1;
    mm[i+1][i] = 1;
  }
  char tmp[55];
  scanf(" %s", tmp);
  for(int i=0;i<n;i++) if(tmp[i] == 'N') {
    if(i) mm[i-1][i] = 0;
    if(i+1 < n) mm[i+1][i] = 0;
  }
  scanf(" %s", tmp);
  for(int i=0;i<n;i++) if(tmp[i] == 'N') {
    if(i) mm[i][i-1] = 0;
    if(i+1 < n) mm[i][i+1] = 0;
  }

  for(int k=0;k<n;k++) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        if(mm[i][k] && mm[k][j]) mm[i][j] = true;
      }
    }
  }

  cout << endl;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout << (mm[i][j]?'Y':'N');
    }
    cout << endl;
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
