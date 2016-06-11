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

int N, K;
vector<int> v;

void process() {
    scanf(" %d %d", &N, &K);
    v.resize(N-K+1);
    for(int i=0;i<N-K+1;i++) {
        scanf(" %d", &v[i]);
    }
    for(int i=0;i+1<size(v);i++) {
        v[i] = v[i+1] - v[i];
    }
    v.pop_back();

    each(it, v) cerr << it << " "; cerr << endl;

    for(int i=0;i<K;i++) {
        LL ret = 0;
        for(int j=i;j<size(v);j+=K) {
            LL sum = 0;
            for(int k=j;k<size(v);k+=K) {
                sum += v[k];
            }
            if(abs(ret) < abs(sum)) ret = sum;
        }
        cerr << ret << endl;
    }
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
