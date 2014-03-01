#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> PII;

int tree[30005];
vector<int> childs[300005];

int pos = 0;
PII ranges[300005];

PII go(int a) {
    int mypos = pos++;
    for(int i=0;i<childs[a].size();i++) {
        go(childs[a][i]);
    }
    return ranges[a] = mp(mypos, pos);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i=2;i<=n;i++) {
        scanf("%d", &tree[i]);
        childs[tree[i]].pb(i);
    }

    go(1);
    for(int i=1;i<=n;i++) {
        cout << ranges[i].first << "," << ranges[i].second << endl;
    }
    return 0;




    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
        } else {
            int a;
            long long ret = 0;
            scanf("%d", &a);
        }
    }


    return 0;
}
