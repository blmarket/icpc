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

int n,m;
int sum[105][105], diff[105][105];

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
            fprintf(stderr, "%5d ",diff[i][j]);
        }
        fprintf(stderr, "\n");
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
