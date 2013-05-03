#include <iostream>
#include <cstdio>
#include <cstring>
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

struct trip {
    int v[3];
    bool operator<(const trip &rhs) const {
        if(v[0] != rhs.v[0]) return v[0] < rhs.v[0];
        if(v[1] != rhs.v[1]) return v[1] < rhs.v[1];
        return v[2] < rhs.v[2];
    }
};

vector<int> ls, rs;

vector<int> split(string str) {
    istringstream sin(str);
    int tmp;
    vector<int> ret;
    while(sin >> tmp) ret.pb(tmp);
    return ret;
}

vector<PII> lrs;

map<trip, LL> cur, next;

const long long mod = 1000000007;

class WolfInZooDivOne 
{
public:
    int count(int N, vector <string> L, vector <string> R) 
    {
        string str; for(int i=0;i<size(L);i++) str += L[i];
        ls = split(str); str.clear();
        for(int i=0;i<size(R);i++) str += R[i];
        rs = split(str);

        for(int i=0;i<size(ls);i++) lrs.pb(mp(ls[i], rs[i]));
        sort(lrs.begin(), lrs.end());

        trip tmp;
        memset(&tmp, -1, sizeof(tmp));

        cur.clear();
        cur[tmp] = 1;
        for(int i=0;i<N;i++) {
            int sho = -1;
            for(int j=0;j<size(lrs);j++) if(lrs[j].first == i) {
                if(sho == -1 || sho > lrs[j].second) sho = lrs[j].second;
            }

            next.clear();
            printf("i=%d\n",i);
            foreach(it, cur) {
                trip tmp = it->first;
                if(tmp.v[0] < i) tmp.v[0] = -1;
                if(tmp.v[1] < i) tmp.v[1] = -1;
                if(tmp.v[2] < i) tmp.v[2] = -1;

                printf("%d %d %d = %d\n",tmp.v[0],tmp.v[1],tmp.v[2],it->second);
                if(sho != -1) {
                    if(tmp.v[0] >= sho || tmp.v[1] >= sho) {} 
                    else if(tmp.v[2] == -1 || tmp.v[2] > sho) tmp.v[2] = sho;
                }
                next[tmp] += it->second;
                if(tmp.v[0] != -1) continue;
                tmp.v[0] = tmp.v[1];
                tmp.v[1] = tmp.v[2];
                tmp.v[2] = -1;
                next[tmp] += it->second;
            }
            printf("\n");
            cur.swap(next);
        }

        long long ret = 0;
        foreach(it, cur) ret = (ret + it->second) % mod;
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 16; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"0 4 2 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 9 5 9"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 225; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; string Arr1[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6419882; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WolfInZooDivOne ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
