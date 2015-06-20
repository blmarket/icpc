#include <iostream>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

long long mod = 1000000007LL;

int group[2][10005];
vector<int> descendants[2][10005];

void merge(int a, int b, int c) {
    int ng = group[a][c];
    auto &V = descendants[a][group[a][b]];
    for(auto &it: V) {
        group[a][it] = ng;
        descendants[a][ng].pb(it);
    }
    V.clear();
}

void process(void) {
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<=n;i++) {
        group[0][i] = group[1][i] = i;
        descendants[0][i].pb(i);
        descendants[1][i].pb(i);
    }

    long long ret = 0;

    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        merge(a-1,b,c);

        map<pair<int, int>, int> M;
        M.clear();

        for(int i=1;i<=n;i++) {
            cout << group[0][i] << group[1][i] << " ";
            M[mp(group[0][i], group[1][i])] += 1;
        }
        cout << endl;
        for(auto &it: M) {
            ret += ((long long)it.second * (it.second - 1)) / 2;
            ret %= mod;
        }
    }
    cout << ret << endl;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) process();
}
