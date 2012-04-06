#include <iostream>
#include <queue>
#include <set>
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

long long sum=0;

int main(void)
{
    long long n;
    cin >> n;
    cout << n*2+1 << endl;
    return 0;
    for(long long i=1;;i++)
    {
        sum += i;
        if((i+1)*n == sum)
        {
            cout << i+1 << endl;
            return 0;
        }
    }
}
