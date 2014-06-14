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

class BuildingHeights 
{
public:
    int minimum(vector <int> heights) 
    {		
        vector<long long> S;
        sort(heights.begin(), heights.end());
        S.pb(0);
        int n = size(heights);
        for(int i=0;i<n;i++) {
            S.pb(S.back() + heights[i]);
        }
        int ret = 0;
        for(int i=1;i<n;i++) {
            int mindiff = 1000000000;
            for(int j=0;j+i < n;j++) {
                long long sum = heights[j+i] * (i+1) - (S[j+i+1] - S[j]);
                if(sum < mindiff) mindiff = sum;
            }
            ret ^= mindiff;
        }
        return ret;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
