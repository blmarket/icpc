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

int n;
string str;

int ds;
int dict[1024];
string ss[1024];

void process() {
  ds = 0;
  int fail = -1;
  scanf(" %d", &n);
  for(int i=1;i<=n;i++) {
    cin >> str;
    cerr << i << " " << fail << endl;
    if(fail != -1) continue;

    bool supp = false;
    for(int j=0;j<ds;j++) {
      if(i % dict[j] == 0) {
        supp = true;
        if(str.size() < ss[j].size()) {
          fail = i;
          break;
        }
        if(str.substr(0, ss[j].size()) != ss[j]) {
          fail = i;
          break;
        }
        str = str.substr(ss[j].size());
      }
    }

    if(fail != -1) continue;

    if(str[0] >= '0' && str[0] <= '9') {
      if(supp) {
        fail = i;
        continue;
      }
      int tmp;
      sscanf(str.c_str(), " %d", &tmp);
      if(tmp != i) {
        fail = i;
      }
    }

    if(supp && str.size() == 0) {
      continue;
    }

    if(str.length() != 4) {
      fail = i;
      continue;
    }
    dict[ds] = i;
    ss[ds] = str;
    ds++;

    cerr << ds << " " << i << " " << str << endl;
  }

  printf("%d\n", fail == -1 ? n : fail-1);
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
      process();
    }
    return 0;
}
