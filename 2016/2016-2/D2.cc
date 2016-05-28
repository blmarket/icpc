#include <iostream>
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

int N;
LL data[30];
int cnt[30];
int bitcnt[30];

void process() {
  scanf(" %d" ,&N);
  char buf[30];
  for(int i=0;i<N;i++) {
    scanf(" %s", buf);
    for(int j=0;j<N;j++) {
      data[i] <<= 1;
      data[i] |= (buf[j] == '1');
    }
  }

  int ret = 0;

  while(true) {
    bool change = false;
    int unused = -1;
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        if(data[i] != data[j] && (data[i] & data[j])) {
          for(int k=0;k<N;k++) if((data[i] & (1<<k)) ^ (data[j] & (1<<k))) {
            ret++;
          }

          data[i] = data[j] = (data[i] | data[j]);
          change = true;
        }
      }
    }

    if(change) continue;
    memset(cnt, 0, sizeof(cnt));
    memset(bitcnt, 0, sizeof(bitcnt));
    for(int i=0;i<N;i++) {
      cnt[i]++;
      for(int j=0;j<N;j++) if(data[i] == data[j]) {
        cnt[i]++;
        cnt[j]++;
      }
      for(int j=0;j<N;j++) if(data[i] & (1LL << j)) {
        bitcnt[i]++;
      }
    }

    for(int i=0;i<N;i++) {
      LL tmp = (1LL << i);
      bool fail = false;
      for(int j=0;j<N;j++) {
        if(data[j] & tmp) {
          fail = true;
          break;
        }
      }
      if(!fail) {
        for(int j=0;j<N;j++) {
          cout << cnt[j] << " " << bitcnt[j] << endl;
          if(cnt[j] < bitcnt[j]) {
            data[j] |= (1LL<<i);
            goto onemore;
          }
        }
        cout << "FAIL" << endl;
      }
    }
    break;
onemore:
    continue;
  }
  cout << ret << endl;
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
