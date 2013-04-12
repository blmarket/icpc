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

bool chkgood(const string &a) {
    string tmp = a;
    reverse(tmp.begin(), tmp.end());
    tmp = a + tmp;
    cout << tmp << endl;
}

void precalc() {
    chkgood("1");
    /*
    for(long long i=1;i<=10000000;i++) {
        if(chkpalin(toString(i)) == false) continue;
        if(chkpalin(toString(i*i))) {
            cout << i << " : " << i*i << endl;
        }
    }
    */
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
