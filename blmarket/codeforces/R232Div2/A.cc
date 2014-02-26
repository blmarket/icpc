#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
bool used[105];

int main(void) {
    memset(used, 0, sizeof(used));
    scanf("%d", &n);
    int s,e;
    scanf(" %d %d", &s, &e);

    for(int i=0;i<n;i++) {
        int a,b;
        scanf(" %d %d", &a, &b);
        for(int j=a;j<b;j++) used[j] = true;
    }

    int ret = 0;
    for(int i=s;i<e;i++) if(!used[i]) ret++;
    printf("%d\n", ret);
    return 0;
}
