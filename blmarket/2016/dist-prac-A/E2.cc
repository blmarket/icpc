#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <message.h>

#define mp make_pair
#define each(it, v) for(auto &it: v)
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

#include "majority.h"

int nn = NumberOfNodes() - 1;
int my = MyNodeId();

int main(void) {
  if (my == nn) {
    cout << 0 << endl;
    return 0;
  }
  return 0;
}
