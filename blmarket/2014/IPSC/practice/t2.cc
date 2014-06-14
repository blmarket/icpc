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

char marker[2000005];

vector<pair<LL, LL> > V;
vector<LL> ps;

void process(int dataId)
{
    cin >> L >> N >> K;
    memset(marker, 0, sizeof(marker));
    for(int i=0;i<N;i++) {
        long long s, e;
        cin >> s >> e;
        e++;
        if(s+K >= e) continue;
        V.pb(mp(s,e));
        ps.pb(s); ps.pb(e);
        ps.pb(s+K); ps.pb(e-K);
    }
    sort(V.begin(), V.end());

    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    auto idx = [&](long long a) -> int {
        return lower_bound(ps.begin(), ps.end(), a) - ps.begin();
    };

    long long cnt = 0;
    for(int i=0;i<size(V);i++) {
        long long s,e;
        tie(s,e) = V[i];
        int si = idx(s);
        int ei = idx(e-K);

        for(int t=si;t<ei;t++) {
            if(marker[t] == 3) continue;
            if(marker[t] == 1) {
                marker[t] = 3;
                cnt += ps[t+1] - ps[t];
            }
        }

        si = idx(s+K);
        ei = idx(e);
        for(int t=si;t<ei;t++) {
            if(marker[t] == 0) marker[t] = 1;
        }
    }

    cout << L - cnt << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
