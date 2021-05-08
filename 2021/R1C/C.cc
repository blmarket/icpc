#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

vector<int> v1, v2;

vector<int> encode(string s) {
  vector<int> ret;
  int cnt = 1;
  for(int i=1;i<s.size();i++) {
    if(s[i] == s[i-1]) {
      ++cnt;
    } else {
      ret.push_back(cnt);
      cnt = 1;
    }
  }
  ret.push_back(cnt);
  if(ret.size() % 2) ret.push_back(0);
  return ret;
}

void process() {
  char tmp[105];
  scanf(" %s", tmp);
  v1 = encode(tmp);
  scanf(" %s", tmp);
  v2 = encode(tmp);

  for(int i=0;i<=v2.size();i++) {
    int tmp = i;
    bool fail = false;
    for(int j=0;j+1<v1.size();j++) {
      if(i+j == v2.size() - 1) {
        if (v2[i+j] < v1[j]) {
          fail = true;
          break;
        }
        tmp += v2[i+j] - v1[j];
      }
      if(i+j >= v2.size()) {
        tmp += v1[j];
      }
      if(v2[i+j] != v1[j]) {
        fail = true;
        break;
      }
    }
    if(!fail) {
      cout << tmp << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
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
