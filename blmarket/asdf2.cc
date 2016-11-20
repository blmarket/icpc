#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k,prep,mana;
vector<pair<int, int> > spell1, spell2;

int main(void) {
    scanf(" %d %d %d", &n, &m, &k);
    scanf(" %d %d", &prep, &mana);
    spell1.resize(m);
    spell2.resize(k+1);
    for(int i=0;i<m;i++) scanf(" %d", &spell1[i].second);
    for(int i=0;i<m;i++) scanf(" %d", &spell1[i].first);
    spell2[0] = make_pair(0, 0);
    for(int i=1;i<=k;i++) scanf(" %d", &spell2[i].second);
    for(int i=1;i<=k;i++) scanf(" %d", &spell2[i].first);

    spell1.emplace_back(make_pair(0, prep));

    long long mintime = 41e17;
    for(auto &it : spell1) {
        int cur = mana - it.first;
        if (cur < 0) continue;
        vector<pair<int, int> >::iterator jt = upper_bound(spell2.begin(), spell2.end(), make_pair(cur, (int)21e8));
        --jt;
        long long remain = n - jt->second;
        if(remain < 0) remain = 0;
        long long t1 = remain * it.second;
        mintime = min(mintime, t1);
    }
    cout << mintime << endl;
}
