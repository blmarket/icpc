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

int N, P;
vector<PII> data;

void process() {
  scanf(" %d %d", &N, &P);
  int base = 0;
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    if(a > b) swap(a,b);
    data.pb(mp(a, b));
    base += a*2+b*2;
  }
  sort(data.rbegin(), data.rend());
  int rem = P - base;
  cerr << rem << endl;
  for(int i=0;i<N;i++) cerr << data[i].first << "," << data[i].second << " ";
  cerr << endl;
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
