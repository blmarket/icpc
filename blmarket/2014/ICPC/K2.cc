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
vector<int> J[25];

vector<int> sum(const vector<int> &a, const vector<int> &b) {
    int m = size(a);
    vector<int> ret(m);
    for(int i=0;i<m;i++) {
        ret[i] = a[i] + b[(i+a[i])%m];
    }
    return ret;
}

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

    if(V.back().second > N) {
        while(V[0].second < V.back().second - N) {
            V.erase(V.begin());
        }
    }

    J[1].resize(V.size());
    for(int i=0;i<size(V);i++) {
        int ss = V[i].second + 1;
        if(ss > N) ss -= N;
        int ep = upper_bound(V.begin(), V.end(), mp(ss, 1000000)) - V.begin() - 1;

        if(V[i].second >= N) {
            ep += size(V);
        }
        J[1][i] = ep - i;
        if(J[1][i] == 0) {
            cout << "impossible" << endl;
            return 0;
        }
        // cout << V[i].first << "," << V[i].second%N << " " << J[i] << endl;
    }

    for(int t=1;t<24;t++) {
        J[t+1].resize(J[1].size());
        for(int i=0;i<size(V);i++) {
            J[t+1][i] = J[t][i] + J[t][(i+J[t][i])%size(V)];
            if(J[t+1][i] > size(V)) J[t+1][i] = size(V);
        }
    }

    int ret = 1<<25;
    for(int i=0;i<size(V);i++) {
        int pos = 24;
        int sum = 0;

        while(pos > 0) {
            int sz = 1<<(pos+1);
            int cur = 0;
            int tmp = cur + J[pos][(i + cur) % size(V)];
            if(tmp >= size(V)) {
                if(ret > sum + sz) {
                    ret = sum + sz;
                }
            } else {
                sum += sz;
                cur = tmp;
            }
            pos--;
        }
    }
    cout << ret << endl;

    return 0;
}
