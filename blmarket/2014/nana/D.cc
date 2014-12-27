#include <iostream>
#include <cmath>
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

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) {
        int n;
        int x,y,r;
        scanf(" %d", &n);
        scanf(" %d %d %d", &x, &y, &r);

        double d = (double)(y - x) / 2.;
        if(fabs(d) > r) {
            cout << sqrt(200) << endl;
            continue;
        }
    }
    return 0;
}
