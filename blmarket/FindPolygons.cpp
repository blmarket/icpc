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
        int ret = -1;
        vector<pair<PII, int> > V;
        for(int i=1;i<5000;i++) {
            for(int j=1;j<i;j++) {
                if(i*i+j*j > L) break;
                int p1 = i*i-j*j;
                int p2 = 2*i*j;
                if(p1 > p2) swap(p1, p2);
                if(i*i*2 + 2*i*j == L) {
                    if(ret < 0 || ret > (i*i+j*j - p1)) {
                        ret = i*i+j*j - p1;
                    }
                }
                V.pb(mp(mp(p1, p2), i*i+j*j));
            }
        }
        sort(V.begin(), V.end());
        for(int i=0;i<size(V);i++) {
            int l1 = V[i].second;
            for(int j=i+1;j<size(V);j++) {
                int l2 = V[j].second;
                if(l1+l2 >= L) break;
                int dst = L - l1 - l2;
                int tmp = max(max(l1, l2), dst) - min(min(l1, l2), dst);
                if(ret >= 0 && tmp > ret) continue;

                int p1 = abs(V[i].first.first - V[j].first.first);
                int p2 = abs(V[i].first.second - V[j].first.second);
                if(p1 > p2) swap(p1, p2);
                int idx = lower_bound(V.begin(), V.end(), mp(mp(p1, p2), 0)) - V.begin();
                if(idx < size(V) && V[idx].first.first == p1 && V[idx].first.second == p2) {
                    if(V[idx].second == dst) ret = tmp;
                }

                p1 = abs(V[i].first.first + V[j].first.first);
                p2 = abs(V[i].first.second - V[j].first.second);
                if(p1 > p2) swap(p1, p2);
                idx = lower_bound(V.begin(), V.end(), mp(mp(p1, p2), 0)) - V.begin();
                if(idx < size(V) && V[idx].first.first == p1 && V[idx].first.second == p2) {
                    if (V[idx].second == dst) ret = tmp;
                }

                p1 = abs(V[i].first.first - V[j].first.first);
                p2 = abs(V[i].first.second + V[j].first.second);
                if(p1 > p2) swap(p1, p2);
                idx = lower_bound(V.begin(), V.end(), mp(mp(p1, p2), 0)) - V.begin();
                if(idx < size(V) && V[idx].first.first == p1 && V[idx].first.second == p2) {
                    if (V[idx].second == dst) ret = tmp;
                }

                p1 = abs(V[i].first.first + V[j].first.first);
                p2 = abs(V[i].first.second + V[j].first.second);
                if(p1 > p2) swap(p1, p2);
                idx = lower_bound(V.begin(), V.end(), mp(mp(p1, p2), 0)) - V.begin();
                if(idx < size(V) && V[idx].first.first == p1 && V[idx].first.second == p2) {
                    if (V[idx].second == dst) ret = tmp;
                }

                p1 = abs(V[i].first.second - V[j].first.first);
                p2 = abs(V[i].first.first - V[j].first.second);
                if(p1 > p2) swap(p1, p2);
                idx = lower_bound(V.begin(), V.end(), mp(mp(p1, p2), 0)) - V.begin();
                if(idx < size(V) && V[idx].first.first == p1 && V[idx].first.second == p2) {
                    if (V[idx].second == dst) ret = tmp;
                }

                p1 = abs(V[i].first.second + V[j].first.first);
                p2 = abs(V[i].first.first - V[j].first.second);
                if(p1 > p2) swap(p1, p2);
                idx = lower_bound(V.begin(), V.end(), mp(mp(p1, p2), 0)) - V.begin();
                if(idx < size(V) && V[idx].first.first == p1 && V[idx].first.second == p2) {
                    if (V[idx].second == dst) ret = tmp;
                }

                p1 = abs(V[i].first.second + V[j].first.first);
                p2 = abs(V[i].first.first + V[j].first.second);
                if(p1 > p2) swap(p1, p2);
                idx = lower_bound(V.begin(), V.end(), mp(mp(p1, p2), 0)) - V.begin();
                if(idx < size(V) && V[idx].first.first == p1 && V[idx].first.second == p2) {
                    if (V[idx].second == dst) ret = tmp;
                }

                p1 = abs(V[i].first.second - V[j].first.first);
                p2 = abs(V[i].first.first + V[j].first.second);
                if(p1 > p2) swap(p1, p2);
                idx = lower_bound(V.begin(), V.end(), mp(mp(p1, p2), 0)) - V.begin();
                if(idx < size(V) && V[idx].first.first == p1 && V[idx].first.second == p2) {
                    if (V[idx].second == dst) ret = tmp;
                }
            }
        }
        cout << ret << endl;
        if(ret != -1) return ret;
        if((L%4) == 0) return 0;
        if((L%2) == 0) {
            return 1.0;
        }
        return -1;
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
