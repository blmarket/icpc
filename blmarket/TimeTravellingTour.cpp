#include <iostream>
#include <cstring>
#include <iterator>
#include <queue>
#include <cstdio>
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

int mindist[55][55];
int N;
vector<int> cities;

long long memo[55][55][55];

LL go(int pos,int s,int e)
{
    if(s==e) return 0;
    int tt = cities[s];
    if(s+1 == e) return mindist[pos][tt];
    if(mindist[pos][tt] == -1) return -1;
    LL &r = memo[pos][s][e];
    if(r != -1) return r;

    for(int i=0;i<N;i++) if(mindist[s][i] != -1)
    {
        for(int j=s+1;j<=e;j++)
        {
            long long tmp = mindist[s][i] + go(i, s, j) + go(i, j, e);
            if(r == -1 || r > tmp)
                r = tmp;
        }
    }
    return r;
}

class TimeTravellingTour 
{
public:
    long long determineCost(int N_, vector <int> cities_, vector <string> roads) 
    {		
        memset(memo, -1, sizeof(memo));
        N = N_;
        for(int i=0;i<N;i++)
            mindist[i][i]=0;
        cities = cities_;
        memset(mindist, -1, sizeof(mindist));
        string rr;
        for(int i=0;i<size(roads);i++) rr += roads[i];
        istringstream sin(rr);
        string tmp;
        while(sin >> tmp)
        {
            int a,b,c;
            sscanf(tmp.c_str(),"%d,%d,%d",&a,&b,&c);
            if(mindist[a][b] != -1 && mindist[a][b] < c) continue;
            mindist[a][b] = mindist[b][a] = c;
        }

        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++) if(mindist[i][k] != -1)
                for(int j=0;j<N;j++) if(mindist[k][j] != -1)
                {
                    if(mindist[i][j] == -1 || mindist[i][j] > mindist[i][k] + mindist[k][j])
                    {
                        mindist[i][j] = mindist[i][k] + mindist[k][j];
                    }
                }
        cerr << go(1,1,3) << endl;
        cerr << go(1,1,2) << " " << go(1,2,3) << endl;
        return -1;
        cerr << go(0,0,3) << endl;
        cerr << " " << go(1,0,1) << " " << go(1,1,3) << endl;
        cerr << "  " << go(1,1,2) << " " << go(1,2,3) << endl;
        cerr << go(0,3,4) << endl;

        return go(0, 0, size(cities));
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {2,3,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,2,4 0,1,2 2,1,2 1,3,3 4,0,4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 13LL; verify_case(0, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,2,1"," 2",",1,5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(1, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,1,2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -1LL; verify_case(2, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {4, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,1,5 0,2,5 0,5,2 2,3,5 2,4,2 3,4,4 3,5,1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 19LL; verify_case(3, Arg3, determineCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TimeTravellingTour ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
