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
int dist[55][55];

int memo[55][1<<17];

int sn;
int s1[55], s2[55], s3[55];

class TravellingPurchasingMan 
{
public:
    int maxStores(int N_, vector <string> interestingStores, vector <string> roads) 
    {		
        sn = size(interestingStores);
        for(int i=0;i<sn;i++) {
            istringstream sin(interestingStores[i]);
            sin >> s1[i] >> s2[i] >> s3[i];
        }
        N = N_;

        memset(dist, -1, sizeof(dist));
        for(int i=0;i<size(roads);i++) {
            int a,b,t;
            istringstream sin(roads[i]);
            sin >> a >> b >> t;
            if(dist[a][b] != -1 && dist[a][b] < t) continue;
            dist[a][b] = dist[b][a] = t;
        }

        for(int k=0;k<N;k++) {
            for(int i=0;i<N;i++) if(dist[i][k] != -1) {
                for(int j=0;j<N;j++) if(dist[k][j] != -1) {
                    if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        memset(memo, -1, sizeof(memo));
        memo[N-1][0] = 0;

        priority_queue<pair<int, PII> > Q;
        Q.push(mp(0, mp(N-1, 0)));

        int ret = 0;
        while(!Q.empty()) {
            int time = -Q.top().first;
            int pos = Q.top().second.first;
            int mask = Q.top().second.second;
            Q.pop();
            if(memo[pos][mask] != time) continue;

            { 
                int tmp = mask, tmp2 = 0;
                while(tmp) { 
                    tmp2 += (tmp & 1);
                    tmp >>= 1;
                }
                if(ret < tmp2) ret = tmp2;
            }

            if(pos < sn && time <= s2[pos] && ((mask & (1<<pos)) == 0)) {
                int ntime = max(time, s1[pos]) + s3[pos];
                int nmask = mask | (1<<pos);
                if(memo[pos][nmask] == -1 || memo[pos][nmask] > ntime) {
                    memo[pos][nmask] = ntime;
                    Q.push(mp(-ntime, mp(pos, nmask)));
                }
            }

            for(int i=0;i<sn;i++) if((mask & (1<<i)) == 0) if(dist[pos][i] != -1) {
                int ntime = time + dist[pos][i];
                if(memo[i][mask] == -1 || memo[i][mask] > ntime) {
                    memo[i][mask] = ntime;
                    Q.push(mp(-ntime, mp(i, mask)));
                }
            }
        }
        return ret;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
