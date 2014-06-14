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

    int last = -1;
    for(int i=0;i<size(V);i++) {
        long long s = V[i].first;
        long long e = V[i].second - K;
        cout << s << " " << e << endl;
        int p1 = lower_bound(ps.begin(), ps.end(), s) - ps.begin();
        int p2 = lower_bound(ps.begin(), ps.end(), e) - ps.begin();
        p1 = max(p1, last);
        for(int i=p1;i<p2;i++) {
            marker[i] |= 1;
        }
        last = p2 - 1;
    }

    last = -1;
    for(int i=0;i<size(V);i++) {
        long long s = V[i].first + K;
        long long e = V[i].second;
        int p1 = lower_bound(ps.begin(), ps.end(), s) - ps.begin();
        int p2 = lower_bound(ps.begin(), ps.end(), e) - ps.begin();
        p1 = max(p1, last);
        for(int i=p1;i<p2;i++) {
            marker[i] |= 2;
        }
        last = p2 - 1;
    }

    long long cnt = 0;
    for(int i=0;i+1<size(ps);i++) {
        cout << ps[i] << "-" << ps[i+1] << " = " << (int)marker[i] << endl;
        if(marker[i] == 3) {
            cnt += (ps[i+1] - ps[i]);
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
