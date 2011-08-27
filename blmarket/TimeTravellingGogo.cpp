#include <iostream>
#include <cstdio>
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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

vector<PII> sun;
long long mindist[22][22];
int N;
LL mst;

map<pair<int,int>, LL> memo;

bool check_update(priority_queue<pair<LL, PII> > &Q, PII key, LL tot)
{
    if(memo.count(key) == 0)
    {
        memo[key] = tot;
        Q.push(mp(-tot, key));
        return true;
    }
    LL &tt = memo[key];
    if(tt > tot)
    {
        tt = tot;
        Q.push(mp(-tot, key));
        return true;
    }
    return false;
}

class TimeTravellingGogo 
{
public:
    long long determineTime(int N_, vector <int> sunnyStart, vector <int> sunnyEnd, vector <string> roads, int machineStartTime) 
    {		
        mst = machineStartTime;
        N = N_;

        sun.clear();
        for(int i=0;i<size(sunnyStart);i++)
            sun.pb(mp(sunnyStart[i], sunnyEnd[i]));

        string rr;
        for(int i=0;i<size(roads);i++) rr += roads[i];

        memset(mindist, -1, sizeof(mindist));
        for(int i=0;i<N;i++)
            mindist[i][i] = 0;

        istringstream sin(rr);
        string tmp;
        while(sin >> tmp)
        {
            int a,b,c;
            sscanf(tmp.c_str(),"%d,%d,%d",&a,&b,&c);
            if(mindist[a][b] == -1 || mindist[a][b] > c)
                mindist[a][b] = mindist[b][a] = c;
        }

        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++) if(mindist[i][k] != -1)
                for(int j=0;j<N;j++) if(mindist[k][j] != -1)
                {
                    if(mindist[i][j] == -1 || mindist[i][j] > mindist[i][k] + mindist[k][j])
                        mindist[i][j] = mindist[i][k] + mindist[k][j];
                }

        if(mindist[0][N-1] == -1) return -1;

        memo.clear();
        memo[mp(0,0)] = 0;

        priority_queue<pair<LL, PII> > Q;
        Q.push(mp(0, mp(0,0)));

        LL ret = -1;

        while(Q.empty() == false)
        {
            LL tt = -Q.top().first;
            int pos = Q.top().second.first;
            int lt = Q.top().second.second;
            Q.pop();

            if(memo[mp(pos,lt)] != tt) continue;

            cout << pos << " " << lt << " " << tt << endl;

            if(pos == N-1)
            {
                if(ret < 0 || ret > tt)
                    ret = tt;
                break;
            }

            for(int i=0;i<size(sun);i++)
            {
                int tdiff = sun[i].second - sun[i].first;
                for(int j=0;j<N;j++)
                {
                    if(mindist[pos][j] == -1 || mindist[pos][j] > tdiff)
                        continue;
                    int targettime = sun[i].second - mindist[pos][j];
                    if(targettime < lt)
                    {
                        LL tmp = tt + mst + (lt - targettime) + mindist[pos][j];
                        if(check_update(Q, mp(j, sun[i].second), tmp))
                            ;//cout << "... rmoves to " << j << " " << sun[i].second << " " << tmp << endl;
                        tmp = tt + mst + (lt - sun[i].first) + mindist[pos][j];
                        if(check_update(Q, mp(j, sun[i].first + mindist[pos][j]), tmp))
                            ;//cout << "... rmoves to " << j << " " << sun[i].first + mindist[pos][j] << " " << tmp << endl;
                    }
                    else
                    {
                        LL tmp = tt;
                        int llt = lt;
                        if(llt < sun[i].first)
                        {
                            tmp += (sun[i].first - llt);
                            llt = sun[i].first;
                        }
                        tmp += mindist[pos][j];
                        llt += mindist[pos][j];
                        if(check_update(Q, mp(j, llt), tmp))
                            ;//cout << "... moves to " << j << " " << llt << " " << tmp << endl;
                    }
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
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0,1,3 1,2,3"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; long long Arg5 = 9LL; verify_case(0, Arg5, determineTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0,1,3 1,2,4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 18; long long Arg5 = 12LL; verify_case(1, Arg5, determineTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0,1,2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; long long Arg5 = -1LL; verify_case(2, Arg5, determineTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {0,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,37}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0,1,1","5"," 1,2,12 2,0,17"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; long long Arg5 = 29LL; verify_case(3, Arg5, determineTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TimeTravellingGogo ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
