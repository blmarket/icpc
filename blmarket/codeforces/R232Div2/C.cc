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

vector<long long> memo[505];

long long go(int a, int b) {
    if(a == 1) return 1;
    if(memo[a].size() <= b) memo[a].resize(b+1, -1);
    if(memo[a][b] != -1) return memo[a][b];

    long long ret = 0;
    for(int i=0;i<=b;i++) {
        ret += go(a-1, b-i);
        if(ret > mod) ret -= mod;
    }
    return memo[a][b] = ret;
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
    
    np.resize(primes.size());
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int tmp;
        scanf("%d", &tmp);
        for(int j=0;j<size(primes);j++) {
            if(tmp < primes[j]) break;
            while(tmp % primes[j] == 0) {
                tmp /= primes[j];
                np[j]++;
            }
        }
        if(tmp > 1) {
            px[tmp] += 1;
        }
    }

    for(int i=0;i<size(primes);i++) if(np[i]) px[primes[i]] = np[i];

    long long ret = 1;
    for(auto &it : px) {
        cout << it.first << " " << it.second << endl;
        ret = (ret * go(n, it.second)) % mod;
    }

    cout << ret << endl;

    return 0;
}
