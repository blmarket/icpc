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

class RollingDiceDivOne 
{
public:
	long long mostLikely(vector <int> dice) 
	{
            long long sum = 0;
            sort(dice.rbegin(), dice.rend());
            int n1 = 0;
            while(size(dice) > 0 && dice.back() == 1)
            {
                n1++;
                dice.pop_back();
            }

            if(size(dice) == 0) return n1;
            if(size(dice) == 1) return n1+1;

            for(int i=1;i<size(dice);i++) sum += dice[i] - 1;

            if(dice[0] > sum + 1)
            {
                dice[0] = sum + 1;
            }
            sum += dice[0];
            return (sum + 1 + 2 * (size(dice) - 1)) / 2 + n1;
	}
	

};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
