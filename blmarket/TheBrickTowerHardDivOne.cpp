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
int maxstates = 16;
int C,K,H;

vector<vector<int> > matrix;
vector<vector<int> > initial;

int stmap[4][4][4][4];
int curst = 1;

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

int * exstate(int *arr, int *res) {
    map<int, int> m;
    m.clear();
    for(int i=0;i<4;i++) {
        if(m.count(arr[i]) == 0) { 
            m[arr[i]] = m.size() - 1;
        }
        res[i] = m[arr[i]];
    }
    return res;
}

void try_rotate(int *arr) {
    int tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = arr[3];
    arr[3] = arr[2];
    arr[2] = tmp;
}

int getstate(int *arr) {
    bool original = false;
    int &ret = stmap[arr[0]][arr[1]][arr[2]][arr[3]];
    if(ret == -1) {
        int tmparr[4];
        memcpy(tmparr, arr, sizeof(tmparr));

        for(int i=0;i<3;i++) {
            int tstate[4];
            try_rotate(tmparr);
            exstate(tmparr, tstate);
            int tmp = stmap[tstate[0]][tstate[1]][tstate[2]][tstate[3]];
            if(tmp != -1) {
                cout << arr[0] << arr[1] << arr[2] << arr[3] << " = " << tmp << endl;
                ret = tmp;
                break;
            }
        }

        if(ret == -1) {
            original = true;
            ret = curst++;
        }
        int ee = *max_element(arr, arr+4) + 1;
        int p = countPerm(ee);
        int nSame = countsame(arr);
        
        long long tmp = initial[maxstates * nSame + ret][0];
        tmp += p;
        tmp %= mod;
        initial[maxstates * nSame + ret][0] = tmp;
        for(int i=0;i<=K;i++) {
            matrix[0][maxstates * i + ret] = 1;
        }
    }
    if(!original) return -ret;
    return ret;
}

void gen(int *arr, int pos) {
    arr[pos] = -1;
    int ee = *max_element(arr, arr+pos) + 1;
    if(pos == 8) {
        int ee2 = *max_element(arr, arr+4) + 1;

        int p = countPerm(ee);
        if(p == 0)
            return;
        p /= countPerm(ee2);

        int s1 = getstate(arr);
        if(s1 < 0) return;

        int tstate[4];
        int s2 = abs(getstate(exstate(arr + 4, tstate)));
        int nSame = countsame(arr + 4);

        for(int i=0;i<4;i++) {
            if(arr[i] == arr[i + 4]) nSame++;
        }
        for(int i=0;i<8;i++) {
            if(i + nSame >= 8) break;
            //if(p != 0) 
            //    cout << maxstates * (i + nSame) + s2 << " " << maxstates * i + s1 << " " << p << endl;
            matrix[maxstates * (i + nSame) + s2][maxstates * i + s1] += p;
            matrix[maxstates * (i + nSame) + s2][maxstates * i + s1] %= mod;
        }
        return;
    }
    for(int i=0;i<=ee;i++) {
        arr[pos] = i;
        gen(arr, pos+1);
    }
}

void matmul(const VVI &a, const VVI &b, VVI &c) {
    c.resize(a.size());
    for(int i=0;i<a.size();i++) {
        c[i].resize(b[0].size());
        for(int j=0;j<b[0].size();j++) {
            long long sum = 0;
            for(int k=0;k<b.size();k++) {
                sum += ((LL)a[i][k] * b[k][j]);
                sum %= mod;
            }
            c[i][j] = sum;
        }
    }
}

void matpow(LL a, VVI &out) {
    VVI tmp;
    out = matrix;
    a--;
    while(a) {
        if(a & 1) {
            matmul(out, matrix, tmp);
            out.swap(tmp);
        }
        matmul(matrix, matrix, tmp);
        matrix.swap(tmp);
        a >>= 1;
        cout << a << endl;
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
        matrix = vector<vector<int> >(maxstates * 8, vector<int>(maxstates * 8, 0));
        initial = vector<vector<int> >(maxstates * 8, vector<int>(1, 0));
        matrix[0][0] = 1;
        curst = 1;
        int arr[8];
        gen(arr, 0);
        VVI tmp;

        //debug(matrix);

        cout << " here?" << endl;
        matpow(H, tmp);
        cout << " here?" << endl;
        matmul(tmp, initial, matrix);

        return matrix[0][0];
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
    ___test.run_test(-1); 
} 
// END CUT HERE
