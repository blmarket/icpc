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
#define assert(x) 1

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

const int mod = 1000000009;

int go2(VI da, VI db, VI dc) {
    return 0;
}

int pump(const VI &a) {
    long long ret = 1;
    int lastidx = 0;
    for(int i=1;i<size(a);i++) {
        ret = (ret * (lastidx + 1)) % mod;
        if(a[i] == a[i-1]) {
            continue;
        }
        lastidx = i;
    }
    return ret;
}

int check1(const VI &da, const VI &db, const VI &dc) {
    VI la, lb, lc;
    int dab = -1, dbc = -1;
    for(int i=0;i<size(da);i++) {
        if(da[i] < db[i] && da[i] < dc[i]) {
            la.pb(da[i]);
            int tab = db[i] - da[i], tbc = dc[i] - db[i];            
            if(tbc < 0) return 0;
            if(dab == -1) dab = tab;
            if(dbc == -1) dbc = tbc;
            if(dab != tab || dbc != tbc) return 0;
            continue;
        }
        if(db[i] < da[i] && db[i] < dc[i]) {
            lb.pb(db[i]);
            int tab = da[i] - db[i];
            int tbc = dc[i] - db[i];
            if(dab == -1) dab = tab;
            if(dbc == -1) dbc = tbc;
            if(dab != tab || dbc != tbc) return 0;
            continue;
        }
        if(dc[i] < da[i] && dc[i] < db[i]) {
            lc.pb(dc[i]);
            int tab = da[i] - db[i];
            int tbc = db[i] - dc[i];
            if(dab == -1) dab = tab;
            if(dbc == -1) dbc = tbc;
            if(dab != tab || dbc != tbc) return 0;
            continue;
        }
        return 0;
    }

    la.pb(0); lb.pb(0); lc.pb(0);
    sort(la.begin(), la.end()); sort(lb.begin(), lb.end()); sort(lc.begin(), lc.end());
    long long ret = 1;
    ret *= pump(la);
    ret = (ret * pump(lb)) % mod;
    ret = (ret * pump(lc)) % mod;
    return ret;
}

int check2(const VI &da, const VI &db, const VI &dc) {
    int mindist = 2100000000;
    for(int i=0;i<size(da);i++) {
        int tmp = da[i] + db[i];
        if(tmp < mindist) {
            mindist = tmp;
        }
    }

    map<int, VI> M;
    vector<int> lc;
    int dbc = -1;
    for(int i=0;i<size(da);i++) {
        int key = da[i] - db[i];
        if(key < -mindist || key > mindist) return 0;

        if(key >= -mindist && key < mindist) { // mid
            int tbc = dc[i] - db[i];
            if(tbc <= 0) return 0;
            if(dbc == -1) dbc = tbc;
            if(dbc != tbc) return 0;
            int sum = da[i] + db[i] - mindist;
            if(sum & 1) return 0;
            sum /= 2;
            M[key].pb(sum);
            continue;
        }

        assert(key == mindist); // bind to B or C
        if(db[i] == dc[i]) return 0;
        if(db[i] < dc[i]) {
            int tbc = dc[i] - db[i];
            if(dbc == -1) dbc = tbc;
            if(dbc != tbc) return 0;
            M[mindist].pb(db[i]);
        } else { assert(db[i] > dc[i]);
            int tbc = db[i] - dc[i];
            if(dbc == -1) dbc = tbc;
            if(dbc != tbc) return 0;
            M[mindist + dbc].pb(dc[i]);
        }
    }
    M[-mindist].pb(0);
    M[mindist].pb(0);
    M[mindist + dbc].pb(0);
    cout << "info : " << mindist << " " << dbc << endl;

    long long ret = 1;
    foreach(it, M) {
        sort(it->second.begin(), it->second.end());
        ret = (ret * pump(it->second)) % mod;
    }
    return ret;
}

int go1(const VI &da, const VI &db, const VI &dc) {
    int ret = 0;

    // A - B - C
    //ret = check1(da, db, dc);

    // A - B - X - C
    // A - X - B - C
    ret = (ret + check2(da, db, dc)) % mod;
    ret = (ret + check2(dc, db, da)) % mod;
    cout << ret << endl;
    // A - X - B - X - C
    return ret;
}

class UnknownTree 
{
public:
    int getCount(vector <int> dA, vector <int> dB, vector <int> dC) 
    {		
        int ret = go1(dA, dB, dC);
        //ret = (ret + go1(dB, dC, dA)) % mod;
        //ret = (ret + go1(dC, dA, dB)) % mod;
        //ret = (ret + go2(dA, dB, dC)) % mod;
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {2, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 6, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {4, 6, 1, 5, 3, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2, 3, 1, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 7, 2, 6, 4, 3, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {6, 4, 5, 6, 8, 1, 5, 6, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2, 3, 4, 6, 1, 3, 4, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 4, 5, 6, 8, 3, 5, 6, 4, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9000; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {8, 5, 6, 8, 6, 5, 6, 10, 8, 5, 10, 8, 7, 9, 7, 1, 11, 5, 9, 6, 6, 1, 6, 9, 8, 4, 12, 7, 5, 7, 6, 8, 12, 8, 6, 6, 5, 8, 5, 3, 3, 4, 8, 6, 6, 8, 8, 9, 7, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 6, 7, 9, 7, 6, 7, 11, 9, 6, 11, 9, 8, 10, 8, 2, 12, 6, 10, 7, 7, 4, 7, 10, 9, 5, 13, 8, 6, 8, 7, 9, 13, 9, 7, 7, 6, 9, 6, 4, 4, 5, 9, 7, 7, 9, 9, 10, 8, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 9, 6, 8, 2, 5, 6, 10, 8, 5, 10, 8, 7, 9, 1, 5, 11, 5, 9, 6, 6, 7, 6, 9, 8, 4, 12, 7, 5, 7, 6, 8, 12, 8, 6, 6, 5, 8, 1, 7, 3, 4, 8, 6, 6, 8, 8, 3, 7, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 770724166; verify_case(6, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {33030780, 30296205, 16842859, 28857842, 37928939, 27190807, 48689043, 33328845, 24254103, 3962046,
31043603, 25699520, 11297547, 27045586, 31603483, 23207518, 44089781, 48470539, 52366295, 39786470,
45623279, 21593844, 38639305, 27260993, 43899542, 36162768, 21640232, 43580853, 33826577, 30501815,
51470990, 2157904, 27823597, 9550575, 39234641, 24163007, 34155133, 42504989, 35821444, 36054200,
29026389, 29716374, 41764139, 19392309, 44258194, 19987908, 56722905, 46771885, 32668277, 40665175}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16191697, 13457122, 3776, 12018759, 21089856, 10351724, 31849960, 16489762, 7415020, 12877037,
14204520, 8860437, 9035480, 10206503, 14764400, 6368435, 27250698, 31631456, 35527212, 22947387,
28784196, 4754761, 21800222, 10421910, 27060459, 19323685, 4801149, 26741770, 16987494, 13662732,
34631907, 18996987, 10984514, 7288508, 22395558, 7323924, 17316050, 25665906, 18982361, 19215117,
12187306, 12877291, 24925056, 2553226, 27419111, 3148825, 39883822, 29932802, 15829194, 23826092}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {19337227, 16602652, 3149306, 15164289, 24235386, 13497254, 34995490, 19635292, 10560550, 16030119,
17350050, 12005967, 12188562, 13352033, 17909930, 3215353, 30396228, 34776986, 38672742, 26092917,
31929726, 7907843, 24945752, 13567440, 30205989, 22469215, 7946679, 29887300, 20133024, 16808262,
37777437, 22150069, 14130044, 10441590, 25541088, 10469454, 20461580, 28811436, 22127891, 22360647,
15332836, 16022821, 28070586, 5706308, 30564641, 6294355, 43029352, 33078332, 18974724, 26971622}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 101733071; verify_case(7, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    UnknownTree ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
