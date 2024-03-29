#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>

#define mp make_pair
#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

typedef pair<int, int> PII;

long long gcd(long long a, long long b) {
    // if(a<b) swap(a,b);
    if(a == 0 || b==0) return a+b;
    return gcd(b, a%b);
}

struct frac {
    long long up;
    long long down;

    frac(long long up, long long down):up(up), down(down) {};
    frac& operator+=(const frac &rhs) {
        long long dd = down / gcd(down, rhs.down) * rhs.down;
        long long uu = up * (dd / down) + rhs.up * (dd / rhs.down);
        up = uu;
        down = dd;
        long long gg = gcd(abs(up), down);
        up /= gg;
        down /= gg;
        return *this;
    }
};

int mod = 1000000007;

int n;
vector<int> primes;

bool isprime(int nn) {
    for(int j=0;j<size(primes);j++) {
        if(primes[j] * primes[j] > nn) return true;
        if(nn % primes[j] == 0) return false;
    }
    return true;
}

int main(void) {
    primes.pb(2);
    for(int i=3;i<=100000;i+=2) {
        bool pp = true;
        for(int j=0;j<size(primes);j++) {
            if(primes[j]*primes[j] > i) break;
            if(i % primes[j] == 0) { pp = false; break; }
        }
        if(pp) primes.pb(i);
    }

    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++) {
        int n;
        scanf("%d", &n);
        int nn;
        int nn2;
        for(nn=n+1;isprime(nn) == false;++nn);
        for(nn2=n;isprime(nn2) == false;--nn2);

        frac ret = frac(1,2);
        ret += frac(-1, nn);

        ret += frac(-(nn-n-1), (long long)nn2 * nn);
        cout << ret.up << "/" << ret.down << endl;
    }
    
    return 0;
}
