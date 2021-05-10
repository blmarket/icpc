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

  if(v1.size() == v2.size()) {
    auto s1 = VI(v1.begin(), v1.end() - 1);
    auto s2 = VI(v2.begin(), v2.end() - 1);
    if(s1 == s2 && v1.back() <= v2.back()) {
      cout << v2.back() - v1.back() + lead0 << endl;
      return;
    }
  }

  if(lead0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  if(v1.back() == 0) v1.pop_back();
  for(int nnot=1;nnot<v1.size();nnot++) {
    auto s1 = VI(v1.begin() + nnot, v1.end());
    if(s1.size() + nnot < v2.size()) break;

    // for(auto &it: s1) cerr << it << " ";
    // cerr << " : ";
    // for(auto &it: v2) cerr << it << " ";
    // cerr << endl;

    bool fail = false;
    int sum = nnot;
    for(int j=0;j<v2.size();j++) {
      if(j+1 < s1.size()) {
        if(s1[j] != v2[j]) { fail = true; break; }
        continue;
      }
      if(j+1 == s1.size()) {
        if(s1[j] > v2[j]) { fail = true; break; }
        sum += v2[j] - s1[j];
        continue;
      }
      sum += v2[j];
    }
    if (fail) continue;
    cout << sum << endl;
    return;
  }

  cout << "IMPOSSIBLE" << endl;
  return;
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

