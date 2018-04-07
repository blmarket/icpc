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
int V[2][100005];

void process(void) {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) scanf(" %d", &V[i%2][i/2]);
  int v1 = (N+1)/2;
  int v2 = N/2;
  cerr << v1 << " " << v2 << endl;
  sort(V[0], V[0] + v1);
  sort(V[1], V[1] + v2);
  // each(it, V[0]) cout << it << " "; cout << endl;
  // each(it, V[1]) cout << it << " "; cout << endl;
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
