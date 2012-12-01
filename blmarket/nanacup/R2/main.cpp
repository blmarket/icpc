#include <iostream>
#include <algorithm>
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

const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};

struct moim_t {
    int sum;
    int diff;

    moim_t(int sum, int diff) : sum(sum), diff(diff) {}
};

int n,m;
int sum[105][105], diff[105][105];
moim_t *moim[105][105];

bool visit[105][105];
void go(int a, int b) {
    if(visit[a][b]) return;
    visit[a][b] = true;
}

void expansion(int a, int b) {
    memset(visit, 0, sizeof(visit));
    function<void(int, int)> func = [visit, func](int a, int b) {
        if(visit[a][b]) return;
        func(a,b);
    };
}

int main(void)
{
    scanf("%d %d",&n, &m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &sum[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp;
            scanf("%d", &tmp);
            diff[i][j] = sum[i][j] - tmp;
            sum[i][j] += tmp;
            moim[i][j] = new moim_t(sum[i][j], diff[i][j]);
            fprintf(stderr, "%5d ",diff[i][j]);
        }
        fprintf(stderr, "\n");
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(moim[i][j]->diff <= 0) {
                expansion(i,j);
            }
        }
    }

    cout << 1 << endl;
    cout << n*m << " ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << i << " " << j << " ";
        }
    }
    cout << endl;
}
