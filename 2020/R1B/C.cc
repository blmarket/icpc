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

int r, s;
vector<int> v;
vector<int> sorted;

void process() {
  scanf(" %d %d", &r, &s);
  v.clear();
  for(int i=0;i<s;i++) {
    for(int j=0;j<r;j++) {
      v.pb(j);
    }
  }
  sorted = v;
  sort(sorted.begin(), sorted.end());

  while(true) {
    for(auto it: v) cout << it << " "; cout << endl;

    if(v == sorted) break;
    vector<int> v2;
    int v1 = v[0];
    int i;
    for(i=1;v[i] == v1;i++);
    for(;v[i] == v1+1;i++);
    int j;
    for(j=i;v[i] != v1 || v[i+1] == v1;j++) {
      v2.pb(v[j]);
    }
    for(int k=0;k<i;k++) v2.pb(v[k]);
    for(int k=j;k<v.size();k++) v2.pb(v[k]);
  }
}

// 123412341234
// 123123412344
// 123123123444
// 121231233444
// 121212333444
// 112122333444
// 111222333444

// 123451234512345
// 345112234512345
// 511223344512345
// 112233445512345
// 334455111222345
// 551112223334445
// 111222333444555



int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
