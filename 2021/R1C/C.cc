#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

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
  if(tmp[0] == '0') {
    if(lead0) {
      cout << 0 << endl;
    } else {
      cout << v1.size() << endl;
    }
    return;
  }
  v2 = encode(tmp);

  if (v1.size()%2) v1.pb(0);
  if (v2.size()%2) v2.pb(0);

  if (v2.size() > v1.size()) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  if (v1.back() == 0) {
    v1.pop_back();
  }

  // v1.size() >= v2.size()
  int ret = -1;
  int ss = (int)size(v1) - (int)size(v2);
  cout << ss << endl;
  for(int sp=ss;sp<=v1.size();sp++) {
    if (sp < 0) continue;
    bool fail = false;
    int tmp = sp;
    for(int j=0;j<v2.size();j++) {
      // cerr << sp << " " << j << " " << tmp << endl;
      int p1 = sp+j;
      if(p1+1 < v1.size()) {
        if(v1[p1] != v2[j]) {
          fail=true;
          break;
        }
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
  cout << lead0 + ret << endl;
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

