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

map<PII, int> memo;
int P, Q, N;
int H[105], G[105];

int go(int a, int b) {
    if(a == N) return 0;
    if(memo.count(mp(a,b))) {
        return memo[mp(a,b)];
    }

    int HH = H[a];
    while(HH > Q) {
        b++;
        HH -= Q;
    }

    int ret = go(a+1, b+1);
    if(HH <= P * b) {
        int tmp = go(a+1, b - (HH+P-1) / P) + G[a];
        if(ret < tmp) ret = tmp;
    }
    return memo[mp(a,b)] = ret;
}

void process() {
    memo.clear();
    scanf(" %d %d %d", &P, &Q, &N);
    for(int i=0;i<N;i++) {
        scanf(" %d %d", &H[i], &G[i]);
    }

    cout << go(0, 1) << endl;
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
