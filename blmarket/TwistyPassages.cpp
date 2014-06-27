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

int n;
vector<int> rr[55];
char diff[55][55][55][55];

void add_diff(int s1, int e1, int s2, int e2) {
    if(diff[s1][e1][s2][e2]) return;
    diff[s1][e1][s2][e2] = 1;
    if(rr[s1].size() != rr[s2].size()) return;

    int p1 = find(rr[s1].begin(), rr[s1].end(), e1) - rr[s1].begin();
    int p2 = find(rr[s2].begin(), rr[s2].end(), e2) - rr[s2].begin();

    int sz = size(rr[s1]);
    for(int i=1;i<sz;i++) {
        int pp1 = rr[s1][(p1 + i) % sz];
        int pp2 = rr[s2][(p2 + i) % sz];
        add_diff(pp1, s1, pp2, s2);
    }
}

bool check_diff(int a, int b) {
    int sz = size(rr[a]);
    for(int i=0;i<sz;i++) {
        bool same = true;
        for(int j=0;j<sz;j++) {
            int n1 = rr[a][j];
            int n2 = rr[b][(i+j)%sz];
            if(diff[a][n1][b][n2]) { same = false; break; }
        }
        if(same) return true;
    }
    return false;
}

class TwistyPassages 
{
public:
    vector <int> similarRooms(vector <string> maze) 
    {		
        memset(diff, 0, sizeof(diff));
        n = size(maze);
        for(int i=0;i<n;i++) {
            rr[i].clear();
            istringstream sin(maze[i]);
            int tmp;
            while(sin >> tmp) {
                rr[i].pb(tmp);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(rr[i].size() == rr[j].size()) continue;
                for(auto a: rr[i]) {
                    for(auto b: rr[j]) {
                        add_diff(a, i, b, j);
                        add_diff(b, j, a, i);
                    }
                }
            }
        }

        bool chk[105];
        memset(chk, 0, sizeof(chk));

        vector<int> ret(n, 0);

        bool none = true;
        for(int i=0;i<n;i++) if(!chk[i]) {
            chk[i] = true;
            vector<int> V;
            V.pb(i);
            for(int j=i+1;j<n;j++) if(!chk[j]) {
                if(rr[i].size() != rr[j].size()) continue;
                if(check_diff(i, j)) {
                    V.pb(j);
                    chk[j] = true;
                    continue;
                }
            }
            for(int j=0;j<size(V);j++) {
                ret[V[j]] = size(V) - 1;
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 3", "0", "0", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, similarRooms(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 2 3", "0", "0", "0 4", "3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, similarRooms(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 2 3", "0", "0", "0 4", "3",
 "6 7 8", "5", "5", "5 9", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, similarRooms(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 2 3 4",  "0", "0 5",  "0", "6 0",  "2", "4",
"8 10 9 11", "7", "7 12", "7", "13 7", "9", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, similarRooms(Arg0)); }
	void test_case_4() { string Arr0[] = {"1 2", "2 0", "0 1", "4 6", "5 3", "6 4", "3 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 6, 6, 6, 6, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, similarRooms(Arg0)); }
	void test_case_5() { string Arr0[] = {"1 2 3", "4 5 0", "6 7 0", "8 9 0", "10 11 1", "12 13 1", 
 "14 15 2", "16 17 2", "18 19 3", "20 21 3", "22 23 4", 
 "24 25 4", "26 27 5", "28 29 5", "30 31 6", "32 33 6", 
 "34 35 7", "36 37 7", "38 39 8", "40 41 8", "42 43 9", 
 "44 45 9", "10", "10", "11", "11", "12", "12", "13", "13",
 "14", "14", "15", "15", "16", "16", "17", "17", "18", "18",
 "19", "19", "20", "20", "21", "21"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, similarRooms(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TwistyPassages ___test; 
    ___test.run_test(4); 
} 
// END CUT HERE
