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
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int n;
VI links[105];
VI label[105];
vector<PII> ls[150005];

VI get_doorsig(int s, int e) {
    int sz = size(links[e]);
    int ii = find(all(links[e]), s) - links[e].begin();

    VI ret;
    for(int i=0;i<sz;i++) {
        ret.pb(label[e][(ii+i)%sz]);
    }
    return ret;
}

VI roomsig(int s) {
    int sz = size(links[s]);
    VI ret;
    for(int i=0;i<sz;i++) {
        VI tmp; tmp.clear();
        for(int j=0;j<sz;j++) {
            tmp.pb(label[s][(i+j)%sz]);
        }
        if(ret.size() == 0 || ret > tmp) ret = tmp;
    }
    return ret;
}

int main(void) {
    scanf(" %d", &n);
    for(int i=1;i<=n;i++) {
        int m;
        scanf(" %d", &m);
        links[i].resize(m);
        for(int j=0;j<m;j++) {
            scanf(" %d", &links[i][j]);
            links[i][j]--;
            ls[m].pb(mp(i, links[i][j]));
        }
        label[i] = vector<int>(m, m);
    }

    int mm = 105;
    while(true) {
        bool change = false;
        // for(int i=0;i<mm;i++) {
        //     if(ls[i].size() == 0) continue;
        //     cout << i << " : ";
        //     for(int j=0;j<size(ls[i]);j++) {
        //         cout << ls[i][j].first << "-" << ls[i][j].second << " ";
        //     }
        //     cout << endl;
        // }

        for(int i=0;i<mm;i++) {
            if(ls[i].size() < 2) continue;
            map<VI, vector<PII> > M;
            M.clear();
            for(int j=0;j<size(ls[i]);j++) {
                VI tmp = get_doorsig(ls[i][j].first, ls[i][j].second);
                M[tmp].pb(ls[i][j]);
            }
            if(size(M) == 1) continue;
            change = true;
            for(auto &it : M) {
                ls[mm] = it.second;
                for(PII jt : it.second) {
                    int a,b;
                    tie(a,b) = jt;
                    for(int j=0;j<size(links[a]);j++) if(links[a][j] == b) {
                        label[a][j] = mm;
                    }
                }
                mm++;
            }
            ls[i].clear();
        }
        cout << change << endl;
        if(!change) break;
    }

    VVI sigs(n);
    for(int i=0;i<n;i++) sigs[i] = roomsig(i);

    vector<bool> used(n, 0);
    bool none = true;
    for(int i=0;i<n;i++) if(used[i] == false) {
        used[i] = true;
        vector<int> V; V.clear(); V.pb(i);
        for(int j=i+1;j<n;j++) if(!used[j] && sigs[i] == sigs[j]) {
            used[j] = true;
            V.pb(j);
        }
        if(V.size() == 1) continue;
        none = false;
        for(int j=0;j<size(V);j++) {
            cout << V[j]+1 << " - ";
        }
        cout << endl;
    }

    if(none) {
        cout << "none" << endl;
    }

    return 0;
}
