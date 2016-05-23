#include <iostream>
#include <sys/wait.h>
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
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

string ns[] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

int order[] = { 0, 2, 4, 6, 8, 1,3,5,7,9 };

void process(void) {
  char buf[4096];
  scanf(" %s", buf);
  map<char, int> MM;
  for(int i=0;i<strlen(buf);i++) {
    MM[buf[i]] += 1;
  }

  string ret;

  for(int i=0;i<10;i++) {
    int tmp = order[i];
    map<char, int> M;
    for(auto &it: ns[tmp]) {
      M[it] += 1;
    }

    int maxc = 10000;
    for(auto &it: M) {
      maxc = min(maxc, MM[it.first] / it.second);
    }

    ret += string(maxc, tmp + '0');
    for(auto &it: M) {
      MM[it.first] -= it.second * maxc;
    }

    for(auto &it: MM) {
      // cerr << it.first << " - " << it.second << endl;
    }
  }

  sort(ret.begin(), ret.end());
  cout << ret << endl;
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
