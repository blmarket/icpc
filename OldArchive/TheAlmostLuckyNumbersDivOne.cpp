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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

LL pure(LL a)
{
    if(a<4) return 1;
    if(a<7) return 2;
    if(a<10) return 3;
    return pure(a/10) * (pure(a%10) + 1);
}

bool ispure(LL a)
{
    return false;
}

LL go(LL a)
{
    if(a<10) return a;
    if(a%10 < 4)
    {
        return go(a/10) + pure(a/10)*10 - ispure(a/10)?2:0;
    }
    if(a%10 < 7)
    {
        return go(a/10)*2 + pure(a/10)*10 - ispure(a/10)?1:0;
    }
    return go(a/10)*3 + pure(a/10)*10;
}

class TheAlmostLuckyNumbersDivOne 
{
public:
    long long find(long long a, long long b) 
    {		
        cout << pure(b) << " " << pure(a-1) << endl;
        cout << go(b) << " " << go(a-1) << endl;
        return go(b) - go(a-1);
    }
};
