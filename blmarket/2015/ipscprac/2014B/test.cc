#include <iostream>
#include <unordered_set>

using namespace std;

long long x[50];
int c[50];

long long mod(long long a) {
    return a % (1LL << 32);
}

int it = 43;
long long next() {
    x[it] = x[(it-22+50)%50] - x[(it-43+50)%50] - c[(it-1+50)%50];
    c[it] = x[it] < 0 ? 1 : 0;
    x[it] += c[it] * (1LL << 32);

    long long ret = x[it];
    it = (it+1) % 50;
    return ret;
}

int main(void) {
    for(int i=0;i<=42;i++) {
        x[i] = mod(mod(mod(i*i)*i)*999999999LL);
    }

    int it = 43;

    for(int i=0;i<10;i++) {
        cout << next() << endl;
    }

}
