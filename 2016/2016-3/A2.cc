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

char mood[50005];
int dyna[202][202];
char cj[3] = "JC";

void setmax(int &a, int b) {
    if(a<b) a= b;
}

int go(int s, int e) {
    if(s >= e) return 0;
    if(mood[s] == mood[e-1]) return go(s+1, e-1) + 10;
    if(mood[s] == mood[s+1]) return go(s+2, e) + 10;
    if(mood[e-1] == mood[e-2]) return go(s, e-2) + 10;

    if(s+2 == e) return 5;

    int ret = 0;
    for(int i=s+2;i<e;i+=2) {
        int tmp = go(s, i) + go(i, e);
        setmax(ret, tmp);
    }
    return dyna[s][e] = ret;
}

void process() {
    scanf(" %s", mood);
    int N = strlen(mood);
    memset(dyna, -1, sizeof(dyna));

    for(int i=2;i<N;i+=2) {
        for(int j=0;j<N;j+=2) {
            go(j, j+i);
        }
    }

    cout << go(0, N) << endl;
    return;
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
