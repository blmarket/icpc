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
int V[100005];
bool visit[100005];

unordered_map<int, LL> memo;

int go(int a) {
  if(visit[a]) return 0;
  visit[a] = true;
  return go(V[a]) + 1;
}

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &V[i]);
    V[i]--;
  }

  LL ret = 1;

  for(int i=0;i<N;i++) {
    if(visit[i] == false) {
      int tmp = go(i);
      cerr << tmp << " ";
    }
  }
  cerr << endl;
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
    return 0;
}
