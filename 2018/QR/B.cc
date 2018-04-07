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
  for(int i=0;i<v1;i++) cout << V[0][i] << " "; cout << endl;
  for(int i=0;i<v2;i++) cout << V[1][i] << " "; cout << endl;
  for(int i=1;i<N;i++) if(V[i%2][i/2] > V[(i-1)%2][(i-1)/2]) {
    cerr << V[i%2][i/2] << endl;
    cout << i << endl;
    return;
  }
  cout << "OK" << endl;
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
