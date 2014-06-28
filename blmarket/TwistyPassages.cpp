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
#define all(x) (x).begin(), (x).end()
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }
ostream& operator<<(ostream &ost, const vector<int> &V) {
    ost << "(";
    for(int i=0;i<size(V);i++) {
        ost << V[i] << " ";
    }
    return ost << ")";
}

int n;
VI links[105];
VI label[105];
vector<PII> ls[50005];

VI get_doorsig(int s, int e) {
    int sz = size(links[e]);
    int ii = find(all(links[e]), s) - links[e].begin();

    VI ret;
    for(int i=0;i<sz;i++) {
        ret.pb(label[e][(ii+i)%sz]);
    }
    return ret;
}

VI roomsig(int s) {
    int sz = size(links[s]);
    VI ret;
    for(int i=0;i<sz;i++) {
        VI tmp; tmp.clear();
        for(int j=0;j<sz;j++) {
            tmp.pb(label[s][(i+j)%sz]);
        }
        if(ret.size() == 0 || ret > tmp) ret = tmp;
    }
    return ret;
}

class TwistyPassages 
{
public:
    vector <int> similarRooms(vector <string> maze) 
    {		
        n = size(maze);
        for(int i=0;i<n;i++) {
            istringstream sin(maze[i]);
            int tmp;
            while(sin >> tmp) {
                links[i].pb(tmp);
            }
            int sz = size(links[i]);
            label[i] = vector<int>(sz, sz);
            for(auto jt : links[i]) {
                ls[sz].pb(mp(i, jt));
            }
        }

        int mm = 55;

        while(true) {
            bool change = false;
            for(int i=0;i<mm;i++) {
                if(ls[i].size() == 0) continue;
                cout << i << " : ";
                for(int j=0;j<size(ls[i]);j++) {
                    cout << ls[i][j].first << "-" << ls[i][j].second << " ";
                }
                cout << endl;
            }

            for(int i=0;i<mm;i++) {
                if(ls[i].size() < 2) continue;
                map<VI, vector<PII> > M;
                M.clear();
                for(int j=0;j<size(ls[i]);j++) {
                    VI tmp = get_doorsig(ls[i][j].first, ls[i][j].second);
                    M[tmp].pb(ls[i][j]);
                }
                if(size(M) == 1) continue;
                change = true;
                for(auto &it : M) {
                    ls[mm] = it.second;
                    for(PII jt : it.second) {
                        int a,b;
                        tie(a,b) = jt;
                        for(int j=0;j<size(links[a]);j++) if(links[a][j] == b) {
                            label[a][j] = mm;
                        }
                    }
                    mm++;
                }
                ls[i].clear();
            }
            if(!change) break;
        }
        VVI sigs(n);
        for(int i=0;i<n;i++) sigs[i] = roomsig(i);

        vector<int> ret(n, -1);
        for(int i=0;i<n;i++) if(ret[i] == -1) {
            int cnt = 0;
            for(int j=i+1;j<n;j++) if(sigs[i] == sigs[j]) cnt++;
            for(int j=i;j<n;j++) if(sigs[j] == sigs[i]) ret[j] = cnt;
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
    ___test.run_test(-1); 
} 
// END CUT HERE
