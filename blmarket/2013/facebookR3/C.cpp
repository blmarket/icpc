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

int N,K,C;
int R[1120][1120];
LL f1[1120 * 1120], f2[1120 * 1120];

void input(void) {
    int x1,a1,b1,m1;
    int x2,a2,b2,m2;

    scanf("%d %d %d", &N, &K, &C);
    scanf("%d %d %d %d", &x1, &a1, &b1, &m1);
    scanf("%d %d %d %d", &x2, &a2, &b2, &m2);

    f1[0] = x1; f2[0] = x2;

    for(int i=1;i<N;i++) {
        f1[i] = (f1[i-1] * a1 + b1) % m1;
        f2[i] = (f2[i-1] * a2 + b2) % m2;
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) if(i != j) {
            if(i > j) R[i][j] = f1[i * (i-1) / 2 + j];
            if(j > i) R[i][j] = f2[j * (j-1) / 2 + i];
        }
    }
}

void process(void) {
    input();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}
