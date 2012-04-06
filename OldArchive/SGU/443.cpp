#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define sqr(x) ((x)*(x))

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

vector<int> primes;

int main(void)
{
    for(int i=2;i<100000;i++)
    {
        bool isprime = true;
        for(int j=0;j<primes.size();j++)
        {
            if(primes[j]*primes[j] > i) break;
            if((i % primes[j]) == 0)
            {
                isprime = false;
                break;
            }
        }
        if(isprime)
            primes.push_back(i);
    }

    int a,b;
    cin >> a >> b;

    vector<int> pa,pb;
    pa.clear();
    pb.clear();
    for(int i=0;i<primes.size();i++)
    {
        if((a % primes[i]) == 0)
        {
            pa.push_back(primes[i]);
        }
        if((b % primes[i]) == 0)
        {
            pb.push_back(primes[i]);
        }
    }
    int sa = pa.back(),sb = pb.back();
    for(int i=0;i<pa.size()-1;i++)
    {
        sa -= pa[i];
    }
    for(int i=0;i<pb.size()-1;i++)
        sb -= pb[i];

    if(sa > sb) cout << "a" << endl; else cout << "b" << endl;
}
