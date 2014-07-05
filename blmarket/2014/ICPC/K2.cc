#include <iostream>
#include <algorithm>
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
vector<int> J;

int main(void) {
    scanf("%d %d", &N, &M);
    V.clear();
    for(int i=0;i<M;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        if(b < a) b += N;
        V.pb(mp(a,b));
    }

    sort(V.begin(), V.end());
    for(int i=0;i<size(V);i++) {
        while(i+1 < size(V)) {
            if(V[i+1].second > V[i].second) break;
            V.erase(V.begin() + i+1);
        }
    }

    J.resize(V.size());
    for(int i=0;i<size(V);i++) {
        int ss = V[i].second;
        if(ss > N) ss -= N;
        int ep = upper_bound(V.begin(), V.end(), mp(ss+1, 1000000)) - V.begin() - 1;

        if(V[i].second > N) {
            ep += size(V);
        }
        J[i] = ep - i;
        // cout << V[i].first << "," << V[i].second%N << " " << J[i] << endl;
    }

    vector<int> JJ(size(J));
    for(int t=1;;t++) {
        for(int i=0;i<size(V);i++) {
            if(J[i] >= size(V)) { cout << t << endl; return 0; }
            JJ[i] = J[i] + J[(i+J[i])%size(J)];
        }
        J.swap(JJ);
    }

    return 0;
}
