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

class MagicalStringDiv1 
{
public:
    int getLongest(string S) 
    {		
        int ret = size(S);
        int c1 = 0;
        int maxx = 0; 
        for(int i=0;i<size(S);i++) {
            if(S[i] == '>') c1++;
            int c2 = 0;
            for(int j=i+1;j<size(S);j++) {
                if(S[j] == '<') c2++;
            }

            maxx = max(maxx, min(c1, c2));
        }
        return maxx * 2;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
