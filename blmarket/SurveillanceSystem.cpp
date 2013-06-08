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

int N, L;
int cons[55];

bool go(int pos, VI &cur, VI &rem, string &ret) {
    for(int i=0;i<=L;i++) {
        if(cur[i] < 0 || cur[i] > rem[i]) {
            ret = "";
            return false;
        }
    }

    if(pos+L == N) {
        if(cur[cons[pos]]) {
            ret = string(L, '+');
        } else {
            ret = string(L, '-');
        }
        return true;
    }

    string t1, t2;
    bool r1,r2;
    rem[cons[pos]]--;
    r1 = go(pos+1, cur, rem, t1);
    if(size(t1)) t1 = "-" + t1;
    cur[cons[pos]]--;
    r2 = go(pos+1, cur, rem, t2);
    if(size(t2)) {
        t2 = "+" + t2;
        for(int i=0;i<L;i++) t2[i] = '+';
    }
    cur[cons[pos]]++;
    rem[cons[pos]]++;

    if(!r1 || !r2) {
        ret = t1 + t2;
        return true;
    }

    ret = t1;
    for(int i=0;i<size(ret);i++) {
        if(ret[i] == '?') continue;
        if(ret[i] == t2[i]) continue;
        ret[i] = '?';
    }
    return true;
}

class SurveillanceSystem 
{
public:
    string getContainerInfo(string containers, vector <int> reports, int L_) 
    {
        N = size(containers);
        L = L_;
        VI rem(L+1, 0);
        VI cur = rem;
        for(int i=0;i+L<=N;i++) {
            cons[i] = 0;
            for(int j=i;j<i+L;j++) cons[i] += (containers[j] == 'X');
            rem[cons[i]]++;
        }
        for(int i=0;i<size(reports);i++) cur[reports[i]]++;

        string ret;
        go(0, cur, rem, ret);
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SurveillanceSystem ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
