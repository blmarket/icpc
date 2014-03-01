#include <iostream>
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

int mod = 1000000007;

int n;
vector<int> primes;
vector<int> np;
map<int, int> px;

long long inv[505];

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

        cout << "1/2" << " - 1/" << nn << endl;
        cout << nn2 << " " << nn << endl;

        while(nn > n) {
            cout << "-" <<  nn2 << " " << nn << endl;
        }
    }
    
    return 0;
}
