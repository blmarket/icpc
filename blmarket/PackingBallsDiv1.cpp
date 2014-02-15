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

template<typename T> int size(const T &a) { return a.size(); }

int V[100005];
int K;
priority_queue<PII> Q;

int go(int nvar) {
    int ret = 0;
    for(int i=0;i<K;i++) if(V[i] > nvar) {
        ret += (V[i] - nvar + K - 1) / K;
    }
    return nvar + ret;
}

class PackingBallsDiv1 
{
public:
    int minPacks(int K_, int A, int B, int C, int D) 
    {		
        K = K_;
        V[0] = A;
        for(int i=1;i<K;i++) {
            V[i] = ((long long)V[i-1] * B + C) % D + 1;
        }

        sort(V, V+K);

        vector<int> VV;
        for(int i=0;i<K;i++) VV.pb(V[i] % K);

        sort(VV.begin(), VV.end());
        int minn = 99999;
        int mx = 0;
        int dff = 0;
        int lp = 0;

        for(int i=0;i<size(VV);i++) {
            cout << VV[i] << " ";
            dff--;
            if(dff < minn) {
                minn = dff;
                mx = lp;
            }
            if(VV[i] == lp) continue;
            dff += (VV[i] - lp);
            lp = VV[i];
        }
        cout << endl;

        return go(mx);
    }
};

int main(void) {
    for(int i=0;i<20;i++) {
        PackingBallsDiv1 aa;
        int a,b,c,d;
        a = rand() % 6; a += 1;
        b = rand() % 555; b += 1;
        c = rand() % 3;
        d = rand() % 666; d += a;
        aa.minPacks(6, a,b,c,d);
        cout << a << " " << b << " " << c << " " << d << endl;
    }
}



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
