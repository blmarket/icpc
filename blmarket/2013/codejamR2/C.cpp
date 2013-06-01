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

vector<int> go(vector<PII> V) {
    int n = size(V);
    vector<int> ret(size(V), -1);

    int cnt = 0;
    while(cnt < n) {
        for(int i=0;i<n;i++) {
            if(V[i].first == 1 && V[i].second == 1) {
                ret[i] = ++cnt;
                V[i].first = V[i].second = -1;

                function<void(int,int,int)> setsecond = [&](int s, int e, int tgt) {
                    for(int j=s;j<e;j++) if(ret[j] == -1) {
                        if(V[j].second == tgt) {
                            V[j].second--;
                            setsecond(s, j, tgt + 1);
                            s = j;
                        }
                    }
                };

                function<void(int,int,int)> setfirst = [&](int s, int e, int tgt) {
                    for(int j=e-1;j>s;j--) if(ret[j] == -1) {
                        if(V[j].first == tgt) {
                            V[j].first--;
                            setfirst(j, e, tgt + 1);
                            e = j;
                        }
                    }
                };

                setsecond(0, i, 2);
                setfirst(i, n, 2);
                break;
            }
        }
    }
    return ret;
}

void process(void) {
    int N;
    vector<PII> V;
    scanf("%d", &N);
    V.resize(N);
    for(int i=0;i<N;i++)
        scanf("%d", &V[i].first);
    for(int i=0;i<N;i++)
        scanf("%d", &V[i].second);

    vector<int> ret = go(V);
    for(int i=0;i<N;i++)
        cout << ret[i] << " ";
    cout << endl;
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
