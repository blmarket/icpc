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

long double p;
long double RR[25];

int combi[25][25];

long double process() {
    RR[0] = 0;
    long double q = (1.-p);
    for(int i=1;i<=20;i++) {
        for(int k=0;k<=i;k++) {
        }
    }
}

int main(void) {
    for(int i=0;i<25;i++) {
        combi[i][0] = combi[i][i] = 1;
        for(int j=1;j<i;j++) {
            combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
        }
    }
    cout << combi[20][10] << endl;
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        scanf(" %Lf", &p);
        long double ret = process();
        printf("Case #%d: %.12Lf\n", ret);
    }
    return 0;
}
