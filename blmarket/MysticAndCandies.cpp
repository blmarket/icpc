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

class MysticAndCandies 
{
public:
    int minBoxes(int C, int X, vector <int> low, vector <int> high) 
    {		
        vector<int> hs = high;
        sort(hs.begin(), hs.end());

        int elasp = C;
        int ret = size(high);
        for(int i=0;i<size(hs);i++) {
            elasp -= hs[i];
            if(elasp >= X) ret = size(high) - i - 1;
            else break;
        }

        sort(low.rbegin(), low.rend());

        int gg = 0;
        for(int i=0;i<size(low);i++) {
            gg += low[i];
            if(gg >= X) {
                if(i+1 < ret) return i+1;
                return ret;
            }
        }
        return ret;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
