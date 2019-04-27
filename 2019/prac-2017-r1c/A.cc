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
pair<LL, LL> data[1050];

void process() {
  scanf(" %d %d", &N, &K);
  for(int i=0;i<N;i++) {
    cin >> data[i].first >> data[i].second;
  }
  sort(data, data + N);
  for(int i=0;i<N;i++) {
    cerr << data[i].first << "," << data[i].second << " ";
  }
  cerr << endl;

  auto comp = [](const PII &a, const PII &b) {
    return (LL) a.first * a.second < (LL) b.first * b.second;
  };
  long double res = 0;
  for(int i=K;i<=N;i++) {
    if(i > 2) sort(data, data+i-2, comp);
    long double sum = M_PI * sqr((LL)data[i-1].first);
    for(int j=i-K;j<i;j++) {
      cerr << data[j].first << " ";
      sum += 2 * M_PIl * (long double)data[j].first * data[j].second;
      fprintf(stderr, "%.25llf ",sum);
    }
    cerr << " = " << sum << endl;
    if(res < sum) res = sum;
  }
  printf("%.25llf\n", res);
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
