#include <iostream>
#include <cstdio>
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

pair<int,int> get(int a, int b)
{
    a = a % 360;
    b = b % 360;

    cout << a << " " << b << endl;
    int hour = a / 30;
    cout << hour << endl;

    if((b % 6) != 0) return mp(-1,-1);
    int min = b / 6;

    cout << min << endl;

    if((min % 2) != 0) return mp(-1,-1);

    int hmove = min / 2;

    if((a % 30) != hmove) return mp(-1,-1);

    return mp(hour, min);
}

class RotatedClock 
{
public:
    string getEarliest(int hourHand, int minuteHand) 
    {
        pair<int,int> ret = mp(-1,-1);
        for(int i=0;i<12;i++)
        {
            pair<int,int> tmp = get(hourHand + 30 * i, minuteHand + 30 * i);
            if(tmp == mp(-1,-1)) continue;

            cout << tmp.first << " " << tmp.second << endl;

            if(ret == mp(-1,-1) || ret > tmp) ret = tmp;
        }

        if(ret == mp(-1,-1)) return "";
        char tmpstr[20];
        sprintf(tmpstr,"%02d:%02d",ret.first,ret.second);
        return tmpstr;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 70; int Arg1 = 300; string Arg2 = "08:20"; verify_case(0, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 90; int Arg1 = 120; string Arg2 = "11:00"; verify_case(1, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 240; int Arg1 = 36; string Arg2 = ""; verify_case(2, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 19; int Arg1 = 19; string Arg2 = ""; verify_case(3, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 12; string Arg2 = "00:02"; verify_case(4, Arg2, getEarliest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RotatedClock ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
