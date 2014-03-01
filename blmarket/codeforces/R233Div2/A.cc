#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define mp make_pair
#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

typedef pair<int, int> PII;

long long arr1[10005];
long long arr2[10005];

int main(void) {
    int a,b;
    scanf("%d %d",&a, &b);

    for(int i=1;i<=a;i++) {
        int big = a-i+1;
        arr1[i] = (long long)big * big + (i - 1);
    }

    for(int i=1;i<=b;i++) {
        int av = b / i;
        int ax = b % i;

        arr2[i] = (long long)ax * (av+1) * (av+1) + (long long)(i-ax) * av * av;
    }

    if(a == 0 || b <= 1) {
        cout << arr1[a] - arr2[b] << endl;
        return 0;
    }

    long long ret = arr1[1] + arr2[1];
    for(int i=2;i<=b;i++) {
        int na = i - 1;
        long long tmp = arr1[na] - arr2[i];
        if(ret < tmp) ret = tmp;
    }

    cout << ret << endl;
    return 0;
}
