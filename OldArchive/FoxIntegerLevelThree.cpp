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

int d(LL a)
{
    LL tmp = 0;
    while(a) { tmp += (a % 10); a/=10; }
    if(tmp < 10) return tmp;
    return d(tmp);
}

LL go(LL a)
{
    if(a==0) return 0;

    LL ret = 0;

    LL t1 = (a / 9)*9+1;
    if(t1 > a) t1 -= 9;
    if(t1 < 0) t1 = 0;

    ret += (t1 - 1 + 9) / 9;

    cout << ret << endl;

    LL t4 = (a / 9) * 9 + 4;
    if(t4 > a) t4 -= 9;
    if(t4 < 0) t4 = 0;

    ret += (t4 - 4 + 18) / 18 + (t4 - 49 + 63) / 63 - (t4 - 112 + 126) / 126;

    cout << ret << endl;

    LL t7 = (a / 9) * 9 + 7;
    if(t7 > a) t7 -= 9;
    if(t7 < 0) t7 = 0;

    ret += (t7 - 16 + 36) / 36 + (t7 - 25 + 45) / 45 - (t7 - 160 + 180) / 180;

    cout << ret << endl;

    LL t9 = (a / 9) * 9 + 9;
    if(t9 > a) t9 -= 9;
    if(t9 < 0) t9 = 0;

    ret += (t9 - 9 + 27) / 27 + (t9 - 81 + 81) / 81;

    cout << ret << endl;

    cout << t1 << " " << t4 << " " << t7 << " " << t9 << endl;

    return ret;
}

class FoxIntegerLevelThree 
{
public:
    long long count(long long min, long long max) 
    {		
        return go(max) - go(min-1);
    }
};
