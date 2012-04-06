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

map<int,int> M;

class ColorfulRabbits 
{
public:
    int getMinimum(vector <int> replies) 
    {		
        int ret = 0;
        for(int i=0;i<size(replies);i++) M[replies[i]]++;
        foreach(it, M)
        {
            while(it->second > 0)
            {
                ret += (it->first + 1);
                it->second -= it->first+1;
            }
        }
        return ret;
    }
};


// Powered by FileEdit
