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

string s;
long long base = 0;
int pp;

long long trial(const string &s) {
    int cs = 0;
    long long ret = -1;

    for(int i=1;i<size(s);i++) {
        long long tmp;
        if(s[i] == '0') {
            cs++;
        } else {
            cs = 0;
        }
        if(cs+1 == size(s) && s[0] == '0') return 0;
        tmp = (size(s) - 1 - i) * 2 + (pp-1)*size(s) + (i - cs);
        if(ret == -1 || ret > tmp) ret = tmp;
    }
    return ret;
}

long long process() {
    if(size(s) == 1 && s[0] == '0') return 0;
    if(size(s) == 1) return pp-1;
    long long tmp = trial(s);
    reverse(s.begin() + 1, s.end());
    long long tmp2 = trial(s);
    return min(tmp, tmp2);
}

int main(void) {
    int T;
    char str[1024];
    scanf("%d", &T);
    for(int i=0;i<T;i++) {
        scanf(" %s %d", str, &pp);
        s = string(str);
        base = 0;
        for(int j=0;j<size(s);j++) {
            base += min(s[j] - '0', 10 - s[j] + '0');
        }
        base *= pp;
        cout << base + process() + 1 << endl;
    }
    return 0;
}
