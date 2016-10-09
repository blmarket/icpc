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

int N,KK,X;
LL K;
LL V[200005];

vector<PII> vs;

int main(void) {
    scanf(" %d %d %d", &N, &KK, &X);
    LL KX = (LL) KK * X;
    int ss, si;
    int mx = 1;
    for(int i=0;i<N;i++) {
        int aa;
        scanf(" %d", &aa);
        V[i] = aa;
        if(V[i] < 0) mx = -mx;
        int tmp = abs(V[i]);
        if(i == 0 || ss > tmp) {
            ss = tmp;
            si = i;
        }
    }
    if(mx == -1) {
        if(V[si] < 0) {
            V[si] -= KX;
        } else {
            V[si] += KX;
        }
    } else {
        if(V[si] < 0) {
            V[si] += KX;
        } else {
            V[si] -= KX;
        }
    }

    for(int i=0;i<N;i++) {
        cout << V[i] << " ";
    }
    cout << endl;
    return 0;
}
