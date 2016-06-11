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
int dyna[20002][20002];
char cj[3] = "JC";

void setmax(int &a, int b) {
    if(a<b) a= b;
}

void process() {
    scanf(" %s", mood);
    int N = strlen(mood);

    memset(dyna, -1, sizeof(dyna));
    dyna[0][0] = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<5;j++) if(dyna[i][j] != -1) {
            int cur = dyna[i][j];
            if(mood[i] == 'C') {
                setmax(dyna[i+1][3], dyna[i][j]);
                setmax(dyna[i+1][2], dyna[i][j]);
            } else {
                setmax(dyna[i+1][4], dyna[i][j]);
                setmax(dyna[i+1][1], dyna[i][j]);
            }
            if(j) {
                int score = (j-1)/2 * 5;
                if(cj[j%2] == mood[i]) score += 5;
                setmax(dyna[i+1][0], dyna[i][j] + score);
            }
        }
    }
    int ret = 0;
    for(int i=0;i<5;i++) {
        setmax(ret, dyna[N][i]);
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
