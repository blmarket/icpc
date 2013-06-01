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

                int tgt = 2;
                for(int j=i-1;j>=0;j--) if(ret[j] == -1) {
                    if(V[j].second <= tgt) { 
                        tgt = max(tgt, V[j].second + 1);
                        V[j].second--;
                    }
                }

                tgt = 2;
                for(int j=i+1;j<n;j++) if(ret[j] == -1) {
                    if(V[j].first <= tgt) {
                        tgt = max(tgt, V[j].first + 1);
                        V[j].first--;
                    }
                }


                for(int j=0;j<n;j++) printf("%3d ", V[j].first);
                printf("\n");
                for(int j=0;j<n;j++) printf("%3d ", V[j].second);
                printf("\n");
                for(int j=0;j<n;j++) printf("%3d ", ret[j]);
                printf("\n\n");
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
