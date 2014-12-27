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

double d;
double R;

double calc(double s) {
    double dd = sqrt(s*s + d*d - R*R);

    double theta = atan( ( (s+R)/(d+dd) + (s-R)/(d-dd)) / 2);

    cout << " theta = " << theta * 180 / 3.1415926535 << endl;
    cout << d * tan(theta) + dd * acos(theta) << endl;

    return dd + theta * R;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) {
        int n;
        int x,y,r;
        scanf(" %d", &n);
        scanf(" %d %d %d", &x, &y, &r);

        d = (double)(y - x) / 2.;
        if(fabs(d) > r) {
            printf("%.12lf\n", sqrt(20000));
            continue;
        }

        R = r;

        double xx = d + x;
        double s = sqrt(2) * xx;
        double t = sqrt(2) * (100. - xx);

        d = fabs(d);
        cout << d << " " << R << " " << s << " " << t << endl;
        // calc(s) << " " << calc(t) << endl;
        printf("%.12lf\n", calc(s) + calc(t));
    }
    return 0;
}
