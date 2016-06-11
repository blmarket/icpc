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

int dyna[2][10005];
int P, Q, N;

void setmax(int &a, int b) {
    if(a<b) a=b;
}

void process() {
    memset(dyna, -1, sizeof(dyna));
    scanf(" %d %d %d", &P, &Q, &N);
    dyna[0][0] = 0;

    int ret = 0;
    for(int i=0;i<N;i++) {
        int H, G;
        scanf(" %d %d", &H, &G);
        int cur = i % 2;
        int nex = !cur;
        for(int j=0;j<10005;j++) if(dyna[cur][j] >= 0) {
            int jj = j + (H+Q-1) / Q;
            cerr << i << " " << j << " = " << dyna[cur][j] << " " << jj << endl;
            setmax(dyna[nex][jj], dyna[cur][j]);
            if(P * jj >= (H % Q)) {
                int jjj = jj - (H%Q) / P;
                setmax(dyna[nex][jjj], dyna[cur][j] + G);
            }
        }
    }
    for(int i=0;i<10005;i++) {
        setmax(ret, dyna[N%2][i]);
    }
    cout << ret << endl;
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
