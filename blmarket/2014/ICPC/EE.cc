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

int n;
vector<int> rr[105];
vector<int> label[105];

vector<PII> ls[50005];

vector<int> get_sig(int s, int e) {
    int sz = size(rr[e]);
    int sp = find(rr[e].begin(), rr[e].end(), s) - rr[e].begin();
    vector<int> ret;
    for(int i=1;i<sz;i++) {
        int ii = (sp + i) % sz;
        ret.pb(label[e][ii]);
    }
    return ret;
}

void set_label(int s, int e, int l) {
    int sp = find(rr[s].begin(), rr[s].end(), e) - rr[s].begin();
    label[s][sp] = l;
}

int main(void) {
    scanf(" %d", &n);
    for(int i=1;i<=n;i++) {
        int m;
        scanf(" %d", &m);
        rr[i].resize(m);
        for(int j=0;j<m;j++) {
            scanf(" %d", &rr[i][j]);
            ls[m].pb(mp(i, rr[i][j]));
        }
        label[i] = vector<int>(m, m);
    }

    int mm = 101;
    while(true) {
        cout << mm << endl;
        map<vector<int>, vector<PII> > M;
        for(int i=1;i<mm;i++) if(ls[i].size() > 1) {
            M.clear();
            for(auto &it : ls[i]) {
                vector<int> sig = get_sig(it.first, it.second);
                M[sig].pb(it);
            }

            if(size(M) != 1) {
                for(auto it : M) {
                    ls[mm] = it.second;
                    for(auto jt : it.second) {
                        set_label(jt.first, jt.second, mm);
                    }
                    mm++;
                }
            }
            ls[i].clear();
        }
    }

    for(int i=1;i<=n;i++) {
        cout << i << " : ";
        for(auto it : label[i]) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
