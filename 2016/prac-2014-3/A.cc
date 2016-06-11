#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N,p,q,r,s;
vector<int> v;

void process() {
    v.clear();
    scanf(" %d %d %d %d %d", &N, &p,&q,&r,&s);
    for(int i=0;i<N;i++) {
        LL tmp = i;
        tmp = (tmp * p + q) % r;
        tmp += s;
        v.pb(tmp);
    }
    each(it, v) cerr << it << " "; cerr << endl;
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
