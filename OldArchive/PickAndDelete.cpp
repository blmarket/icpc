#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

#define MOD 1000000007LL

vector<int> V;
map<pair<int,int>, LL> memo;
LL inverse[505];
LL facto[505];
LL invfacto[505];

int power(int a, int b)
{
    LL ret = 1;
    LL aa = a;
    while(b)
    {
        if(b & 1) ret = (ret * aa) % MOD;
        aa = (aa * aa) % MOD;
        b>>=1;
    }
    return ret;
}

void precalc()
{
    inverse[1] = 1;
    facto[1] = 1;
    invfacto[1] = 1;
    facto[0] = 1;
    invfacto[0] = 1;
    for(int i=2;i<505;i++)
    {
        LL num = i;
        LL tmp = MOD - 2;
        inverse[i] = 1;

        while(tmp)
        {
            if(tmp & 1) 
                inverse[i] = (inverse[i] * num) % MOD;
            num = (num * num) % MOD;
            tmp >>= 1;
        }

        facto[i] = (facto[i-1] * i) % MOD;
        invfacto[i] = (invfacto[i-1] * inverse[i]) % MOD;
    }
}

int H(int a,int b)
{
    int n = a+b-1;
    LL ret = (facto[n] * invfacto[n-b]) % MOD;
    ret = (ret * invfacto[b]) % MOD;
    return ret;
}

LL go(int s, int c)
{
    if(V[s] == 0) return !(c-1);

    if(V[s] == V[s+1])
        return go(s+1, c+1);

    if(memo.count(mp(s,c)) != 0) return memo[mp(s,c)];

    int diff = V[s] - V[s+1];

    LL ret = 0;
    LL pow = 1;
    for(int i=c;i>=0;i--)
    {
        // total used = size(V) - s - 1 + i
        LL tmp = (go(s+1, i+1) * pow) % MOD;
        tmp = (tmp * H(size(V)-s-1+i, c-i)) % MOD;
        ret = (ret + tmp) % MOD;

        pow = (pow * diff) % MOD;
    }

    return memo[mp(s,c)] = ret;
}

class PickAndDelete 
{
public:
    int count(vector <string> S) 
    {		
        precalc();
        V.clear();
        string ss;
        for(int i=0;i<size(S);i++) ss += S[i];
        istringstream sin(ss);
        int tmp;
        while(sin >> tmp) V.pb(tmp);

        sort(V.rbegin(), V.rend());
        V.pb(0);

        cout << size(V) << endl;

        return go(0, 1);
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
