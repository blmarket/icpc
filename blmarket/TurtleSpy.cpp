#include <iostream>
#include <cstring>
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

vector<int> degs;
int F = 0, B = 0;

class TurtleSpy 
{
public:
    double maxDistance(vector <string> commands) 
    {
        for(int i=0;i<size(commands);i++) {
            string a;
            int b;
            istringstream sin(commands[i]);
            sin >> a >> b;
            if(a == "right") {
                degs.pb(b);
            } else if(a == "left") {
                degs.pb(-b);
            } else if(a == "forward") {
                F += b;
            } else {
                B += b;
            }
        }

        bool avail[360] = {0};
        avail[0] = true;
        for(int i=0;i<size(degs);i++) {
            bool nex[360];
            memset(nex, 0, sizeof(nex));
            for(int j=0;j<360;j++) if(avail[j]) {
                nex[j] = true;
                int jj = (j + degs[i] + 360) % 360;
                nex[jj] = true;
            }
            memcpy(avail, nex, sizeof(nex));
        }

        int mdiff = 180;
        for(int i=0;i<360;i++) if(avail[i]) {
            int dd = abs(180 - i);
            if(mdiff > dd) mdiff = dd;
        }

        double D = (double)mdiff / 180 * 3.1415926535;

        cout << F << " " << B << " " << D << endl;

        double xx = F + B * cos(D);
        double yy = B * sin(D);

        return hypot(xx,yy);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"forward 100", "backward 100", "left 90" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 141.4213562373095; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 40.58520737741619; verify_case(2, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TurtleSpy ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
