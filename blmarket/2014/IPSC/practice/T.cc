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
vector<pair<LL, LL> > V;

void process(int dataId)
{
    cin >> L >> N >> K;
    V.resize(N);
    for(int i=0;i<N;i++) {
        cin >> V[i].first >> V[i].second;
    }
    sort(V.begin(), V.end());

    long long ps = -1, pe = -1;

    long long cnt = 0;

    for(int i=0;i<N;i++) {
        long long s, e;
        tie(s,e) = V[i];
        long long rs, re;
        rs = s; re = e - K;

        if(ps != -1) {
            // erase rs, re from ps, pe;
            if(pe < rs || re < ps) { 1; } else {
                long long arr[4] = { ps, pe, rs, re };
                sort(arr, arr+4);
                cnt += (arr[2] - arr[1] + 1);
                if(arr[1] == ps) {
                    if(arr[2] == pe) {
                        ps = pe = -1;
                    } else {
                        ps = arr[2]+1;
                    }
                } else {
                    pe = arr[1] - 1;
                }
            }
        }

        if(ps == -1) {
            ps = s + K;
            pe = e;
        } else {
            // add s+K, e to ps, pe range.
            cout << ps << " " << pe << " + " << (s+K) << " " << e << endl;
        }
    }
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
