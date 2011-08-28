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

template<typename T> int size(const T &a) { return a.size(); }

double score[2][100005];

class AlternatingLane 
{
public:
    double expectedBeauty(vector <int> low, vector <int> high) 
    {		
        if(size(low) == 1) return 0;
        memset(score, 0, sizeof(score));

        double ret;
        for(int i=1;i<size(low);i++)
        {
            int prev = (i+1)%2;
            int cur = (i%2);

            memset(score[cur], 0 ,sizeof(score[0]));

            double accum = 0;
            for(int j=low[i-1];j<=high[i-1];j++)
            {
                accum += score[prev][j];
            }

            for(int k=low[i];k<=high[i];k++)
            {
                score[cur][k] = accum;

                int d2 = k - low[i-1];
                int d1 = k - high[i-1];

                if(d1 < 0 && d2 > 0)
                {
                    score[cur][k] += (d2*(d2+1)/2);
                    d1*=-1;
                    score[cur][k] += (d1*(d1+1)/2);
                }
                else
                {
                    d1 = abs(d1);
                    d2 = abs(d2);
                    if(d1 > d2) swap(d1,d2);
                    score[cur][k] += (d2*(d2+1)/2) - (d1*(d1+1)/2);
                }
            }

            ret = 0;
            for(int k=low[i];k<=high[i];k++)
            {
                score[cur][k] /= high[i-1] - low[i-1] + 1;
                ret += score[cur][k];
                cerr << score[cur][k] << " ";
            }
        }

        return ret / (high.back() - low.back() + 1);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3, 5, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 6, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(2, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4, 3, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.171428571428572; verify_case(3, Arg2, expectedBeauty(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AlternatingLane ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
