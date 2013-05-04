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

int N,X,Y;

void process(void) {
    scanf("%d %d %d",&N, &X, &Y);
    Y = 20;
    int layer = (abs(X) + abs(Y)) / 2;
    if(layer == 0) {
        cout << "1.0" << endl;
        return;
    }
    layer--;
    int minrange = (2*layer+1) * (layer+1);
    layer++;
    int maxrange = (2*layer+1) * (layer+1);

    cerr << "maxrange = " << maxrange << endl;

    if(N <= minrange) {
        cout << "0.0" << endl;
        return;
    }
    if(N >= maxrange) {
        cout << "1.0" << endl;
        return;
    }

    if(X == 0) {
        cout << "0.0" << endl;
        return;
    }

    int given = N - minrange;

    cout << "???" << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
