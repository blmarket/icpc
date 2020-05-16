#include <iostream>
#include <functional>
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

int K, Q;
char code[100005];
int port[100005];
int query[100005][2];
int cost[100005];

void process() {
  scanf(" %d %d", &K, &Q);
  scanf(" %s", code);
  VI stack;
  for(int i=0;i<K;i++) {
    if(code[i] == '(') {
      stack.pb(i);
    } else {
      port[i] = stack.back();
      port[stack.back()] = i;
      stack.pop_back();
    }
  }

  for(int i=0;i<K*3;i++) {
    int tmp;
    scanf(" %d", &tmp);
  }
  for(int i=0;i<2;i++) {
    for(int j=0;j<Q;j++) {
      scanf(" %d", &query[j][i]);
    }
  }

  int ret = 0;
  for(int i=0;i<Q;i++) {
    int s = query[i][0];
    int e = query[i][1];
    memset(cost, -1, sizeof(cost));
    cost[s] = 0;
    priority_queue<PII> Q;
    Q.push(mp(0, s));
    while(!Q.empty() && cost[e] == -1) {
      auto v = Q.top();
      int node = v.second;
      Q.pop();
      if(v.first != cost[node]) continue;
      int nn = port[node];
      if(cost[nn] == -1 || cost[nn] > cost[node] + 1) {
        cost[nn] = cost[node] + 1;
        Q.push(mp(cost[nn], nn));
      }
      
      if(node < e) {
        int n2 = node + 1;
        if(cost[n2] == -1 || cost[n2] > cost[node] + 1) {
          cost[n2] = cost[node] + 1;
          Q.push(mp(cost[n2], n2));
        }
        if(nn < e && node > 0) {
          int n2 = node - 1;
          if(cost[n2] == -1 || cost[n2] > cost[node] + 1) {
            cost[n2] = cost[node] + 1;
            Q.push(mp(cost[n2], n2));
          }
        }
      } else {
        int n2 = node - 1;
        if(cost[n2] == -1 || cost[n2] > cost[node] + 1) {
          cost[n2] = cost[node] + 1;
          Q.push(mp(cost[n2], n2));
        }
        if(nn >= e && node + 1 < K) {
          int n2 = node - 1;
          if(cost[n2] == -1 || cost[n2] > cost[node] + 1) {
            cost[n2] = cost[node] + 1;
            Q.push(mp(cost[n2], n2));
          }
        }
      }
    }
    cerr << cost[e] << endl;
    ret += cost[e];
  }
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
