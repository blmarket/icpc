#include <iostream>
#include <cmath>
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

class FindPolygons 
{
public:
    double minimumPolygon(int L) 
    {		
        set<PII> S;
        for(int i=1;i<5000;i++) {
            for(int j=1;j<i;j++) {
                if(i*i+j*j > L) break;
                int p1 = i*i-j*j;
                int p2 = 2*i*j;
                if(p1 > p2) swap(p1, p2);
                S.insert(mp(p1, p2));
            }
        }
        cout << S.size() << endl;
        return 0;
        for(int i=1;i<1600;i++) {
            int tmp = sqr(i+819) - sqr(i);
            cout << i << " " << tmp << " " << sqrt((double)tmp) << endl;
        }

        if(L%2) return -1.0;
        for(int i=1;i<=L;i++) {
            if(L % (2*i)) continue;
            cout << i << " " << L/2/i << endl;
            int ss = (L/2/i);
            cout << "tmp " << i << " " << ss << endl;
            int j = ss - i;
            if(j < 0) continue;
            cout << "so " << i << " " << j << endl;
            cout << i*i-j*j << " " << 2*i*j << " " << i*i+j*j << endl;
        }
        return 0;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; double Arg1 = 0.0; verify_case(0, Arg1, minimumPolygon(Arg0)); }
	void test_case_1() { int Arg0 = 5; double Arg1 = -1.0; verify_case(1, Arg1, minimumPolygon(Arg0)); }
	void test_case_2() { int Arg0 = 12; double Arg1 = 2.0; verify_case(2, Arg1, minimumPolygon(Arg0)); }
	void test_case_3() { int Arg0 = 4984; double Arg1 = 819.0; verify_case(3, Arg1, minimumPolygon(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FindPolygons ___test; 
    ___test.run_test(3); 
} 
// END CUT HERE
