#include <iostream>
#include <cmath>
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
#define sqr(x) ((x)*(x))

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, K;
PII data[1050];

void process() {
  scanf(" %d %d", &N, &K);
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    data[i] = mp(a, b);
  }
  sort(data, data + N);
  auto comp = [](const PII &a, const PII &b) {
    return a.second < b.second;
  };
  double res = 0;
  for(int i=K;i<N;i++) {
    sort(data, data+i-2, comp);
    double sum = M_PI * sqr(data[i-1].first);
    for(int j=i-K;j<i;j++) {
      sum += M_PI * data[j].first * data[j].second;
    }
    if(res < sum) res = sum;
  }
  printf("%.15lf\n", res);
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
