#include <iostream>
#include <cstdio>
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

set<PII> cur, nex;

PII move(PII cur, int a, int b) {
    cur.first = abs(cur.first + a);
    cur.second = abs(cur.second + b);
    if(cur.first < cur.second) swap(cur.first, cur.second);
    cout << cur.first << "," << cur.second << endl;
    return cur;
}

void process(void) {
    cur.insert(mp(0,0));
    for(int i=1;i<=5;i++) {
        nex.clear();
        for(auto it : cur) {
            printf("%d %d\n", it.first, it.second);
            nex.insert(move(it, i, 0));
            nex.insert(move(it, -i, 0));
            nex.insert(move(it, 0, i));
            nex.insert(move(it, 0, -i));
        }
        printf("\n");
        cur.swap(nex);
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
