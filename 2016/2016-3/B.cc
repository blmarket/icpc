#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N;
int req[105];
char chr[105];
int M;
int L;
char tgt[105];

bool state[105];

double go(int a, int ntry) {
    cerr << a << " " << ntry << endl;
    if(ntry == 0) return 0;
    double ret = 0;

    if(a == L) return 1;

    vector<int> poss;
    for(int i=0;i<N;i++) if(!state[i]) {
        if(req[i] == -1 || state[req[i]]) {
            poss.pb(i);
        }
    }
    if(poss.size() == 0) return 0;

    int nn = ntry / poss.size();
    if(nn == 0) {
        random_shuffle(poss.begin(), poss.end());
        poss.resize(ntry);
        nn = 1;
    }

    each(it, poss) {
        state[it] = true;
        if(chr[it] == tgt[a]) {
            ret += go(a+1, nn) / poss.size();
        } else {
            ret += go(0, nn) / poss.size();
        }
        state[it] = false;
    }
    return ret;
}

pair<int, LL> nchild[105];

void chk(int a) {
    int nc = 0;
    LL ne = 1;
    for(int i=0;i<N;i++) if(req[i] == a) {
        if(nchild[i].first == -1) chk(i);
        ne *= combi(nc + nchild[i].first, nchild[i].first) * nchild[i].second;
        nc += nchild[i].first;
    }
    nchild[a] = mp(nc, ne);
}

void process() {
    scanf(" %d" ,&N);
    for(int i=0;i<N;i++) {
        scanf(" %d", &req[i]);
        req[i]--;
    }
    for(int i=0;i<N;i++) nchild[i] = mp(-1,-1);
    for(int i=0;i<N;i++) {
        chk(i);
    }

    scanf(" %s", chr);
    scanf(" %d", &M);
    for(int i=0;i<M;i++) {
        scanf(" %s", tgt);
        L = strlen(tgt);
        double ret = go(0, 100000000);
        printf("%.12lf ", ret);
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
