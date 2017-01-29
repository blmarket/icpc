#include "paint.h"

#include <cstdlib>
#include <iostream>
#include <algorithm>

#define pb push_back

using namespace std;

bool check_place(const string &str, int s, int l) {
  for(int i=0;i<l;i++) {
    if(str[s+i] == '_') return false;
  }
  if(str[s+l] == 'X') return false;
  return true;
}

vector<int> try_place(const string &s, const vector<int> &c) {
  vector<int> ret;
  int pos = 0;
  for(int i=0;i<c.size();i++) {
    int it = c[i];
    while(!check_place(s, pos, it)) {
      ret.pb(-1);
      pos++;
    }
    for(int j=0;j<it;j++) {
      ret.pb(i);
    }
    ret.pb(-1);
    pos += it + 1;
  }
  while(ret.size() < s.size()) {
    ret.pb(-1);
  }
  return ret;
}

std::string solve_puzzle(std::string s, std::vector<int> c) {
  vector<int> t1, t2;
  t1 = try_place(s, c);
  reverse(s.begin(), s.end());
  reverse(c.begin(), c.end());
  t2 = try_place(s, c);
  reverse(t2.begin(), t2.end());
  for(int i=0;i<t2.size();i++) if(t2[i] != -1) {
    t2[i] = c.size() - t2[i] - 1;
  }
  for(int i=0;i<t1.size();i++) {
    cerr << t1[i] << " ";
  }
  cerr << endl;
  for(int i=0;i<t1.size();i++) {
    cerr << t2[i] << " ";
  }
  cerr << endl;
  return "";
}
