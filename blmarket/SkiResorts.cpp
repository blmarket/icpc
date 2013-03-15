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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

long long mincost[55][55];
int N;
vector<int> als, alti;
VI links[55];

class SkiResorts 
{
public:
    long long minCost(vector <string> road, vector <int> altitude) 
    {
        N = size(altitude);
        alti = altitude;
        als = altitude;
        for(int i=0;i<N;i++) {
            links[i].clear();
            for(int j=0;j<N;j++) if(road[i][j] == 'Y') links[i].pb(j);
        }
        sort(als.begin(), als.end());
        als.erase(unique(als.begin(), als.end()), als.end());

        for(int i=0;i<N;i++) {
            for(int j=0;j<size(als);j++) if(alti[i] == als[j]) { alti[i] = j; break; }
            cout << alti[i] << " ";
        }
        cout << endl;

        memset(mincost, -1, sizeof(mincost));

        priority_queue<pair<LL, PII> > Q;

        for(int i=0;i<size(als);i++) {
            mincost[0][i] = abs(als[i] - als[alti[0]]);
            cout << mincost[0][i] << " ";
            Q.push(mp(-mincost[0][i], mp(0,i)));
        }
        cout << endl;

        while(!Q.empty()) {
            int p1 = Q.top().second.first;
            int p2 = Q.top().second.second;
            LL cur = -Q.top().first;
            Q.pop();

            if(mincost[p1][p2] != cur) continue;
            for(int it=0;it<size(links[p1]);it++) {
                int i = links[p1][it];
                for(int j=0;j<=p2;j++) {
                    LL tmp = cur + abs(als[j] - als[alti[i]]);
                    if(mincost[i][j] == -1 || mincost[i][j] > tmp) {
                        mincost[i][j] = tmp;
                        Q.push(mp(-tmp, mp(i,j)));
                    }
                }
            }
        }

        long long ret = -1;
        for(int i=0;i<size(als);i++) if(mincost[N-1][i] != -1) {
            if(ret == -1 || ret > mincost[N-1][i]) ret = mincost[N-1][i];
        }
        return ret;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
