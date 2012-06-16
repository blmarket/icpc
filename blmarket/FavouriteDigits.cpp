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

int d1,c1,d2,c2;
set<pair<pair<int,bool>, pair<int,int> > > S;

bool go(string &str, int pos, bool flag, int c1, int c2)
{
    if(c1 == 0 && c2 == 0) return true;
    if(pos == size(str)) return false;
    pair<pair<int, bool>, PII> key = mp(mp(pos, flag), mp(c1,c2));
    if(S.count(key)) return false;
    S.insert(key);
    if(flag == false)
    {
        if(go(str, pos+1, false, c1-(str[pos]-'0'==d1), c2-(str[pos]-'0'==d2)))
            return true;
        for(int i=str[pos] - '0' + 1;i<10;i++)
        {
            str[pos] = i + '0';
            if(go(str, pos+1, true, c1-(str[pos]-'0'==d1), c2-(str[pos]-'0'==d2)))
                return true;
        }
        return false;
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            str[pos] = i + '0';
            if(go(str, pos+1, true, c1-(str[pos]-'0'==d1), c2-(str[pos]-'0'==d2)))
                return true;
        }
        return false;
    }
}

class FavouriteDigits 
{
public:
    long long findNext(long long N, int digit1, int count1, int digit2, int count2) 
    {		
        d1 = digit1; c1 = count1; d2 = digit2; c2 = count2;
        if(d1 > d2)
        {
            swap(d1,d2);
            swap(c1,c2);
        }
        string str;
        ostringstream ost;
        ost << N;
        str = ost.str();

        if(go(str, 0, false, c1, c2))
        {
            cout << str << endl;
            return 0;
        }
        else
        {
            cout << "make one" << endl;
            return 0;
        }
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 47LL; int Arg1 = 1; int Arg2 = 0; int Arg3 = 2; int Arg4 = 0; long long Arg5 = 47LL; verify_case(0, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 47LL; int Arg1 = 5; int Arg2 = 0; int Arg3 = 9; int Arg4 = 1; long long Arg5 = 49LL; verify_case(1, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 47LL; int Arg1 = 5; int Arg2 = 0; int Arg3 = 3; int Arg4 = 1; long long Arg5 = 53LL; verify_case(2, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 47LL; int Arg1 = 2; int Arg2 = 1; int Arg3 = 0; int Arg4 = 2; long long Arg5 = 200LL; verify_case(3, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 123456789012345LL; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; long long Arg5 = 123456789012422LL; verify_case(4, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { long long Arg0 = 92LL; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 100LL; verify_case(5, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FavouriteDigits ___test; 
    ___test.run_test(2); 
} 
// END CUT HERE
