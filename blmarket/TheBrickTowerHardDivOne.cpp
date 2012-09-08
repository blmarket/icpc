#include <iostream>
#include <cstring>
#include <iterator>
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

long long mod = 1234567891LL;
int C,K,H;

vector<vector<int> > matrix;
vector<vector<int> > initial;

int stmap[4][4][4][4];
int curst = 1;

int tstate[4];

int countsame(int *arr) {
    int ret = 0;
    ret += (arr[0] == arr[1]);
    ret += (arr[0] == arr[2]);
    ret += (arr[1] == arr[3]);
    ret += (arr[2] == arr[3]);
    return ret;
}

int countPerm(int candis) {
    long long ret = 1;
    for(int i=0;i<candis;i++) {
        ret *= (C - i);
        ret %= mod;
    }
    return ret;
}

int * exstate(int *arr) {
    map<int, int> m;
    m.clear();
    for(int i=0;i<4;i++) {
        if(m.count(arr[i]) == 0)
            m[arr[i]] = m.size();
        tstate[i] = m[arr[i]];
    }
    if(arr[0] == 1 && arr[1] == 2 && arr[2] == 2 && arr[3] == 1) {
        cout << "gotcha" << endl;
        cout << m[1] << endl;
        copy(tstate, tstate+4, ostream_iterator<int>(cout," "));
    }
    return tstate;
}

int getstate(int *arr) {
    int &ret = stmap[arr[0]][arr[1]][arr[2]][arr[3]];
    if(ret == -1) {
        ret = curst++;
        int ee = *max_element(arr, arr+4) + 1;
        int p = countPerm(ee);
        int nSame = countsame(arr);
        initial[32 * nSame + ret][0] = p;
        for(int i=0;i<=K;i++) {
            matrix[0][32 * i + ret] = 1;
        }
    }
    return ret;
}

void gen(int *arr, int pos) {
    arr[pos] = -1;
    int ee = *max_element(arr, arr+pos) + 1;
    if(pos <= 1) cout << ee << endl;
    if(pos == 8) {
        int s1 = getstate(arr);
        int s2 = getstate(exstate(arr + 4));
        int p = countPerm(ee);
        int nSame = countsame(tstate);
        for(int i=0;i<4;i++) {
            if(arr[i] == tstate[i]) nSame++;
        }
        for(int i=0;i<8;i++) {
            if(i + nSame >= 8) break;
            //if(p != 0) 
            //    cout << 32 * (i + nSame) + s2 << " " << 32 * i + s1 << " " << p << endl;
            matrix[32 * (i + nSame) + s2][32 * i + s1] += p;
            matrix[32 * (i + nSame) + s2][32 * i + s1] %= mod;
        }
        return;
    }
    for(int i=0;i<=ee;i++) {
        arr[pos] = i;
        gen(arr, pos+1);
    }
}

void matmul(const VVI &a, const VVI &b, VVI &c) {
    VVI tmp(a.size(), VI(b[0].size(), 0));
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b[0].size();j++) {
            long long sum = 0;
            for(int k=0;k<b.size();k++) {
                sum += ((LL)a[i][k] * b[k][j]);
                sum %= mod;
            }
            tmp[i][j] = sum;
        }
    }
    c=tmp;
}

void matpow(LL a, VVI &out) {
    out = matrix;
    a--;
    while(a) {
        if(a & 1) {
            matmul(out, matrix, out);
        }
        matmul(matrix, matrix, matrix);
        a >>= 1;
    }
}

void debug(const VVI &matrix) {
    for(int i=0;i<size(matrix);i++) {
        for(int j=0;j<size(matrix[i]);j++) if(matrix[i][j])
            cout << i << " " << j << " = " << matrix[i][j] << endl;
    }
}

class TheBrickTowerHardDivOne 
{
public:
    int find(int C_, int K_, long long H_) 
    {
        C = C_; K = K_; H = H_;
        memset(stmap, -1, sizeof(stmap));
        matrix = vector<vector<int> >(260, vector<int>(260, 0));
        initial = vector<vector<int> >(260, vector<int>(1, 0));
        matrix[0][0] = 1;
        curst = 1;
        int arr[8];
        gen(arr, 0);
        VVI tmp;

        //debug(matrix);
        //debug(initial);

        matpow(H+1, tmp);
        matmul(tmp, initial, tmp);

        cout << stmap[0][1][1][0] << endl;
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<4;k++) for(int l=0;l<4;l++) if(stmap[i][j][k][l] == 10) cout << i << j << k << l << endl;
        return tmp[0][0];
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; long long Arg2 = 2LL; int Arg3 = 4; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 7; long long Arg2 = 19LL; int Arg3 = 1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; long long Arg2 = 1LL; int Arg3 = 14; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; long long Arg2 = 47LL; int Arg3 = 1008981254; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheBrickTowerHardDivOne ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
