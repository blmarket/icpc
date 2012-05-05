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

class MergersDivOne 
{
public:
	double findMaximum(vector <int> revenues) 
	{
            double ret = 0;
            sort(revenues.begin(), revenues.end());
            ret = revenues[0];
            for(int i=1;i<size(revenues);i++)
            {
                int cur = revenues[i];
                ret = (ret + cur) / 2;
                cout << ret << endl;
            }
            return ret;
	}
	

};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
