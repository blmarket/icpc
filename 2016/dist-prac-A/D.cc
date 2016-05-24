#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#include <message.h>

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

#include "load_balance.h"

vector<LL> w;

vector<LL> gen1(int s, int e) {
    vector<LL> v;
    v.pb(0);
    for(int i=s;i<e;i++) {
        for(int j=v.size()-1;j>=0;j--) {
            v.pb(v[j] + w[i]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes();

    int n = GetN();
    for(int i=0;i<n;i++) w.pb(GetWeight(i));

    LL sum = 0;
    each(it, w) sum += it;

    if (sum & 1) {
        if(my == 0) {
            cout << "IMPOSSIBLE" << endl;
        }
        return 0;
    }
    sum /= 2;

    vector<LL> v1 = move(gen1(0, n/2));
    vector<LL> v2 = move(gen1(n/2, n));

    each(it, v1) {
        int rest = sum - it;
        if (ret == *lower_bound(v2.begin(), v2.end(), rest)) {
            PutLL(0, 1);
            Send(0);
            goto end;
        }
    }
    PutLL(0, 0);
    Send(0);

end:
    if(my == 0) {
        for(int i=0;i<nn;i++) {
            Receive(i);
            if (GetLL(i)) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    return 0;
}
