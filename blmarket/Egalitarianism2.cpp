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

class Egalitarianism2 
{
public:
    double minStdev(vector <int> x, vector <int> y) 
    {
        auto dist = [&](int a, int b) -> double {
            return hypot(x[a] - x[b], y[a] - y[b]);
        };
        vector<tuple<double, int, int> > V;
        int n = size(x);
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                double d = dist(i, j);
                V.pb(make_tuple(d,i,j));
            }
        }

        vector<double> ds;
        for(int i=0;i<size(V);i++) ds.pb(get<0>(V[i]));
        sort(ds.begin(), ds.end());

        auto chk = [&](double m) -> double {
            auto cmp = [&](const tuple<double, int, int> &a, const tuple<double, int, int> &b) -> bool {
                double d1 = get<0>(a);
                double d2 = get<0>(b);

                return sqr(d1 - m) < sqr(d2 - m);
            };

            int gn[55];
            sort(V.begin(), V.end(), cmp);

            for(int i=0;i<n;i++) gn[i] = i;

            function<int(int)> getg;
            getg = [&](int a) {
                if(gn[a] == a) return a;
                return gn[a] = getg(gn[a]);
            };

            double sqsum = 0;
            double sum = 0;

            for(int i=0;i<size(V);i++) {
                double d;
                int n1, n2;
                tie(d, n1, n2) = V[i];
                if(getg(n1) == getg(n2)) continue;
                gn[getg(n1)] = gn[getg(n2)];
                sqsum += d*d;
                sum += d;
            }

            cout << m << " " << sqsum << " " << sum << endl;

            double ret = sqrt(sqsum / (n-1) - sqr(sum / (n-1)));
            return ret;
        };

        double ret = 100000000;
        for(int i=0;i<size(ds);i++) {
            double tmp = chk(ds[i]);
            if(ret > tmp) ret = tmp;
            if(i+1 <size(ds)) {
                tmp = chk((ds[i] + ds[i+1]) / 2);
                if(ret > tmp) ret = tmp;
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(1, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,46,81,56}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,45,2,67}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.102799971320872; verify_case(2, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,3,9,10,15,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.9428090415820617; verify_case(3, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {167053, 536770, -590401, 507047, 350178, -274523, -584679, -766795, -664177, 267757, -291856, -765547, 604801, -682922, -404590, 468001, 607925, 503849, -499699, -798637}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-12396, -66098, -56843, 20270, 81510, -23294, 10423, 24007, -24343, -21587, -6318, -7396, -68622, 56304, -85680, -14890, -38373, -25477, -38240, 11736}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 40056.95946451678; verify_case(4, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-306880, 169480, -558404, -193925, 654444, -300247, -456420, -119436, -620920, -470018, -914272, -691256, -49418, -21054, 603373, -23656, 891691, 258986, -453793, -782940}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-77318, -632629, -344942, -361706, 191982, 349424, 676536, 166124, 291342, -268968, 188262, -537953, -70432, 156803, 166174, 345128, 58614, -671747, 508265, 92324}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 36879.1512763429; verify_case(5, Arg2, minStdev(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Egalitarianism2 ___test; 
    ___test.run_test(2); 
} 
// END CUT HERE
