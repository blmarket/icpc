#include <iostream>
#include <sys/wait.h>
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

map<string, int> m1;
map<string, int> m2;
int n;

void process(void) {
  scanf(" %d", &n);
  m1.clear();
  m2.clear();
  char s1[32], s2[32];
  for(int i=0;i<n;i++) {
    scanf(" %s %s", s1, s2);
    if(m1.count(s1) == 0) {
      m1[s1] = m1.size();
    }
    if(m2.count(s2) == 0) {
      m2[s2] = m2.size();
    }
  }

  for(auto &it : m1) {
    cout << it.first << " = " << it.second << endl;
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
