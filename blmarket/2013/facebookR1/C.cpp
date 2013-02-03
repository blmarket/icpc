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
    data.clear();
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
    data.erase(unique(data.begin(), data.end()), data.end());
    /*
    if(ID == 1) {
        for(int i=0;i<size(data);i++) {
            cout << data[i].first << "," << data[i].second << " ";
        }
        cout << endl;
    }
    */

    int ret = 0;
    map<int, int> M;
    M.clear();
    M[H] = 1;

    int j = 0, jj = 0;
    // wrange
    for(int i=0;i<=W-P;i++) {
        while(j < size(data) && data[j].first < i+P) {
            M[data[j].second]++;
            j++;
        }
        while(jj < size(data) && data[jj].first < i) {
            M[data[jj].second]--;
            jj++;
        }

        int prev = -1;
        foreach(it, M) {
            while(it != M.end() && it->second == 0) {
                M.erase(it++);
            }
            if(it == M.end()) break;
            int range = it->first - (prev + 1);
            prev = it->first;
            if(range < Q) continue;
            ret += range - Q + 1;
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
