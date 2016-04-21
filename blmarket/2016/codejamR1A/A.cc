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

char str[1024];
string src;

string go(int len) {
    if(len == 0) {
        return "";
    }

    char maxc = 0;
    int mp = 0;
    for(int i=0;i<len;i++) {
        if(str[i] >= maxc) {
            maxc = str[i]; 
            mp = i;
        }
    }

    return string(1, maxc) + go(mp) + src.substr(mp + 1);
}

void process(void) {
    scanf(" %s", str);
    src = str;

    cout << go(src.size()) << endl; 
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
