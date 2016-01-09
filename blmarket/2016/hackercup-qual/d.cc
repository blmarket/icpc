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

int N, K;

struct tri {
    string tag;
    tri *child[26] = {0};
    int nc = 0;
    int cost[305];

    tri() {
        memset(cost, -1, sizeof(cost));
        cost[0] = 0;
    }

    void calc() {
        if(nc == 0) {
            cost[1] = 1;
            return;
        }
        for(int i=0;i<26;i++) {
            if(!child[i]) continue;
            child[i]->calc();
            for(int j=min(nc, K);j>=1;j--) {
                for(int k=0;k<=j;k++) {
                    if(cost[k] < 0 || child[i]->cost[j-k] < 0) continue;
                    int tmp = cost[k] + 2 + child[i]->cost[j-k];
                    if(cost[j] < 0 || cost[j] > tmp) cost[j] = tmp;
                }
            }
        }
        cout << tag << " ";
        for(int i=1;i<=K;i++) {
            cout << cost[i] << " ";
        }
        cout << endl;
    }
};

tri *root;

void build(char *cur, tri *tr) {
    if(*cur == 0) return;
    tr->nc++;
    int idx = *cur - 'a';
    if(tr->child[idx] == 0) {
        tr->child[idx] = new tri();
        tr->child[idx]->tag = tr->tag + *cur;
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
    cout << root->cost[K] << endl;
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
