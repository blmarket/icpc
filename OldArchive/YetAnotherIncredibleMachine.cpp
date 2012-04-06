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

class YetAnotherIncredibleMachine 
{
public:
    int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) 
    {
        sort(balls.begin(), balls.end());

        long long ret = 1;
        long long nr = 0;

        for(int i=0;i<size(platformMount);i++)
        {
            int pos = platformMount[i];
            int len = platformLength[i];

            for(int j=pos-len;j<=pos;j++)
            {
                vector<int>::iterator pos = lower_bound(balls.begin(), balls.end(), j);
                if(pos != balls.end() && *pos <= j+len) continue;
                nr = (nr + ret) % 1000000009;
            }

            ret = nr;
            nr = 0;
        }

        return ret;
    }
};


// Powered by FileEdit
