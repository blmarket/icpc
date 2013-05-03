#include <iostream>
#include <cstring>
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

int match[55][55];
int parent[55];
vector<int> a,b;
int N;

void setparent(int pos, int par) {
    parent[pos] = par;
    for(int i=0;i<size(a);i++) {
        if(a[i] != pos && b[i] != pos) continue;
        int oth = a[i] + b[i] - pos;
        if(oth == par) continue;
        setparent(oth, pos);
    }
}

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);

    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

void calc(int a, int b) {
    vector<int> ca, cb;
    VVI w;
    for(int i=0;i<N;i++) if(parent[i] == a) ca.pb(i);
    for(int i=0;i<N;i++) if(parent[i] == b) cb.pb(i);

    if(ca.size() == 0 || cb.size() == 0) {
        match[a][b] = match[b][a] = 1;
        return;
    }

    w.resize(ca.size());
    for(int i=0;i<size(ca);i++) w[i].resize(cb.size());

    for(int i=0;i<size(ca);i++) for(int j=0;j<size(cb);j++) {
        if(match[ca[i]][cb[i]] == -1) calc(ca[i], cb[i]);
        w[i][j] = match[ca[i]][cb[i]];
    }

    vector<int> t1,t2;
    BipartiteMatching(w, t1, t2);

    int totmatch = 1;
    for(int i=0;i<size(t1);i++) if(t1[i] >= 0) {
        totmatch += w[i][t1[i]];
    }

    match[a][b] = match[b][a] = totmatch;
}

int go(int pos) {
    memset(match, -1, sizeof(match));
    setparent(a[pos], b[pos]);
    setparent(b[pos], a[pos]);

    parent[a[pos]] = -1;
    parent[b[pos]] = -1;

    int ret = -1;
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        if(match[i][j] == -1) calc(i,j);
        if(ret < match[i][j]) ret = match[i][j];
    }
    return ret;
}

class DeerInZooDivOne 
{
public:
    int getmax(vector <int> a_, vector <int> b_) 
    {
        int ret = 0;
        a=a_;b=b_;
        N = size(a) + 1;

        for(int i=0;i<size(a);i++) {
            int tmp = go(i);
            if(ret < tmp) ret = tmp;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 8, 1, 7, 4, 2, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 3, 6, 8, 2, 6, 8, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 11, 10, 10, 19, 17, 6, 17, 19, 10, 10, 11, 9, 9, 14, 2, 13, 11, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 5, 2, 12, 8, 9, 16, 8, 4, 18, 8, 13, 15, 13, 17, 16, 3, 1, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {14, 13, 28, 15, 20, 4, 9, 6, 1, 23, 19, 25, 25, 8, 14, 16, 2, 8, 15, 25, 22, 22, 28, 10, 10, 14, 24, 27, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {21, 5, 12, 13, 27, 1, 24, 17, 27, 17, 23, 14, 18, 26, 7, 26, 11, 0, 25, 23, 3, 29, 22, 11, 22, 29, 15, 28, 29}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(4, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DeerInZooDivOne ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
