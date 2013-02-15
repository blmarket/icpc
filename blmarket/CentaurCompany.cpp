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

const int INF = 99999;

struct info {
    info(int h, int s, int d) : head(h), same(s), diff(d) {}

    int head, same, diff;

    bool operator<(const info &rhs) const {
        if(head != rhs.head) return head < rhs.head;
        if(same != rhs.same) return same < rhs.same;
        return diff < rhs.diff;
    }
};
typedef map<info, long long> data;

int n;
vector<int> links[40];

int add(int a, int b) {
    if(a == -INF) a = 0;
    if(b == -INF) b = 0;
    return a+b;
}

void go(int a, int parent, data &ret) {
    ret.clear();
    ret[info(1, -INF, -INF)] = 1;

    for(int i=0;i<size(links[a]);i++) {
        int oth = links[a][i];
        if(oth == parent) continue;

        data tmp;
        go(oth, a, tmp);

        data tmp2; tmp2.clear();
        foreach(it, ret) {
            foreach(jt, tmp) {
                int nh = it->first.head + jt->first.head;
                int ns = add(it->first.same, jt->first.same) - 2;
                int nd = add(it->first.diff, jt->first.diff) - 2;
                tmp2[info(nh, ns, nd)] += it->second * jt->second;

                nh = it->first.head;
                ns = add(it->first.same, jt->first.diff) - 2;
                nd = add(add(it->first.diff, jt->first.head), jt->first.same) - 4;
                tmp2[info(nh, ns, nd)] += it->second * jt->second;
            }
        }
        ret.swap(tmp2);
    }
}

class CentaurCompany 
{
public:
    double getvalue(vector <int> a, vector <int> b) 
    {
        n = size(a) + 1;
        for(int i=1;i<=n;i++) links[i].clear();
        for(int i=0;i<size(a);i++) {
            links[a[i]].pb(b[i]);
            links[b[i]].pb(a[i]);
        }
        data ret;
        go(1, -1, ret);
        long long tot = 0, need = 0;
        foreach(it, ret) {
            int same = add(it->first.head, it->first.same) - 2;
            int diff = it->first.diff;
            if(diff == -INF) diff = 0;
            need += it->second * (-min(same, 0) - min(diff, 0));
            tot += it->second;
        }
        return (double)need / tot;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.125; verify_case(1, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.375; verify_case(2, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.41796875; verify_case(3, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 15.500000001076842; verify_case(4, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 7, 2, 5, 6, 2, 4, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 10, 10, 4, 1, 6, 2, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.646484375; verify_case(5, Arg2, getvalue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CentaurCompany ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
