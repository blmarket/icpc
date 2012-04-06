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

class TripleStrings 
{
public:
    int getMinimumOperations(string init, string goal) 
    {
        int len = init.size();
        for(int i=len;i>=0;i--)
        {
            if(goal.substr(0,i) == init.substr(len-i))
            {
                return (len-i)*2;
            }
        }
        return len*2;
    }
};


// Powered by FileEdit
