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

bool visit[31*31*31*31];
long long cnt[31*31*31*31];
long long childs[31*31*31*31];
int group[31*31*31*31];
int tarj[31*31*31*31];
int gn;
int K;
long long ret = 0;
long long combi[33][33];
vector<int> stack;

int check[100][4], diff[100];
int cn = 0;

long long getsize(int idx)
{
    long long ret = 1;

    int kk = K;
    while(idx)
    {
        int tmp = (idx % 31);
        ret *= combi[kk][tmp];
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

bool get_group(int a)
{
//    cout << "get_group(" << a << endl;
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
        vector<int> V;
        long long cc = 0;
        while(group[stack.back()] != group[a])
        {
            cc += getsize(stack.back());
//            cout << debug(stack.back()) << " ";
            group[stack.back()] = -group[a];
            V.pb(stack.back());
            stack.pop_back();
        }
        cc += getsize(stack.back());
//        cout << debug(stack.back()) << " = " << cc << endl;
        cout << cc << endl;
        V.pb(stack.back());
        stack.pop_back();
        group[a] = -group[a];

        long long maxchild = 0;
        for(int i=0;i<size(V);i++)
        {
            for(int j=0;j<cn;j++)
            {
                int aa = V[i];
                if(move(aa,j) && group[aa] != group[a])
                {
//                    cout << a << " has child " << aa << " " << childs[-group[aa]] << endl;
                    maxchild = max(maxchild, childs[-group[aa]]);
                }
            }
        }

//        cout << maxchild << endl;
        cnt[-group[a]] = cc;
        childs[-group[a]] = cc + maxchild;

        ret = max(ret, cc + maxchild);

        return true;
    }
    return false;
}

class ImpossibleGame 
{
public:
    long long getMinimum(int K_, vector <string> before, vector <string> after) 
    {
        combi[0][0]=1;
        for(int i=1;i<=30;i++)
        {
            combi[i][0] = combi[i][i] = 1;
            for(int j=1;j<i;j++)
                combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
        }

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

        for(int i=0;i<=K;i++)
        {
            for(int j=0;j+i<=K;j++)
            {
                for(int k=0;i+j+k <= K;k++)
                {
                    int l = K - (i+j+k);
                    int node = i+j*31+k*31*31+l*31*31*31;
                    if(group[node] == 0)
                        get_group(node);
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
    ___test.run_test(3); 
} 
// END CUT HERE
