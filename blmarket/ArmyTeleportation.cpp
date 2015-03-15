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

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

/**
 * Problem: 500
 * Test Case: 16
 * Succeeded: No
 * Execution Time: 1 ms
 * Peak memory used: 11.605MB
 * Args:
 * {{0}, {0}, {11}, {22}, {3, 4, 6}, {6, 8, 12}}
 *
 * Expected:
 * "impossible"
 *
 * Received:
 * "possible"
 *
 * Answer checking result:
 * Returned value must exactly match the expected one.
 */

vector<PII> v1, v2, v3;
vector<pair<long long, long long> > v4;
vector<int> xt,yt;

bool divi(long long a, long long b) {
    if(a == 0) return true;
    if(b == 0) return false;
    return ((a%b) == 0);
}

PII abs(PII v) {
    if(v.first >= 0) return v;
    v.first = -v.first;
    v.second = -v.second;
    return v;
}

long long gcd(LL a, LL b) {
    cout << "gcd " << a << " " << b << endl;
    a = abs(a);
    b = abs(b);
    if(a > b) swap(a,b);
    while(a != 0) {
        b = (b % a);
        swap(a,b);
    }
    return b;
}

bool match() {
    v3.clear();
    for(int i=0;i<size(v1);i++) {
        v3.pb(mp(v1[i].first - v2[i].first, v1[i].second - v2[i].second));
    }
    for(int i=1;i<size(v3);i++) {
        if(v3[i] != v3[0]) return false;
    }

    v4.resize(3);
    v4[0] = mp(xt[0] - xt[1], yt[0] - yt[1]);
    v4[1] = mp(xt[0] - xt[2], yt[0] - yt[2]);
    v4[2] = mp(xt[1] - xt[2], yt[1] - yt[2]);

    LL xt = v3[0].first;
    LL yt = v3[0].second;

    for(int i=0;i<3;i++) cout << v4[i].first << "," << v4[i].second << " ";
    cout << endl;
    cout << xt << " " << yt << endl;

    LL gx = gcd(gcd(v4[0].first, v4[1].first), v4[2].first);
    LL gy = gcd(gcd(v4[0].second, v4[1].second), v4[2].second);
    cout << gx << " " << gy << endl;
    if(!divi(xt, gx) || !divi(yt, gy)) return false;


    v4[0].first *= v4[2].second;
    v4[1].first *= v4[2].second;
    xt *= v4[2].second;

    v4[0].second *= v4[2].first;
    v4[1].second *= v4[2].first;
    yt *= v4[2].first;

    LL ah = v4[0].first - v4[0].second;
    LL bh = v4[1].first - v4[1].second;
    LL rh = xt - yt;

    cout << ah << " " << bh << " " << gcd(ah,bh) << " " << rh << endl;

    if(divi(rh, gcd(ah, bh))) {
        return true;
    }
    
    return false;
}

class ArmyTeleportation 
{
public:
    string ifPossible(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2, vector <int> xt_, vector <int> yt_) 
    {
        xt = xt_; yt = yt_;

        for(int i=0;i<3;i++) xt[i] *= 2, yt[i] *= 2;
        for(int i=0;i<size(x1);i++) {
            v1.pb(mp(x1[i], y1[i]));
            v2.pb(mp(x2[i], y2[i]));
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if(match()) {
            return "possible";
        }
        for(int i=0;i<size(v1);i++) {
            v1[i].first = xt[0] - v1[i].first;
            v1[i].second = yt[0] - v1[i].second;
        }
        sort(v1.begin(), v1.end());
        if(match()) {
            return "possible";
        }
        return "impossible";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 3, 2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 1, 3}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arg6 = "possible"; verify_case(0, Arg6, ifPossible(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3, 1, -2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {4, 2, 10}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arg6 = "impossible"; verify_case(1, Arg6, ifPossible(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {5, 3, 8}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arg6 = "impossible"; verify_case(2, Arg6, ifPossible(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arr0[] = {6, -5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, -10, -7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 11, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-5, 8, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, -5, 4}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {-8, -9, -4}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arg6 = "possible"; verify_case(3, Arg6, ifPossible(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arr0[] = {3, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6, 5, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {-2, 5, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1, -3, 2}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arg6 = "impossible"; verify_case(4, Arg6, ifPossible(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arr0[] = {903, -970, 404, 563}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-348, -452, 37, 692}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3359, 1486, 2860, 3019}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-416, -520, -31, 624}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {346, -838, 916}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {-541, -717, -348}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arg6 = "possible"; verify_case(5, Arg6, ifPossible(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_6() { int Arr0[] = {4600, 8914, 9330, -193, 5422}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, 7650, -7366, -8494, -6574}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-117326, -121640, -122056, -112533, -118148}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {322619, 314994, 330010, 331138, 329218}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {9523, -7546, -9858}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {-3750, -5347, -3828}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arg6 = "impossible"; verify_case(6, Arg6, ifPossible(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_7() { int Arr0[] = {4514, -67225, -78413, -96468, -58938}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-22815, -86062, -54529, -87391, 42044}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {259998, 331737, 342925, 360980, 323450}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {912263, 975510, 943977, 976839, 847404}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {23726, -98808, -26788}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {80876, -68160, -13684}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); string Arg6 = "possible"; verify_case(7, Arg6, ifPossible(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ArmyTeleportation ___test; 
    ___test.run_test(7); 
} 
// END CUT HERE
