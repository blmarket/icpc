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

map<string, int> makeit(const vector<string> &in)
{
    int n = size(in[0]);
    map<string, int> ret;
    for(int i=0;i<n;i++)
    {
        string tmp;
        for(int j=0;j<size(in);j++)
        {
            tmp += in[j][i];
        }
        ret[tmp]++;
    }
    return ret;
}

class SwitchesAndLamps 
{
public:
	int theMin(vector <string> switches, vector <string> lamps) 
	{
            map<string, int> m1 = makeit(switches);
            map<string, int> m2 = makeit(lamps);
            if(m1 != m2) return -1;
            int maxx = 0;
            foreach(it, m1)
            {
                maxx = max(maxx, it->second);
            }

            int ret = 0;
            while(maxx > 1)
            {
                ret++;
                maxx = (maxx + 1) / 2;
            }
            return ret;
	}
	

};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
