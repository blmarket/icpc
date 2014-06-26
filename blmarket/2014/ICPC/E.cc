#include <iostream>
#include <sys/wait.h>
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
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int n;
vector<int> rr[105];
char diff[105][105][105][105];

void add_diff(int s1, int e1, int s2, int e2) {
    if(diff[s1][e1][s2][e2]) return;
    diff[s1][e1][s2][e2] = 1;
    if(rr[s1].size() != rr[s2].size()) return;

    int p1 = find(rr[s1].begin(), rr[s1].end(), e1) - rr[s1].begin();
    int p2 = find(rr[s2].begin(), rr[s2].end(), e2) - rr[s2].begin();

    int sz = size(rr[s1]);
    for(int i=1;i<sz;i++) {
        int pp1 = rr[s1][(p1 + i) % sz];
        int pp2 = rr[s2][(p2 + i) % sz];
        add_diff(pp1, s1, pp2, s2);
    }
}

int main(void) {
    scanf(" %d", &n);
    for(int i=0;i<n;i++) {
        int m;
        scanf(" %d", &m);
        rr[i].resize(m);
        for(int j=0;j<m;j++) {
            scanf(" %d", &rr[i][j]);
            rr[i][j]--;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(rr[i].size() == rr[j].size()) continue;
            for(auto a: rr[i]) {
                for(auto b: rr[j]) {
                    add_diff(a, i, b, j);
                }
            }
        }
    }

    cout << (int)diff[1][2][3][4] << endl;
    return 0;
}
