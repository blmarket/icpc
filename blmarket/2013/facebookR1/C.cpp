#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
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

int W,H,P,Q,N,X,Y,A,B,C,D;
vector<PII> data;

void process(int ID) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d",&W,&H,&P,&Q,&N,&X,&Y,&A,&B,&C,&D);
    data.pb(mp(X,Y));
    for(int i=1;i<N;i++) {
        int x = data[i-1].first;
        int y = data[i-1].second;
        int xx = (x * A + y * B + 1) % W;
        int yy = (x * C + y * D + 1) % H;
        data.pb(mp(xx,yy));
    }

    sort(data.begin(), data.end());
    if(ID == 5) {
        for(int i=0;i<size(data);i++) {
            cout << data[i].first << "," << data[i].second << " ";
        }
        cout << endl;
        cout << P << " " << Q << endl;
    }

    int ret = 0;
    // wrange
    for(int i=0;i<W-P;i++) {
        // xs are i~(i+P-1)
        set<int> S;
        S.clear();
        for(int j=0;j<size(data);j++) {
            if(data[j].first >= i && data[j].first < i+P) {
                S.insert(data[j].second);
            }
        }
        S.insert(H);

        int prev = -1;
        foreach(it, S) {
            int range = *it - (prev + 1);
            ret += range - Q + 1;
            prev = *it;
        }
    }
    cout << ret << endl;
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        process(i);
    }
}
