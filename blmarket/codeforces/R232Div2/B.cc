#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        int div = a / b;
        if((long long)c * div >= a) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
