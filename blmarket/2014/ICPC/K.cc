#include <iostream>
#include <sys/wait.h>
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

template<typename T> int size(const T &a) { return a.size(); } 

int N, M;
vector<PII> V;

int chk(int a) {
    int s = V[a].first;
    int e = V[a].second;

    int ret = 1;

    if(e < s) e += N;
    int nextreach = e;
    for(int i=a;i<size(V);i++) {
        int rr = V[i].second;
        if(V[i].second < V[i].first) rr += N;

        if(V[i].first > nextreach+1) {
            return -1;
        }

        if(V[i].first > e+1) {
            e = nextreach;
            ret++;
            if(e + 1 >= s + N) return ret;
        }

        nextreach = max(nextreach, rr);
    }

    if(nextreach + 1 >= s + N) return ret + 1;
    return -1;
}

int main(void) {
    scanf("%d %d", &N, &M);
    V.clear();
    for(int i=0;i<M;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        V.pb(mp(a,b));
    }
    sort(V.begin(), V.end());

    for(int i=0;i<size(V);i++) {
        cout << V[i].first << " " << V[i].second << " = " << chk(i) << endl;
    }
    cout << endl;

    return 0;
}
