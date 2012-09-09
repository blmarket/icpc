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
long long cut = mod * mod;
int maxstates = 15;
#define N 120
int C,K;
long long H;

struct mat {
    int data[N+1][N+1];
};

mat * matmul(mat *m1, mat *m2, mat *tmp) 
{
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) {
            long long sum = 0;
            for(int k=0;k<=N;k++) {
                sum += ((LL)m1->data[i][k]) * m2->data[k][j];
                if(sum >= cut) sum -= cut;
            }
            sum %= mod;
            tmp->data[i][j] = sum;
        }
    }

    return tmp;
}

mat *matrix = new mat(), *initial = new mat(), *tmpmatrix = new mat();

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
    int &ret = stmap[arr[0]][arr[1]][arr[2]][arr[3]];
    if(ret == -1) {
        int tmparr[4];
        memcpy(tmparr, arr, sizeof(tmparr));

        //for(int i=0;i<3;i++) {
        //    int tstate[4];
        //    try_rotate(tmparr);
        //    exstate(tmparr, tstate);
        //    int tmp = stmap[tstate[0]][tstate[1]][tstate[2]][tstate[3]];
        //    if(tmp != -1) {
        //        cout << arr[0] << arr[1] << arr[2] << arr[3] << " = " << tmp << endl;
        //        ret = tmp;
        //        break;
        //    }
        //}

        if(ret == -1) {
            ret = curst++;
        }
        int ee = *max_element(arr, arr+4) + 1;
        int p = countPerm(ee);
        int nSame = countsame(arr);
        
        long long tmp = initial->data[maxstates * nSame + ret][0];
        tmp += p;
        tmp %= mod;
        initial->data[maxstates * nSame + ret][0] = tmp;
        for(int i=0;i<=K;i++) {
            matrix->data[N][maxstates * i + ret] = 1;
        }
    }
    return ret;
}

void gen(int *arr, int pos) {
    arr[pos] = -1;
    int ee = *max_element(arr, arr+pos) + 1;
    if(pos == 8) {
        int ee2 = *max_element(arr, arr+4) + 1;

        if(ee > C) return;

        long long p = 1;
        for(int i=ee2;i<ee;i++) {
            p *= (C - i);
            p %= mod;
        }

        /*
        int p = countPerm(ee);
        if(p == 0)
            return;
        p /= countPerm(ee2);
        */

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
            long long tmp = p;
            tmp += matrix->data[maxstates * (i + nSame) + s2][maxstates * i + s1];
            tmp %= mod;
            matrix->data[maxstates * (i + nSame) + s2][maxstates * i + s1] = tmp;
        }
        return;
    }
    for(int i=0;i<=ee;i++) {
        arr[pos] = i;
        gen(arr, pos+1);
    }
}

mat * matpow(LL a) {
    mat *result = new mat();
    memcpy(result->data, matrix->data, sizeof(matrix->data));
    a--;

    while(a) {
        if(a & 1) {
            matmul(result, matrix, tmpmatrix);
            swap(result, tmpmatrix);
        }
        matmul(matrix, matrix, tmpmatrix);
        swap(matrix, tmpmatrix);
        a >>= 1;
        cout << a << endl;
    }

    return result;
}

void debug(mat *matrix) {
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=N;j++) cout << matrix->data[i][j] << " ";
        cout << endl;
    }
}

class TheBrickTowerHardDivOne 
{
public:
    int find(int C_, int K_, long long H_) 
    {
        C = C_; K = K_; H = H_;
        memset(stmap, -1, sizeof(stmap));
        memset(matrix->data, 0, sizeof(matrix->data));
        memset(initial->data, 0, sizeof(initial->data));
        matrix->data[N][N] = 1;
        curst = 0;
        int arr[8];
        gen(arr, 0);

        debug(matrix);

        //debug(matrix);
        //debug(initial);

        cout << curst << endl;
        mat* tmp = matpow(H);
        matmul(tmp, initial, matrix);

        return matrix->data[N][0];
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
    //___test.run_test(-1); 
    cout << ___test.find(2027, 6, 133181695103836835LL) << endl;
} 
// END CUT HERE
