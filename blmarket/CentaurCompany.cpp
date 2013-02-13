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

struct item {
    int head;
    int diff;
    int same;

    bool operator<(const item &rhs) const {
        if(head != rhs.head) return head < rhs.head;
        if(diff != rhs.diff) return diff < rhs.diff;
        return same < rhs.same;
    }
};

typedef map<item, long long> data;

int N;
VI a,b;

data go(int pos, int parent) {
    data ret;

    item key;
    key.head = 1;
    key.diff = -99999; key.same = -99999; // FIXME: check later
    ret[key] = 1;

    for(int i=0;i<size(a);i++) {
        if(a[i] != pos && b[i] != pos) continue;
        int oth = a[i] + b[i] - pos;
        if(oth == parent) continue;

        data tmp = go(oth, pos);

        data tmp2;
        tmp2.clear();
        foreach(it, ret) {
            foreach(jt, tmp) {
                // same head
                item tmpkey;
                tmpkey.head = it->first.head + jt->first.head;
                tmpkey.diff = it->first.diff + jt->first.diff - 1;
                if(tmpkey.diff < -90000) tmpkey.diff = it->first.diff + jt->first.diff + 99999;
                tmpkey.same = it->first.same + jt->first.same - 1;
                if(tmpkey.same < -90000) tmpkey.same = it->first.same + jt->first.same + 99999;
                tmp2[tmpkey] += it->second * jt->second;

                // diff head
                tmpkey.head = it->first.head;
                tmpkey.diff = it->first.diff + jt->first.same - 1;
                if(tmpkey.diff < -90000) tmpkey.diff = it->first.diff + jt->first.same + 99999;

                if(tmpkey.diff < -90000) tmpkey.diff = jt->first.head; 
                else tmpkey.diff += jt->first.head - 2;

                tmpkey.same = it->first.same + jt->first.diff - 1;
                if(tmpkey.same < -90000) tmpkey.same = it->first.same + jt->first.diff + 99999;
                tmp2[tmpkey] += it->second * jt->second;
            }
        }
        ret.swap(tmp2);
    }
    return ret;
}

LL brute_cur;
bool chk(int pos) {
    if(brute_cur & (1LL << pos)) return true;
    return false;
}
PII brute_dfs(int pos, int par) {
    PII ret = mp(0,0);
    if(chk(pos)) ret.second++; else ret.first++;

    for(int i=0;i<size(a);i++) {
        if(a[i] != pos && b[i] != pos) continue;
        int oth = a[i] + b[i] - pos;
        if(oth == par) continue;

        PII tmp = brute_dfs(oth, pos);
        ret.first += tmp.first;
        ret.second += tmp.second;
        if(chk(pos) != chk(oth)) {
            if(chk(pos)) ret.second-=2;
            else ret.first-=2;
        }
    }
    return ret;
}

long long brute() {
    long long dst = (1LL << N);
    long long ret = 0;
    for(long long i=0;i<dst;i++) {
        brute_cur = i << 1;
        PII tmp = brute_dfs(1, -1);
        cout << tmp.first << " : " << tmp.second << endl;
        if(tmp.first < 0) ret += -tmp.first;
        if(tmp.second < 0) ret += -tmp.second;
    }
    return ret;
}

class CentaurCompany 
{
public:
    double getvalue(vector <int> a_, vector <int> b_) 
    {
        a=a_;b=b_;
        N = size(a) + 1;

        cout << brute() << endl;

        for(int i=1;i<=N;i++) {
            int occur = 0;
            int pos = -1;
            for(int j=0;j<size(a);j++) {
                if(a[j] == i) { occur++; pos = j; }
                if(b[j] == i) { occur++; pos = j; }
            }

            if(occur == 1) {
                data ret = go(i, -1);
                long long tot = 0;
                long long need = 0;
                foreach(it, ret) {
                    int same = it->first.head;
                    if(it->first.same != -99999) same += it->first.same - 2;
                    if(same < 0) need += it->second * -same;
                    if(it->first.diff != -99999 && it->first.diff < 0) need += it->second * -it->first.diff;

                    tot += it->second;
                }
                cout << need << " / " << tot << endl;
                return (double)need / tot;
            }
        }
        return -1;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.125; verify_case(1, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.375; verify_case(2, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.41796875; verify_case(3, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 15.500000001076842; verify_case(4, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 7, 2, 5, 6, 2, 4, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 10, 10, 4, 1, 6, 2, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.646484375; verify_case(5, Arg2, getvalue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CentaurCompany ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
