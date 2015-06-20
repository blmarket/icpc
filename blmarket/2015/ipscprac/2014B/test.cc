#include <iostream>
#include <unordered_set>

using namespace std;

long long x[50];
int c[50];

long long mod(long long a) {
    return a % (1LL << 32);
}

int main(void) {
    for(int i=0;i<=42;i++) {
        x[i] = mod(mod(mod(i*i)*i)*999999999LL);
    }

    int it = 43;

    for(int i=0;i<10;i++) {
        x[it] = x[(it-22+50)%50] - x[(it-43+50)%50] - c[(it-1+50)%50];
        c[it] = x[it] < 0 ? 1 : 0;

        cout << x[it] << " " << c[it] << endl;
        it = (it+1) % 50;
    }

}
