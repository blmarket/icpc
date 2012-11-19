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
vector<int> V;

void process(int dataId)
{
    double minimalist = 999;
    
    scanf("%d %d", &n, &l);
    V.resize(n);
    for(int i=0;i<n;i++) {
        scanf(" %d",&V[i]);
    }

    for(int i=0;i<n;i++) {
        int cnt = 0;
        int sum = 0;
        for(int j=i;j<n;j++) {
            cnt++;
            sum += V[j];
            if(cnt >= l) {
                double tmp = (double)sum / cnt;
                if(tmp < minimalist) minimalist = tmp;
            }
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
