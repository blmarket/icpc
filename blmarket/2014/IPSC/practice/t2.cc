#include <algorithm>
#include <iostream>
#include <cstdlib>
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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

long long L, K;
int N;

char marker[20000];

vector<pair<LL, LL> > V;

void process(int dataId)
{
    cin >> L >> N >> K;
    memset(marker, 0, sizeof(marker));
    for(int i=0;i<N;i++) {
        long long s, e;
        cin >> s >> e;
        V.pb(mp(s,e));
    }
    sort(V.begin(), V.end());
    long long cnt = 0;
    for(int i=0;i<size(V);i++) {
        long long s,e;
        tie(s,e) = V[i];
        cout << s << "-" << e << " ";
        for(int t=s;t<=e-K;t++) {
            if(marker[t] == 3) continue;
            marker[t] |= 2;
            cout << i << " " << t << endl;
            if(i == 1 && t == 500) cout << marker[t] << endl;
            if(marker[t] == 3) cnt++;
        }

        for(int t=s+K;t<=e;t++) {
            marker[t] |= 1;
        }
        cout << cnt << " ";
        if(i == 1) break;
    }

    cout << cnt << " " << L - cnt << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
        break;
    }
}
