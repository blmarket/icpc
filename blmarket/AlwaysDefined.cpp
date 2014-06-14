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

/*
 * Problem: 900
 * Test Case: 74
 * Succeeded: No
 * Execution Time: 0 ms
 * Peak memory used: 0.000MB
 * Args:
 * {52654107011850814, 744472477227325439, 2028}
 *
 * Expected:
 * 2819463395911898
 *
 * Received:
 * The code execution time exceeded the 2.000 second time limit.
 *
 * Answer checking result:
 * null
 */

map<pair<long long, int>, long long> memo;

int W;
vector<int> nr[3005];

long long go2(long long maxk, int r) {
    if(r == 1) return maxk+1;
    auto key = mp(maxk, r);
    auto it = memo.find(key);
    if(it != memo.end()) return it->second;
    long long ret = 0;
    // k W + r
    for(auto it : nr[r]) {
        if(maxk - it < 0) break;
        long long maxw = (maxk - it) / r;
        int nr = (it * W + r) / r;
        ret += go2(maxw, nr);
    }
    // cout << maxk << " " << r << " = " << ret << endl;
    return memo[key] = ret;
}

long long go(long long A) {
    long long ret = 0;
    for(int i=1;i<W;i++) {
        if(A < i) break;
        long long k = (A-i) / W;
        ret += go2(k, i);
    }
    return ret;
}

class AlwaysDefined 
{
public:
    long long countIntegers(long long L, long long R, int W_) 
    {
        memo.clear();
        W = W_;
        for(int i=1;i<W;i++) {
            nr[i].clear();
            for(int j=0;j<i;j++) {
                if((j*W+i) % i) continue;
                nr[i].pb(j);
            }
        }
        return go(R) - go(L-1);
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
