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

VI ls;
VI target;
int memo[55][55];

int go(int pos,int cur)
{
    if(pos == size(target)) return 0;
    if(memo[pos][cur] != -1) return memo[pos][cur];

    int ret = 1 + go(pos+1, cur) + abs(target[pos] - ls[cur]);

    for(int i=0;i<size(ls);i++)
    {
        int tmp = abs(ls[i] - ls[cur]) + 1 + go(pos+1, i) + abs(target[pos] - ls[i]);
        if(ret > tmp) ret = tmp;
    }
    
    memo[pos][cur] = ret;
    return ret;
}

class WhiteSpaceEditing 
{
public:
    int getMinimum(vector <int> lines) 
    {		
        target = lines;
        memset(memo, -1, sizeof(memo));
        for(int i=0;i<size(lines);i++) ls.pb(lines[i]);
        ls.pb(0);
        sort(ls.begin(),ls.end());
        ls.erase(unique(ls.begin(), ls.end()), ls.end());

        return go(0,0) - 1;
    }
};


// Powered by FileEdit
