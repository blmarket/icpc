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

vector<int> g, a;

bool chk(int aa) {
    if(aa < 1 || aa > 1000000000) return false;
    for(int i=0;i<size(g);i++) {
        int tmp = abs(g[i] - aa);
        if(tmp != a[i]) return false;
    }
    return true;
}

class EllysNumberGuessing 
{
public:
    int getNumber(vector <int> guesses, vector <int> answers) 
    {
        g = guesses;
        a = answers;
        bool chk1 = chk(g[0] - a[0]);
        bool chk2 = chk(g[0] + a[0]);
        
        if(!chk1 && !chk2) return -2;
        if(chk1 && chk2) return -1;
        if(chk1) return g[0] - a[0];
        return g[0] + a[0];
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
