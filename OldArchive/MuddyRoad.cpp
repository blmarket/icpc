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

vector<int> road;
double memo[104][2];

double go(int a, bool flag)
{
    if(a >= size(road) - 2) return 0;
    double &ret = memo[a][flag];
    if(ret >= -0.5) return ret;

    double p1 = (double)road[a+1] / 100;
    double p2 = (double)road[a+2] / 100;

    if(flag)
    {
        ret = p2 * (1 + go(a+2, false)) + (1-p2) * go(a+2, false);        
    }
    else
    {
        ret = p1*p2*(1+go(a+2,false)) +
            p1*(1-p2)*(go(a+2,false)) +
            (1-p1)*p2*(go(a+1,true)) +
            (1-p1)*(1-p2)*go(a+2, false);
    }
    return ret;
}

class MuddyRoad 
{
public:
    double getExpectedValue(vector <int> road_) 
    {		
        road = road_;
        road.pb(0); road.pb(0); road.pb(0);
        for(int i=0;i<104;i++) memo[i][0] = memo[i][1] = -1;
        return go(0, false);
    }
};
