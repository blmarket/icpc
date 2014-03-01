#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define mp make_pair
#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

typedef pair<int, int> PII;

int n,m;
bool used1[10000], used2[10000];

double memo[2005][2005];

double go(int a, int b) {
    if(a > n || b > n) return 0;
    if(memo[a][b] > -0.1) return memo[a][b];

    double p1 = (double)a / n;
    double p2 = (double)b / n;

    double pp1 = p1 * p2;
    double pp2 = p1 * (1.0-p2);
    double s2 = go(a, b+1);
    double pp3 = (1.0-p1) * p2;
    double s3 = go(a+1, b);
    double pp4 = (1.0-p1) * (1.0-p2);
    double s4 = go(a+1, b+1);

    double rr = (1.0 + pp2*s2 + pp3*s3 + pp4*s4) / (1.0 - pp1);
    return memo[a][b] = rr;
}

int main(void) {
    for(int i=0;i<2005;i++) for(int j=0;j<2005;j++) memo[i][j] = -1;

    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        used1[a] = true;
        used2[b] = true;
    }

    int c1 = 0, c2 = 0;
    for(int i=0;i<n;i++) c1 += used1[i], c2 += used2[i];

    printf("%.12lf\n", go(c1, c2));

    return 0;
}
