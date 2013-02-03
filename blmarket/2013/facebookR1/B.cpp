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

int m,l;
string k1, k2;
string block1[105], block2[105];
bool links[105][105];

bool matches(const string &a, const string &b) {
    for(int i=0;i<l;i++) {
        if(a[i] == '?' || b[i] == '?') continue;
        if(a[i] != b[i]) return false;
    }
    return true;
}

void assign(const string &a, string target[]) {
    for(int i=0;i<m;i++) {
        target[i] = a.substr(i*l, l);
    }
}

bool visit[105];
int back[105];

bool check_flow(int a) {
    if(visit[a]) return false;
    visit[a] = true;
    for(int i=0;i<m;i++) if(links[a][i]) {
        if(back[i] == -1 || check_flow(back[i])) {
            back[i] = a;
            return true;
        }
    }
    return false;
}


bool try_flow() {
    memset(back, -1, sizeof(back));
    for(int i=0;i<m;i++) {
        memset(visit, 0, sizeof(visit));
        if(check_flow(i) == false) return false;
    }
    return true;
}

void process(void) {
    char buff[1024];
    scanf("%d", &m);
    scanf(" %s",buff);
    k1 = buff;
    l = size(k1) / m;
    scanf(" %s", buff);
    k2 = buff;
    assign(k1, block1);
    assign(k2, block2);

    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            links[i][j] = matches(block1[i], block2[j]);
        }
    }

    if(try_flow() == false) {
        printf("IMPOSSIBLE\n");
        return;
    }
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        process();
    }
}
