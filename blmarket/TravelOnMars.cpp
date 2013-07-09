#include <iostream>
#include <cstring>
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

int N;
int mindist[55];

class TravelOnMars 
{
public:
    int minTimes(vector <int> range, int startCity, int endCity) 
    {		
        N = size(range);
        memset(mindist, -1, sizeof(mindist));
        mindist[startCity] = 0;

        queue<int> Q;
        Q.push(startCity);

        while(!Q.empty()) {
            int pos = Q.front();
            Q.pop();

            int r = range[pos];
            for(int i=-r;i<=r;i++) {
                int nn = (pos + i + N) % N;
                if(mindist[nn] == -1) {
                    mindist[nn] = mindist[pos] + 1;
                    Q.push(nn);
                }
            }
        }

        return mindist[endCity];
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
