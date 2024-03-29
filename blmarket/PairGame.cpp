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

set<PII> S;

int go(int a, int b) {
    if(S.count(mp(a,b))) return a+b;
    if(a == b) {
        return -1;
    }
    if(a > b) {
        return go(a-b, b);
    } else {
        return go(a, b-a);
    }
}

class PairGame 
{
public:
    int maxSum(int a, int b, int c, int d) 
    {
        S.insert(mp(a,b));
        while(a && b && a!=b) {
            if(a<b) {
                b -= a;
            } else {
                a -= b;
            }
            S.insert(mp(a,b));
        }
        if(a==b) {
            S.insert(mp(a,0));
            S.insert(mp(0,a));
        }

        if(S.count(mp(c,d))) return c+d;
        while(c != d) {
            if(c > d) {
                c -= d;
            } else {
                d -= c;
            }
            if(S.count(mp(c,d))) return c+d;
        }
        return -1;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
