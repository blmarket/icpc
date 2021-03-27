#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N;

vector<int> go(vector<int> &arr) {
  int res;
  if(arr.size() == 1) {
    return arr;
  }
  if(arr.size() == 2) {
    cout << arr[0] << " " << arr[1] << " " << left << endl;
    scanf(" %d", &res);
    if(res == arr[1]) {
      swap(arr[0], arr[1]);
    }
    return arr;
  }

  vector<int> left, right;
  int mid;

  cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
  scanf(" %d", &res);
  left.pb(res == arr[0] ? arr[1] : arr[0]);
  right.pb(res == arr[2] ? arr[1] : arr[2]);
  mid = res;

  for(int i=4;i<arr.size();i++) {
    cout << left[0] << " " << mid << " " << arr[i] << endl;
    scanf(" %d", &res);
    if(res == mid) {
      right.pb(arr[i]);
    } else {
      left.pb(arr[i]);
    }
  }

  left = go(left);
  right = go(right);

  if(right.size() > 1) {
    cout << mid << " " << right[0] << " " << right[1] << endl;
    scanf(" %d", &res);
    if(res == right[1]) {
      reverse(right.begin(), right.end());
    }
  }

  if(left.size() > 1) {
    cout << mid << " " << left[0] << " " << left[1] << endl;
    scanf(" %d", &res);
    if(res == left[0]) {
      reverse(left.begin(), left.end());
    }
  }

  arr.clear();
  for(auto &it: left) arr.pb(it);
  arr.pb(mid);
  for(auto &it: right) arr.pb(it);

  return arr;
}

int main(void) {
    int T, Q;
    scanf(" %d %d %d", &T, &N, &Q);
    for(int i=1;i<=T;i++) {
      vector<int> arr;
      for(int j=1;j<=N;j++) arr.pb(j);
      arr = go(arr);
      cerr << "GOT" << endl;
      for(auto &it: arr) cout << it << " ";
      cout << endl;
      int tmp;
      scanf(" %d", &tmp);
    }
    return 0;
}
