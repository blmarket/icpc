#include <iostream>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

long long mod = 1000000007LL;

int mf[2][1000005];
vector<int> gmf[2][1000005];
map<pair<int, int>, int> MM;

void process(void) {
    for(int i=0;i<2;i++) for(int j=0;j<1000005;j++) gmf[i][j].clear();
    int n,m;
    scanf("%d %d", &n, &m);
    MM.clear();
    for(int i=0;i<n;i++) {
        mf[0][i] = mf[1][i] = i;
        MM[mp(i,i)] = 1;
        gmf[0][i].pb(i);
        gmf[1][i].pb(i);
    }

    long long ret = 0;
    long long sum = 0;

    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        a--;b--;c--;
        int g1 = mf[a][b], g2 = mf[a][c];
        if(g1 != g2) {
            if(gmf[a][g1].size() < gmf[a][g2].size()) {
                swap(g1, g2);
            }

            for(auto &it: gmf[a][g2]) {
                pair<int, int> cg = mp(mf[0][it], mf[1][it]);
                mf[a][it] = g1;
                gmf[a][g1].pb(it);
                pair<int, int> ng = mp(mf[0][it], mf[1][it]);
                // cout << "::" << cg.first << " " << cg.second << " -> " << ng.first << " " << ng.second << endl;
                long long tmp = MM[cg];
                sum -= tmp*(tmp-1)/2;
                sum += (tmp-1)*(tmp-2)/2;
                if(--MM[cg] == 0) {
                    MM.erase(cg);
                }
                tmp = MM[ng];
                sum -= tmp*(tmp-1)/2;
                sum += tmp*(tmp+1)/2;
                MM[ng]++;
                sum %= mod;
                if(sum < 0) sum += mod;
            }
            gmf[a][g2].clear();
        }

        // cerr << "sum = " << sum << " " << MM.size() << endl;
        ret += sum * (i+1);
        if(ret >= mod) ret %= mod;
    }
    cerr << n << " " << m << endl;
    cout << ret << endl;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) process();
}
