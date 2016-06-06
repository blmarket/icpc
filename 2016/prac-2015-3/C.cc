#include <iostream>
#include <algorithm>
#include <bitset>
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
template<typename T> void setmin(T &a, const T &b) { if(a>b) a=b; }

int Y, N;
vector<PII> data;
double dyna[505][505][505];

void process(void) {
  scanf(" %d %d", &Y, &N);
  data.resize(N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &data[i].second);
  }
  for(int i=0;i<N;i++) {
    scanf(" %d", &data[i].first);
  }
  sort(data.rbegin(), data.rend());

  vector<int> ls, rs;
  for(int i=0;i<N;i++) {
    if(data[i].second < 0) {
      data[i].first *= -1;
      ls.pb(i);
    } else {
      rs.pb(i);
    }
  }

  int L = ls.size();
  int R = rs.size();
  for(int i=0;i<=L;i++) {
    for(int j=0;j<=R;j++) {
      for(int k=0;k<=N;k++) dyna[i][j][k] = 1e18;
    }
  }

  dyna[0][0][0] = 0;
  for(int i=0;i<=L;i++) {
    for(int j=0;j<=R;j++) {
      for(int k=0;k<N;k++) if(dyna[i][j][k] < 1e17) {
        double t = dyna[i][j][k];
        cerr << i << " " << j << " " << k << " = " << t << endl;
        double pos = t * data[i].first + data[i].second;

        if(i < L) {
          int ni = ls[i];
          double npos = t * data[ni].first + data[ni].second;
          cerr << ni << " <-> " << npos << endl;
          if(pos < npos) {
            setmin(dyna[i+1][j][ni], t);
          } else {
            double nt = t + (pos - npos) / (Y + data[ni].first);
            cerr << "nt = " << nt << endl;
            setmin(dyna[i+1][j][ni], nt);
          }
        }
        if(j < R) {
          int ni = rs[j];
          double npos = t * data[ni].first + data[ni].second;
          if(pos > npos) {
            setmin(dyna[i][j+1][ni], t);
          } else {
            double nt = t + (npos - pos) / (Y - data[ni].first);
            setmin(dyna[i][j+1][ni], nt);
          }
        }
      }
    }
  }

  double ret = 1e18;
  for(int i=0;i<N;i++) {
    cerr << dyna[L][R][i] << endl;
    setmin(ret, dyna[L][R][i]);
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
