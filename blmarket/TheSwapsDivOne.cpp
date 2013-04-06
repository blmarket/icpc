#include <iostream>
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

typedef double matrix[1110][1110];

template<typename T> int size(const T &a) { return a.size(); }

int m;
matrix mata, matb, matc;
string seq;

void matmul(const matrix &src1, const matrix &src2, matrix &target) {
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            target[i][j] = 0;
            for(int k=0;k<m;k++) {
                target[i][j] += src1[i][k] * src2[k][j];
            }
        }
    }
}

class TheSwapsDivOne 
{
public:
    double find(vector <string> sequence, int k) 
    {
        seq.clear(); for(int i=0;i<size(sequence);i++) seq += sequence[i];
        int n = size(seq);
        m = (n+1) / 2;

        int nmoves = n * (n-1) / 2;
        for(int i=0;i<m;i++) {
            int elasp = nmoves;
            for(int j=0;j<m;j++) if(i != j) {
                int np1 = 2;
                if(n-1-j == j) np1 = 1;
                elasp -= np1;
                mata[i][j] = (double)np1;
            }
            mata[i][i] = (double)elasp;

            for(int j=0;j<m;j++) {
                cout << mata[i][j] << " ";
            }
            cout << endl;
        }
        memcpy(matb, mata, sizeof(matrix));
        k--;
        matrix *src = &mata, *dst = &matb, *tmp = &matc;

        while(k) {
            if(k&1) {
                matmul(*src, *dst, *tmp);
                swap(*dst, *tmp);
            }
            matmul(*src, *src, *tmp);
            swap(*src, *tmp);
            k>>=1;
        }

        double ret = 0;
        for(int i=0;i<m;i++) {
            int num = (seq[i]-'0') + (seq[n-1-i]-'0');
            if(n-1-i == i) num = seq[i] - '0';
            cout << i << " " << num << endl;

            for(int j=0;j<m;j++) {
                double &prob = *dst[i][j];
                double multiplier = (double)(j+1) * (n-j) * 2 / n / (n+1);
                cout << j << ":" << prob << " " << num*prob << endl;
                ret += num * prob * multiplier;
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4", "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 10.0; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"4", "77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; double Arg2 = 10.0; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1", "1", "1", "1", "1", "1", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; double Arg2 = 3.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; double Arg2 = 98.3238536775161; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheSwapsDivOne ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
