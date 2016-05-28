#include <iostream>
#include <algorithm>
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

int n,k;
vector<double> v;
vector<double> vv;

double pp[300];

double go() {
  memset(pp, 0, sizeof(pp));
  pp[0]=1;
  for(int i=0;i<size(v);i++) {
    for(int j=i+1;j>=0;j--) {
      pp[j] += pp[j-1] * v[i];
      pp[j-1] *= (1-v[i]);
    }
  }
  return pp[k/2];
}

void process() {
  scanf(" %d %d", &n, &k);
  for(int i=0;i<n;i++) {
    double tmp;
    cin >> tmp;
    v.pb(tmp);
  }

  sort(v.begin(), v.end());

  double ret = 0;

  for(int i=0;i<=k;i++) {
    int right = n-k+i;
    vv.clear();
    for(int j=0;j<i;j++) {
      vv.pb(v[j]);
    }
    for(int j=right;j<n;j++) {
      vv.pb(v[j]);
    }
    double tmp = go();
    if(ret < tmp) ret = tmp;
  }
  printf("%.12lf\n", ret);
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ",i);
    process();
  }
  return 0;
}
