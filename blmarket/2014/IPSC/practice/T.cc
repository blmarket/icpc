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

long long L;
int N;
long long K;
char marker[2000005];
vector<long long> ps;
vector<pair<LL, LL> > V;

void process(int dataId)
{
    cin >> L >> N >> K;
    V.clear();
    for(int i=0;i<N;i++) {
        long long a,b;
        cin >> a >> b;
        b++;
        if(b-a <= K) continue;

        ps.pb(a);
        ps.pb(b);
        ps.pb(a+K);
        ps.pb(b-K);
        V.pb(mp(a,b));
    }
    sort(V.begin(), V.end());
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());

    memset(marker, 0, sizeof(marker));

    long long cnt = 0;
    int cntlast = -1;
    int marklast = -1;
    for(int i=0;i<size(V);i++) {
        long long s = V[i].first;
        long long e = V[i].second - K;
        int p1 = lower_bound(ps.begin(), ps.end(), s) - ps.begin();
        int p2 = lower_bound(ps.begin(), ps.end(), e) - ps.begin();
        p1 = max(p1, cntlast);
        for(int i=p1;i<p2;i++) {
            if(marker[i]) {
                cout << ps[i] << "-" << ps[i+1] << endl;
                cnt += (ps[i+1] - ps[i]);
            }
        }
        cntlast = max(cntlast, p2);

        s = V[i].first + K;
        e = V[i].second;
        p1 = lower_bound(ps.begin(), ps.end(), s) - ps.begin();
        p2 = lower_bound(ps.begin(), ps.end(), e) - ps.begin();
        p1 = max(p1, marklast);
        for(int i=p1;i<p2;i++) {
            marker[i] = 1;
        }
        marklast = max(marklast, p2);
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
