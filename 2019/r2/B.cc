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

vector<int> v;

void process() {
  int d;
  int cur = 1;
  int mark = -1;
  int marksize = -1;
  for(int i=1;i<=100;i++) {
    scanf(" %d", &d);
    if(d == -1) {
      cerr << "wrong" << endl;
      exit(0);
    }
    if(d == 100) {
      printf("20 100\n");
      fflush(stdout);
      break;
    }
    // if(mark != -1 && v.size() < 7) {
    //   cerr << "here" << endl;
    //   auto put = [&]() {
    //     for(int j=1;j<100;j++) {
    //       bool fail = false;
    //       for(int k=0;k<v.size();k++) {
    //         if(v[k] == j)
    //           fail = true; break;
    //       }
    //       if(!fail) {
    //         printf("%d %d\n", mark, j);
    //         fflush(stdout);
    //         v.pb(j);
    //         return;
    //       }
    //     }
    //   };
    //   // put();
    //   // continue;
    // }
    
    if(d >= 80 && cur < 20) {
      printf("%d 0\n", cur);
      fflush(stdout);
      int n;
      scanf(" %d", &n);
      v.resize(n);
      for(int j=0;j<n;j++) {
        scanf(" %d", &v[j]);
      }
      cerr << n << " ";
      for(int j=0;j<n;j++) cerr << v[j] << " ";
      cerr << endl;
      if(n < 7) {
        mark = cur;
        marksize = n;
      }
      cur++;
      continue;
    }
    int v = (d % 19) + 1;
    printf("%d %d\n", v, 100 - ((d-1) / 19));
    fflush(stdout);
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
    return 0;
}
