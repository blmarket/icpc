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
int dyna[50005][9];
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
        for(int j=0;j<9;j++) if(dyna[i][j] != -1) {
            int cur = dyna[i][j];
            int s1 = j / 3;
            int s2 = j % 3;
            cerr << i << " " << s1 << " " << s2 << " = " << cur << endl;

            if(mood[i] == 'C') {
                setmax(dyna[i+1][6 + s2], dyna[i][j]);
                setmax(dyna[i+1][s1*3+1], dyna[i][j]);
            } else {
                setmax(dyna[i+1][3 + s2], dyna[i][j]);
                setmax(dyna[i+1][s1*3+2], dyna[i][j]);
            }

            if(s1) {
                int score = (s1-1 + (mood[i]=='C')) * 5;
                setmax(dyna[i+1][s2], dyna[i][j] + score);
            }
            if(s2) {
                int score = (s2-1 + (mood[i]=='J')) * 5;
                setmax(dyna[i+1][s1*3], dyna[i][j] + score);
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
