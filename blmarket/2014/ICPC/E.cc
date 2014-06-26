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
int diff[105][105][105][105];

int main(void) {
    scanf(" %d", &n);
    for(int i=0;i<n;i++) {
        int m;
        scanf(" %d", &m);
        rr[i].resize(m);
        for(int j=0;j<m;j++) {
            scanf(" %d", &rr[i][j]);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(rr[i].size() == rr[j].size()) continue;
            for(int a=0;a<size(rr[i]);a++) {
                for(int b=0;b<size(rr[j]);b++) {
                }
            }
        }
    }
    return 0;
}
