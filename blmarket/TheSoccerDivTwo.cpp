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

class TheSoccerDivTwo 
{
public:
    int find(vector <int> points) 
    {		
        int myp = points[0] + 3;
        swap(points[0], points.back()); points.pop_back();
        sort(points.rbegin(), points.rend());

        for(int i=0;i<size(points);i++)
            cerr << points[i] << ", ";
        cerr << endl;

        for(int i=0;i<size(points);i++)
        {
            if(points[i] > myp) continue;
            int wincount = 1 + i;
            int drawcount = 0, losecount = 0;
            for(int j=i;j<size(points);j++)
            {
                if(points[j] + 1 > myp)
                    losecount++;
                else if(points[j] + 3 > myp)
                    drawcount++;
            }
            cerr << i << " : " << wincount << " " << losecount << " " << drawcount << endl;
            if(losecount > wincount) continue;
            if((drawcount % 2) == 1)
            {
                if(losecount + 1 > wincount) continue;
            }
            return i+1;
        }
        return size(points) + 1;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 7, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {5, 9, 11, 9, 10, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 1, 3, 7, 6, 5, 3, 4, 2, 6, 5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheSoccerDivTwo ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
