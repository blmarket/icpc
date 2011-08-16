#include <iostream>
#include <queue>
#include <set>
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

bool check(const string &a, int b)
{
    char tmp[1024];
    int tmp2;
    sscanf(a.c_str()+2, "%s %d", tmp, &tmp2);
    string tt = tmp;

    if(tt == "<=") return b <= tmp2*2;
    if(tt == "<") return b < tmp2*2;
    if(tt == "=") return b == tmp2*2;
    if(tt == ">") return b > tmp2*2;
    if(tt == ">=") return b >= tmp2*2;

    return false;
}

class Inequalities 
{
public:
    int maximumSubset(vector <string> inequalities) 
    {		
        int maxcnt = 0;
        for(int i=-1;i<=2001;i++)
        {
            int cnt = 0;
            for(int j=0;j<size(inequalities);j++)
                if(check(inequalities[j], i)) cnt++;

            if(maxcnt < cnt) maxcnt = cnt;
        }
        return maxcnt;
    }
};
