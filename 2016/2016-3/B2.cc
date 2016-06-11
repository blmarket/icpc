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
string gg;

bool gen(int a) {
    if(a >= L) {
        if(gg.substr(a-L) == tgt) return true;
    }
    if(a == N) return false;

    int x;
    while(true) {
        x = (rand() % N) + 1;
        if(state[x]) continue;
        while(state[req[x]] == false) x = req[x];
        break;
    }

    //cerr << a << " " << b << " " << x << endl;

    state[x] = true;
    gg += chr[x];
    return gen(a+1);
}

void process() {
    scanf(" %d" ,&N);
    for(int i=1;i<=N;i++) {
        scanf(" %d", &req[i]);
    }

    scanf(" %s", chr + 1);
    scanf(" %d", &M);
    for(int i=0;i<M;i++) {
        scanf(" %s", tgt);
        L = strlen(tgt);

        int cnt = 0;
        int ntry = 20000;
        for(int j=0;j<ntry;j++) {
            memset(state, 0, sizeof(state));
            gg.clear();
            state[0] = true;
            cnt += gen(0);
        }

        printf("%.12lf ", (double)cnt / ntry);
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        cerr << i << endl;
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
