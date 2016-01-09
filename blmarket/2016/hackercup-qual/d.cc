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

struct tri {
    tri *child[26] = {0};
    int nc = 0;
    int cost[305] = {0};

    void calc() {
        for(int i=0;i<26;i++) {
        }
    }
};

int N, K;
tri *root;

void build(char *cur, tri *tr) {
    if(*cur == 0) return;
    tr->nc++;
    int idx = *cur - 'a';
    if(tr->child[idx] == 0) {
        tr->child[idx] = new tri();
    }
    build(cur + 1, tr->child[idx]);
}

void process(void) {
    scanf(" %d %d", &N, &K);

    root = new tri();

    char tmp[100005];
    for(int i=0;i<N;i++) {
        scanf(" %s", tmp);
        build(tmp, root);
    }
    root->calc();
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
