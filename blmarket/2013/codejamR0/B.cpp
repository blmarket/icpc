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

string toString(LL a) { ostringstream ost; ost << a; return ost.str(); } 
bool chkpalin(const string &a) { 
    for(int i=0;i*2<size(a);i++) {
        if(a[i] != a[size(a)-1-i]) return false;
    }
    return true;
}

void candidate(const string &candi) {
    cout << candi << endl;
}

bool chkgood(const string &a) {
    bool ret = false;
    int sum = 0, mid = 0;
    for(int i=0;i<size(a);i++) {
        sum += sqr(a[i]-'0') * 2;
    }
    mid = sqr(a[size(a)-1] - '0');

    string tmp = a;
    reverse(tmp.begin(), tmp.end());
    if(sum < 10) {
        ret = true;
        candidate(a + tmp);
    }
    sum -= mid;
    if(sum < 10) {
        ret = true;
        candidate(a + tmp.substr(1));
    }
    return ret;
}

void precalc() {
    for(int i=1;i<=100000;i++) {
        chkgood(toString(i));
    }
    cout << endl << endl;

    for(long long i=1;i<=100000;i++) {
        if(chkpalin(toString(i)) == false) continue;
        if(chkpalin(toString(i*i))) {
            cout << i << " : " << i*i << endl;
        }
    }
}

int A,B;
void process(void) {
    scanf("%d %d", &A, &B);
}

int main(void)
{
    precalc();
    return 0;
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}
