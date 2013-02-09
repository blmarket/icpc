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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N;
int A[105];

void process() 
{
    long long ret = 1;
    int prevline = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        int tmp;
        scanf("%d", &tmp);
        A[i] = tmp;
        ret++;
        for(int j=0;j<=tmp;j++) {
            ret += prevline;
            if(j>0) prevline++;
        }
        prevline++;
    }
    cout << ret << endl;
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        process();
    }
}
