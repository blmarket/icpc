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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

vector<int> alts;
vector<int> altitude;
vector<string> road;

map<PII, long long> mins;

class SkiResorts 
{
public:
    long long minCost(vector <string> road_, vector <int> altitude_) 
    {
        road = road_;
        altitude = altitude_;
        mins.clear();
        alts = altitude;
        sort(alts.begin(), alts.end());
        alts.erase(unique(alts.begin(), alts.end()), alts.end());
        for(int i=0;i<size(altitude);i++) {
            for(int j=0;j<size(alts);j++) {
                if(alts[j] == altitude[i]) {
                    altitude[i] = j;
                    break;
                }
            }
        }

        priority_queue<pair<LL, PII> > Q;
        for(int i=0;i<size(alts);i++) {
            int cur = alts[altitude[0]];
            int tgt = alts[i];
            int diff = abs(cur - tgt);

            mins[mp(0,i)] = diff;
            Q.push(mp(-diff, mp(0, i)));
        }

        while(!Q.empty()) {
            long long curcost = -Q.top().first;
            int curpos = Q.top().second.first;
            int curalt = Q.top().second.second;
            PII key = Q.top().second;

            Q.pop();
            if(mins[key] != curcost) continue;

            for(int i=0;i<size(road);i++) {
                if(road[curpos][i] == 'Y') {
                    for(int j=0;j<=curalt;j++) {
                        PII key = mp(i, j);
                        int diff = abs(alts[j] - alts[altitude[i]]);
                        long long ncost = curcost + diff;
                        if(mins.count(key) == 0 || mins[key] > ncost) {
                            mins[key] = ncost;
                            Q.push(mp(-ncost, key));
                        }
                    }
                }
            }
        }

        long long mincost = -1;
        for(int i=0;i<size(alts);i++) {
            PII key = mp(size(road)-1, i);
            if(mins.count(key) == 0) continue;
            if(mincost < 0 || mins[key] < mincost) mincost = mins[key];
        }
        return mincost;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 20, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(0, Arg2, minCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(1, Arg2, minCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYN",
 "YNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {573, 573, 573}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(2, Arg2, minCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 12LL; verify_case(3, Arg2, minCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SkiResorts ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
