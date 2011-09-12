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

long long cnt[31*31*31*31];
int group[31*31*31*31];
int tarj[31*31*31*31];
int gn;
int K;
vector<int> stack;

int check[100][4], diff[100];
int cn = 0;

long long combi(int a, int b)
{
    long long ret = 1;
    for(int i=0;i<b;i++)
    {
        ret *= (a-i);
        ret /= (b+1);
    }
    return ret;
}

long long getsize(int idx)
{
    long long ret = 1;
    int kk = K;
    while(idx)
    {
        int tmp = (idx % 31);
        ret *= combi(kk, tmp);
        cout << ret << endl;
        kk -= tmp;
        idx /= 31;
    }
    return ret;
}

bool move(int &now, int k)
{
    int tmp = now;
    for(int i=0;i<4;i++)
    {
        if( (tmp % 31) < check[k][i] ) return false;
        tmp /= 31;
    }

    now += diff[k];
    return true;
}

std::string debug(int a)
{
    ostringstream ost;
    for(int i=0;i<4;i++)
        ost << (a%31) << ",", a /= 31;
    return ost.str();
}

long long get_group(int a)
{
    cout << "get_group(" << a << endl;
    group[a] = tarj[a] = ++gn;
    stack.pb(a);

    for(int i=0;i<cn;i++)
    {
        int aa=a;
        if(move(aa,i))
        {
            if(group[aa] == 0)
            {
                get_group(aa);
                tarj[a] = min(tarj[a], tarj[aa]);
            }
            else if(group[aa] > 0)
            {
                tarj[a] = min(tarj[a], group[aa]);
            }
        }
    }

    if(group[a] == tarj[a])
    {
        long long cc = 0;
        while(group[stack.back()] != group[a])
        {
            cc += getsize(stack.back());
            cout << debug(stack.back()) << " ";
            group[stack.back()] = -group[a];
            stack.pop_back();
        }
        cc += getsize(stack.back());
        cout << debug(stack.back()) << " = " << cc << endl;

        stack.pop_back();
        cnt[group[a]] = cc;
        group[a] = -group[a];
    }
}

class ImpossibleGame 
{
public:
    long long getMinimum(int K_, vector <string> before, vector <string> after) 
    {
        K = K_;
        cn = size(before);
        for(int i=0;i<size(before);i++)
        {
            int arr[4];
            for(int j=0;j<4;j++)
            {
                int cnt = 0;
                int cnt2 = 0;
                for(int k=0;k<size(before[i]);k++)
                    if(before[i][k] == j + 'A') cnt++;
                for(int k=0;k<size(after[i]);k++)
                    if(after[i][k] == j + 'A') cnt2++;
                check[i][j] = cnt;
                arr[3-j] = cnt2 - cnt;
            }

            diff[i] = 0;
            for(int j=0;j<4;j++)
                diff[i] = (diff[i] * 31) + arr[j];
        }

        long long ret = 0;
        for(int i=0;i<=K;i++)
        {
            for(int j=0;j+i<=K;j++)
            {
                for(int k=0;i+j+k <= K;k++)
                {
                    int l = K - (i+j+k);
                    get_group(i+j*31+k*31*31+l*31*31*31);
                }
            }
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arr1[] = { "A" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "B" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "A", "A", "D" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "B", "C", "D" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; string Arr1[] = { "B", "C", "D" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "C", "D", "B" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 9LL; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; string Arr1[] = { "AABBC", "AAAADA", "AAACA", "CABAA", "AAAAAA", "BAAAA" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "AACCB", "DAAABC", "AAAAD", "ABCBA", "AABAAA", "AACAA" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 499LL; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ImpossibleGame ___test; 
    ___test.run_test(2); 
} 
// END CUT HERE
