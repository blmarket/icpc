#include <iostream>
#include <vector>
#include <cstdio>

#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

int n;

long long sol2() {
    int x1;
    switch(n % 4) {
        case 0:
            x1 = n;
            break;
        case 1:
            return n;
        case 2:
            x1 = n + 1;
            break;
        case 3:
            return 0;
    }

    long long bigbit = 1;
    while(bigbit <= x1) {
        bigbit <<= 1;
    }
    bigbit >>= 1;
    return n - bigbit + 1;
}

int main(void) {
    scanf("%d", &n);
    long long r1 = n;
    r1 = r1*(r1+1) / 2;

    cout << r1 << " " << sol2() << endl;
}
