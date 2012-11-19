#include <iostream>
#include <list>
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

int n,l;
int sums[1005][1005];

void process(int dataId)
{
    double minimalist = 999;
    
    scanf("%d %d", &n, &l);
    for(int i=0;i<n;i++) {
        scanf(" %d",&sums[i][i+1]);
    }

    for(int i=2;i<=n;i++) {
        int minsum = 9990000;
        for(int j=0;j+i<=n;j++) {
            sums[j][j+i] = sums[j][j+i-1] + sums[j+i-1][j+i];
            if(minsum > sums[j][j+i]) minsum = sums[j][j+i];
        }
        if(i >= l) {
            double tmp = (double)minsum / i;
            if(tmp < minimalist) minimalist = tmp;
        }
    }
    
    printf("%.12lf\n", minimalist);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
