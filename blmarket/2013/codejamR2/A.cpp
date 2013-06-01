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

int N, M;
int s[1000005], e[1000005], f[1000005];

void process(void) {
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++) {
        scanf("%d %d %d", &s[i], &e[i], &f[i]);
    }

    long long ret = 0;

    while(true) {
        bool action = false;

        for(int i=0;i<M;i++) if(f[i]) {
            for(int j=i+1;j<M;j++) if(f[j]) {
                if(e[i] < s[j] || e[j] < s[i]) continue;
                int d1 = e[i] - s[i];
                int d2 = e[j] - s[j];
                long long cost = d1 * N - (d1-1) * d1 / 2 + d2 * N - (d2-1) * d2 / 2;

                int nd1 = e[i] - s[j];
                int nd2 = e[j] - s[i];
                long long cost2 = nd1 * N - (nd1-1) * nd1 / 2 + nd2 * N - (nd2-1) * nd2 / 2;

                if(cost2 < cost) {
                    action = true;
                    int minf = min(f[i], f[j]);
                    ret += minf * (cost - cost2);
                    if(f[i] == f[j]) {
                        swap(e[i], e[j]);
                    } else {
                        f[i] -= minf;
                        f[j] -= minf;
                        s[M] = s[i]; e[M] = e[j]; f[M] = minf;
                        s[M+1] = s[j]; e[M+1] = e[i]; f[M+1] = minf;
                        if(f[i] == 0) {
                            s[i] = s[M+1]; e[i] = e[M+1]; f[i] = f[M+1];
                        } else {
                            s[j] = s[M+1]; e[j] = e[M+1]; f[j] = f[M+1];
                        }
                        M++;
                    }
                }
            }
        }
        if(!action) break;
    }
    cerr << M << endl;
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
