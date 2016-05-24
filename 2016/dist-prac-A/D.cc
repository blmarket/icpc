#include <iostream>
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
    return v;
}

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes();

    int n = GetN();
    for(int i=0;i<n;i++) w.pb(GetWeight(i));

    vector<LL> v1 = move(gen1(0, n/2));
    vector<LL> v2 = move(gen1(n/2, n));

    return 0;
}
