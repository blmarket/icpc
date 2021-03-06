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
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N,M;
vector<int> s,e,f;
vector<int> ss,ee;
int arr[1024][1024];

void process(void) {
    cin >> N >> M;
    s=e=f=vector<int>(M,0);
    for(int i=0;i<M;i++) {
        cin >> s[i] >> e[i] >> f[i];
    }
    ss=s;ee=e;
    sort(ss.begin(), ss.end()); ss.erase(unique(ALL(ss)), ss.end());
    sort(ee.begin(), ee.end()); ee.erase(unique(ALL(ee)), ee.end());

    LL cur = 0;
    memset(arr, 0, sizeof(arr));
    for(int i=0;i<M;i++) {
        LL dist = e[i] - s[i];
        cur += dist * (dist-1) * f[i];
        int p1 = lower_bound(ALL(ss), s[i]) - ss.begin();
        int p2 = lower_bound(ALL(ee), e[i]) - ee.begin();
        arr[p1][p2] += f[i];
    }

    LL ret = 0;
    auto debug = [&]() {
        LL nex = 0;
        int cc = 0;
        for(int i=0;i<size(ss);i++) {
            for(int j=0;j<size(ee);j++) {
                if(arr[i][j]) {
                    cc++;
                    LL dist = ee[j] - ss[i];
                    nex += dist * (dist-1) * arr[i][j];
                }
            }
        }
    };

    while(true) {
        bool change = false;
        for(int i=0;i<size(ss);i++, cerr << i << endl) for(int j=0;j<size(ee);j++) if(arr[i][j]) {
            for(int ii=i+1;ii<size(ss);ii++) {
                if(ee[j] < ss[ii]) continue;
                if(arr[i][j] == 0) break;
                for(int jj=0;jj<size(ee);jj++) if(arr[ii][jj]) {
                    if(ee[jj] < ss[i]) continue;
                    if(arr[i][j] == 0) break;
                    long long p1 = ee[j] - ss[i];
                    long long p2 = ee[jj] - ss[ii];
                    LL c1 = p1*(p1-1) + p2*(p2-1);

                    long long p3 = ee[jj] - ss[i];
                    long long p4 = ee[j] - ss[ii];
                    LL c2 = p3*(p3-1) + p4 * (p4-1);
                    if(c2 > c1) {
                        change = true;
                        int minf = min(arr[i][j], arr[ii][jj]);
                        c2 -= c1;
                        c2 %= 1000002013LL;
                        ret += c2 * minf;
                        ret %= 1000002013LL;
                        arr[i][j] -= minf; arr[ii][jj] -= minf;
                        arr[i][jj] += minf; arr[ii][j] += minf;
                    }
                }
            }
        }

        if(!change) break;
    }

    if(ret & 1) {
        ret += 1000002013LL;
    }
    ret /= 2;
    ret %= 1000002013LL;

    cout << ret << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
