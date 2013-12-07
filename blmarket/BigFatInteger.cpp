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

vector<int> primes;

class BigFatInteger 
{
public:
    int minOperations(int A, int B) 
    {
        primes.clear();
        VI qs;
        for(int i=2;i*i <= A;i++) {
            bool fail = false;
            for(int j=0;j<size(primes);j++) {
                if((i%primes[j]) == 0) {
                    fail = true;
                    break;
                }
            }
            if(fail) continue;
            primes.pb(i);
            int cnt = 0;
            while((A%i) == 0) {
                cnt++;
                A /= i;
            }
            if(cnt == 0) continue;
            qs.pb(cnt);
        }
        if(A != 1) qs.pb(1);
        sort(qs.rbegin(), qs.rend());

        for(int i=0;i<size(qs);i++) cout << qs[i] << " ";
        cout << endl;

        long long cc = (long long)B * qs[0] - 1;
        int ret = size(qs);
        int cut = 1;
        while(cc) {
            if(cc >= cut) {
                cc -= cut;
                cut *= 2;
                ret++;
            } else {
                return ret + 1;
            }
        }
        return ret;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
