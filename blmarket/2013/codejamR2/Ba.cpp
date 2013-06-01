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

    if(p+1 == nn) {
        cout << nn-1 << " " << nn-1 << endl;
        return;
    }

    for(int i=0;i<n;i++) {
        if(getworst(nn, i) >= p) {
            cout << i-1 << " ";
            break;
        }
    }

    for(int i=0;i<n;i++) {
        if(getbest(nn, i) >= p) {
            cout << i-1 << endl;
            break;
        }
    }
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
