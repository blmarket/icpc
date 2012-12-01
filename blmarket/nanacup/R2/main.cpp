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

int n,m;
int sum[105][105], diff[105][105];
bool check(int x, int y) { return x>=0 && y>=0 && x<n && y<m; }

struct moim_t;
moim_t *moim[105][105];

struct moim_t {
    int sum;
    int diff;

    int headx, heady;

    moim_t(int sum, int diff,int x, int y) : sum(sum), diff(diff), headx(x), heady(y) {}

    void forall(function<void(int, int)> f, function<void(int, int)> others) {
        bool visit[105][105];
        memset(visit, 0, sizeof(visit));
        function<void(int, int)> func = [&](int a, int b) {
            if(visit[a][b]) return;
            visit[a][b] = true;
            for(int i=0;i<4;i++) {
                int nx = a + dx[i];
                int ny = b + dy[i];
                if(check(nx, ny) == false) continue;
                if(moim[nx][ny] != moim[a][b]) {
                    others(nx, ny);
                    continue;
                }
                func(nx, ny);
            }
            f(a,b);
        };
        func(headx, heady);
    }

    void merge(moim_t *rhs) {
        if(this == rhs) return;
        rhs->forall([&](int a, int b) {
            moim[a][b] = this;
        }, [](int,int){});
        sum += rhs->sum;
        diff += rhs->diff;
        delete rhs;
    }
};

void expansion(int a, int b) {
    vector<PII> near;

    moim[a][b]->forall([](int,int){ },[&](int a, int b) {
        near.pb(mp(a,b));
    });

    int pick = rand() % size(near);
    auto it = near[pick];
    moim[a][b]->merge(moim[it.first][it.second]);

    if(moim[a][b]->diff <= 0) return expansion(a,b);
}

bool try_equalize(int target) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(moim[i][j]->sum > target*5) return false;
        }
    }
    cerr << target << endl;
    return true;
}

int main(void)
{
    if(scanf("%d %d",&n, &m) == -1) return -1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(scanf("%d", &sum[i][j]) == -1) return -1;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp;
            if(scanf("%d", &tmp) == -1) return -1;
            diff[i][j] = sum[i][j] - tmp;
            sum[i][j] += tmp;
            moim[i][j] = new moim_t(sum[i][j], diff[i][j], i, j);
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

    for(int i=100;;i+=100) {
        if(try_equalize(i)) {
            break;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            fprintf(stderr, "%6d ", moim[i][j]->sum);
        }
        fprintf(stderr,"\n");
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
