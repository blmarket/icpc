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

#define MATSIZE 2
typedef double matrix[MATSIZE][MATSIZE];

template<typename T> int size(const T &a) { return a.size(); }

int m;
matrix mata, matb, matc;
string seq;

void matmul(const matrix &src1, const matrix &src2, matrix &target) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            target[i][j] = 0;
            for(int k=0;k<2;k++) {
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
        mata[0][1] = (double)(n-1) / nmoves;
        mata[0][0] = (double)(nmoves - n + 1) / nmoves;
        mata[1][0] = 1.0 / nmoves;
        mata[1][1] = (double)(nmoves - 1) / nmoves;

        memcpy(matb, mata, sizeof(matrix));
        k--;
        matrix *src = &mata, *dst = &matb, *tmp = &matc;

        while(k) {
            cout << k << endl;
            if(k&1) {
                matmul(*src, *dst, *tmp);
                swap(dst, tmp);
            }
            matmul(*src, *src, *tmp);
            swap(src, tmp);
            k>>=1;
        }

        double ret = 0;
        for(int i=0;i<n;i++) {
            int num = (seq[i] - '0');

            for(int j=0;j<n;j++) {
                double prob;
                double multiplier = (double)(j+1) * (n-j) * 2 / n / (n+1);
                if(i == j) {
                    prob = (*dst)[0][0];
                } else {
                    prob = (*dst)[0][1] / (n-1);
                }
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
	void test_case_0() { 

string Arr0[] = {"1036289617", "9", "384291788", "96335541573832682", "4", "1145886696298818414409133853", "14003669829889666632945210664529577317996900453", "82693945549422703149770409756645099919935", "63848", "54920232068520940146620831532", "7972648441263043822510844454622945596963728168", "77924812773987462545137418685572685085149", "9598902647806463326698034850", "469219720257361086076072438401", "4608219002506398", "295887240155846949391897815", "313541402779220386738561", "449204598080091286340588122261239768475745", "004580988", "64297948069966", "38", "99634652276403970661097710570754719", "0900457768474418456", "702766459586239506910468", "966801", "7190", "83", "30584", "41406007382355862157884964760302924733292", "222545775097", "33815114706414507938", "982760962164611308051945360486494228129358", "69572722063648288572177822973844324122", "283406552987622181313437819833302", "480561611800320964348782093106451343386"};


vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6491; double Arg2 = 10.0; verify_case(0, Arg2, find(Arg0, Arg1)); }
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
