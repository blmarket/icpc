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

bool check(vector<string> &data, int s, int t)
{
    if(s == t) return true;
    vector<bool> flag(data.size(), false);
    flag[s] = true;
    queue<int> Q;
    Q.push(s);

    while(Q.empty() == false)
    {
        s = Q.front();
        Q.pop();
        for(int i=0;i<size(data[s]);i++)
        {
            if(data[s][i] == 'Y' && flag[i] == false) 
            {
                if(i == t) return true;
                flag[i]=true;
                Q.push(i);
            }
        }
    }
    return false;
}

int calc(vector<string> &data, int s, int t)
{
    cout << s << " " << t << endl;
    if(s==t) return 1;
    for(int i=0;i<size(data);i++)
    {
        if(data[s][i] == 'N') continue;
        if(check(data, i, t) == false) continue;
        cout << "path " << s << " " << i << endl;
        data[s][i] = 'N';
        int tmp = calc(data, s, t);
        if(check(data, s, i)) return tmp+1;
        return tmp + calc(data, i, t);
    }
    return 0;
}

class GogoXMarisaKirisima 
{
public:
	int solve(vector <string> choices) 
	{
            for(int i=0;i<size(choices);i++)
            {
                choices[i] += 'N';
            }
            *(choices[size(choices)-1].rbegin()) = 'Y';
            choices.push_back(string(size(choices)+1, 'N'));

            for(int i=0;i<size(choices);i++)
                cout << choices[i] << endl;
            return calc(choices, 0, size(choices)-1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN"
,"YNY"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNY"
,"YNY"
,"YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYY"
,"NNNY"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

};



// BEGIN CUT HERE 
int main() {
	GogoXMarisaKirisima ___test;
	___test.run_test(-1);
}
// END CUT HERE
