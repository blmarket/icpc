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

VI L;
int memo[60][30][30];

int go(int pos, int used, int now) {
    if(memo[pos][used][now] != -1) return memo[pos][used][now];
    if(pos == size(L)) return memo[pos][used][now] = 0;
    // now: current using window.
    int usable = 26 - used;
    if(usable < 26 && L[pos] > usable) return memo[pos][used][now] = -2; // unable to finish it.
    int nnow = max(now, min(26, L[pos]));

    int ret = -2;

    for(int i=0;i<=min(26, L[pos]);i++) { // end them here.
        int stretch = max(now - i, 0);
        int begins = max(nnow - i - stretch, 0);
        int ends = min(i, now);

        int tmp = go(pos+1, used + i, nnow - i);
        if(tmp >= 0) {
            tmp += begins * (begins + 1) / 2;
            tmp += ends * (ends - 1) / 2;
            tmp += stretch * L[pos];
            if(stretch == 0 && L[pos] > 26) {
                tmp += L[pos] - 26;
            }
            if(ret == -2 || ret > tmp) {
                // cout << pos << " " << used << " " << now << " : " << i << " = " << tmp << endl;
                ret = tmp;
            }
        }
    }

    if(ret != -2) cout << pos << " " << used << " " << now << " = " << ret << endl;
    return memo[pos][used][now] = ret;
}

class StringWeight 
{
public:
    int getMinimum(vector <int> L_)
    {
        memset(memo, -1, sizeof(memo));
        L = L_;
        return go(0, 0, 0);
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
