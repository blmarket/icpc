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

const LL MOD = 1e9 + 7;

int M;
int D[100005][2];
LL S[100005];
vector<int> back[100005];

void process() {
  scanf(" %d", &M);
  for(int i=1;i<=M;i++) back[i].clear();
  for(int i=1;i<=M;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    tie(D[i][0], D[i][1]) = { a, b };
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
