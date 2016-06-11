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

int N;
int req[105];
char chr[105];
int M;
int L;
char tgt[105];

bool state[105];

bool gen(int a, int b) {
    cerr << a << " " << b << endl;
    if(b == L) return true;
    if(a == N) return false;

    int x;
    while(true) {
        x = rand() % N;
        if(state[x]) continue;
        while(state[req[x]] == false) x = req[x];
        cerr << x << endl;
        break;
    }

    state[x] = true;
    if(tgt[b] == chr[x]) {
        return gen(a+1, b+1);
    } else {
        return gen(a+1, 0);
    }
}

void process() {
    scanf(" %d" ,&N);
    for(int i=0;i<N;i++) {
        scanf(" %d", &req[i]);
    }

    scanf(" %s", chr);
    scanf(" %d", &M);
    for(int i=0;i<M;i++) {
        scanf(" %s", tgt);
        L = strlen(tgt);

        int cnt = 0;
        for(int j=0;j<100000;j++) {
            memset(state, 0, sizeof(state));
            state[0] = true;
            cnt += gen(0, 0);
        }

        printf("%.12lf ", cnt / 100000.0);
    }
    printf("\n");
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
