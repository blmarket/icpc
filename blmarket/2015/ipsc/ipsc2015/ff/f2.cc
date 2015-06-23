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
    }

    long long ret = 0;

    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        a--;b--;c--;
        int g1 = mf[a][b], g2 = mf[a][c];
        if(gmf[a][g1].size() < gmf[a][g2].size()) {
            swap(g1, g2);
        }

        for(auto &it: gmf[a][g2]) {
            cout << it << " -> " << g1 << endl;
            pair<int, int> cg = mp(mf[0][it], mf[1][it]);
            mf[a][it] = g1;
            gmf[a][g1].pb(it);
            pair<int, int> ng = mp(mf[0][it], mf[1][it]);
            if(--MM[cg] == 0) {
                MM.erase(cg);
            }
            MM[ng]++;
        }
        gmf[a][g2].clear();

        long long sum = 0;
        for(auto &it: MM) {
            cout << it.second << " ";
            sum += (long long)it.second * (it.second-1) / 2;
            if(sum >= mod) sum -= mod;
        }
        cout << endl;
        ret += sum * (i+1);
        if(ret >= mod) ret %= mod;
    }
    cout << ret << endl;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) process();
}
