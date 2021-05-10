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
  return ret;
}

void process() {
  bool lead0 = false;
  char tmp[105];
  scanf(" %s", tmp);
  if(tmp[0] == '0') lead0 = true;
  v1 = encode(tmp);
  scanf(" %s", tmp);
  v2 = encode(tmp);

  if (v1.size()%2) v1.pb(0);
  if (v2.size()%2) v2.pb(0);

  if (v2.size() > v1.size()) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  // v1.size() >= v2.size()
  int ret = -1;
  for(int sp=v1.size() - v2.size();sp<v1.size();sp++) {
    bool fail = false;
    int tmp = sp;
    for(int j=0;j<v2.size();j++) {
      int p1 = sp+j;
      if(p1+2 < v1.size()) {
        if(v1[p1] != v2[j]) {
          fail=true;
          break;
        }
      } else if (p1+2 == v1.size() && v1.back() == 0 && sp) {
        if (v1[p1] > v2[j]) {
          fail = true;
          break;
        }
        tmp += v2[j] - v1[p1];
      } else if (p1+1 == v1.size()) {
        if(v1[p1] > v2[j]) {
          fail = true;
          break;
        }
        tmp += v2[j] - v1[p1];
      } else {
        tmp += v2[j];
      }
    }
    if (fail) {
      continue;
    }
    cerr << sp << " " << tmp << endl;
    if (ret == -1 || ret > tmp) ret = tmp;
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

