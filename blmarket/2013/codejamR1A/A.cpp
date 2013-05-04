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

const double pi = M_PI;

vector<double> paint;

long long r,t;

void process(void) {
    cin >> r >> t;

    long long sum = 0;
    for(int i=1;;i++) {
        sum += sqr(r+1) - sqr(r);
        if(sum > t) {
            cout << i-1 << endl;
            break;
        }
        r += 2;
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        // cerr << i << endl;
    }
}
