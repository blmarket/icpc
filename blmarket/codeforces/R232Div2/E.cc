#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int tree[30005];
int number[30005];
int reducer[30005];

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i=2;i<=n;i++) scanf("%d", &tree[i]);

    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            number[a] += b;
            reducer[a] += c;
        } else {
            int a;
            long long ret = 0;
            scanf("%d", &a);

            for(int j=0;;j++) {
                ret += number[a] - reducer[a] * j;
                if(a == 1) break;
            }

            ret %= 1000000007;
            printf("%lld\n", ret);
        }
    }


    return 0;
}
