#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

/**
 * Problem: 600
 * Test Case: 8
 * Succeeded: No
 * Execution Time: 2 ms
 * Peak memory used: 11.617MB
 * Args:
 * {
 * {3, 21, 16, 12, 25,  9, 26, 15, 19, 2,  18, 0, 7, 4, 11, 14, 17, 20, 22, 8, 5, 10, 23, 24, 6, 27, 13}, 
 * {1, 1,   3,  1,  1, 25, 12, 21, 26, 12, 26, 9, 0, 15, 19, 2, 18, 7, 4, 20, 20, 14, 20, 20, 5, 10, 6}, 
 * {13, 18, 23, 9, 27, 14, 4, 0, 10, 11, 5, 24, 19, 15, 2, 20, 25, 21, 3, 7, 16, 12, 1, 22, 6, 26, 17}, 
 * {8, 13, 13, 18, 9, 13, 13, 14, 23, 0, 11, 11, 0, 11, 24, 5, 15, 25, 15, 21, 20, 20, 21, 16, 3, 22, 12}, 
 * {439, 677, -245, -564, -289, 687, 501, -359, 19, 691, 335, 211, 196, 21, 10, 335, -711, -233, -49, -371, -316, -432, 228, 776, 503, -17, -608, 28}}
 *
 * Expected:
 * 1696
 *
 * Received:
 * 3174
 *
 * Answer checking result:
 * Returned value must exactly match the expected one.
 *
 */

vector<bool> visit;
vector<vector<PII> > V;

void init_graph(int sz) {
  V.clear();
  V.resize(sz);
}

void add_edge(int s, int e, int flow) {
  vector<PII> &vv = V[s];
  for(int i=0;i<size(vv);i++) {
    if(vv[i].first == e) {
      vv[i].second += flow;
      return;
    }
  }
  vv.pb(mp(e, flow));
}

int get_edge(int s, int e) {
    auto &vv = V[s];
    for(auto &it : vv) {
        if(it.first == e) return it.second;
    }
    return 0;
}

int try_flow(int s, int e, int maxflow) {
  if(s == e) {
    return maxflow;
  }
  if(visit[s]) return 0;
  visit[s] = true;
  for(auto &it : V[s]) {
    if(it.second > 0) {
      int tmp = try_flow(it.first, e, min(maxflow, it.second));
      if(tmp == 0) continue;

      add_edge(s, it.first, -tmp);
      add_edge(it.first, s, tmp);
      return tmp;
    }
  }
  return 0;
}

int do_flow(int s, int e) {
  int tot = 0;
  int tmp;
  while(true) {
    visit = vector<bool>(size(V), false);
    tmp = try_flow(s, e, 500000);
    if(tmp == 0) break;
    tot += tmp;
  }
  return tot;
}

void build_tree(int parent, int root, vector<int> &a, vector<int> &b, vector<int> &res) {
  for(int i=0;i<size(a);i++) if(a[i] == root || b[i] == root) {
    int oth = a[i] + b[i] - root;
    if(oth == parent) continue;
    res[oth] = root;
    build_tree(root, oth, a, b, res);
  }
}

class DoubleTree 
{
public:
  int maximalScore(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> score) 
  {
    int ret = 0;
    int n = size(score);
    for(int i=0;i<n;i++) {
      vector<int> p1, p2;
      p1 = p2 = VI(n, -1);
      build_tree(-1,i,a,b,p1);
      build_tree(-1,i,c,d,p2);

      init_graph(n+2);

      int sum = 0;
      for(int j=0;j<n;j++) {
        if(score[j] > 0) {
          sum += score[j];
          add_edge(n, j, score[j]);
        }
        if(score[j] < 0) {
          add_edge(j, n+1, -score[j]);
        }
        if(i != j) {
          add_edge(j, p1[j], 500000);
          add_edge(j, p2[j], 500000);
        }
      }

      int tmp = do_flow(n, n+1);
      cout << i << " " << sum << " " << sum-tmp << endl;
      for(int j=0;j<n;j++) {
          if(score[j] > 0) {
              cout << j << ":" << get_edge(n, j) << " ";
          }
      }
      cout << endl;
      if(ret < (sum - tmp)) {
        ret = sum - tmp;
      }
    }
    return ret;
  }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1000,24,100,-200}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1024; verify_case(0, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1000,24,100,200}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1324; verify_case(1, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-1000,-24,-100,-200}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; verify_case(2, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-1000,24,100,200}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 200; verify_case(3, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {0,0,1,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,1,1,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-3,2,2,-1,2,2,-1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; verify_case(4, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arr0[] = {0,0,1,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0,0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-3,2,2,-1,2,2,-1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; verify_case(5, Arg5, maximalScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DoubleTree ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
