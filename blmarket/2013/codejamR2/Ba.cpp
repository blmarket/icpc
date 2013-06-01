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

int n;

long long getworst(long long nn, long long a) {
    if(a == 0) return 0;
    if(a & 1) {
        return (nn/2) + getworst(nn / 2, a / 2);
    } else {
        return (nn/2) + getworst(nn / 2, (a-1) / 2);
    }
}

long long getbest(long long nn, long long a) {
    if(a == nn-1) return nn-1;

    if(a & 1) {
        return getbest(nn/2, (a+1)/2);
    } else {
        return getbest(nn/2, a/2);
    }
}

void process(void) {
    long long p;
    long long nn;
    cin >> n >> p;
    nn = (1LL << n);

    if(p == nn) {
        cout << nn-1 << " " << nn-1 << endl;
        return;
    }

    long long s=0, e=nn;
    while(s+1<e) {
        long long m = (s+e) / 2;
        if(getworst(nn, m) >= p) {
            e = m;
        } else {
            s = m+1;
        }
    }

    cout << e-1 << " ";

    s=0, e=nn;

    while(s+1<e) {
        long long m = (s+e) / 2;
        if(getbest(nn, m) >= p) {
            e = m;
        } else {
            s = m+1;
        }
    }
    cout << e-1 << endl;
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
