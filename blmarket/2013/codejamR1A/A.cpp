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

long long r,t;

void process(void) {
    cin >> r >> t;

    long long X = r * 2 + 1;

    long long s = 0, e = 707106790;

    while(s+1<e) {
        long long m = (s+e+1) / 2;
        long long tmp = X * m + m * (m-1) * 2;
        if(tmp > t) {
            e = m;
        } else {
            s = m;
        }
    }

    cout << s << endl;
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
