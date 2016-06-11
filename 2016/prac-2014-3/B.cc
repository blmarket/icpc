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

int dyna[2][2][10005];
int P, Q, N;

void setmax(int &a, int b) {
    if(a<b) a=b;
}

void process() {
    memset(dyna, -1, sizeof(dyna));
    scanf(" %d %d %d", &P, &Q, &N);
    dyna[0][0][0] = 0;

    int ret = 0;
    for(int i=0;i<N;i++) {
        int H, G;
        scanf(" %d %d", &H, &G);
        int cur = i % 2;
        int nex = !cur;
        memset(dyna[nex], -1, sizeof(dyna[0]));
        for(int t=0;t<2;t++) {
            for(int j=0;j<10005;j++) if(dyna[cur][t][j] >= 0) {
                int jj = j + (H+Q-1) / Q;
                cerr << i << " " << t << " " << j << " = " << dyna[cur][t][j] << " " << jj << endl;
                setmax(dyna[nex][0][jj], dyna[cur][t][j]);
                if(H > 0 && P * jj >= ((H-1) % Q)+1) {
                    int jjj = jj - (((H-1)%Q)+1) / P;
                    setmax(dyna[nex][1][jjj], dyna[cur][t][j] + G);
                }
            }
            H -= Q;
        }
    }
    for(int i=0;i<10005;i++) {
        setmax(ret, dyna[N%2][0][i]);
        setmax(ret, dyna[N%2][1][i]);
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
