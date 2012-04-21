#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
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

#define MOD 1000000007

typedef map<pair<vector<int>,int>, int> memo_t;
memo_t memo;
string str;
vector<int> vals;
int nn[10];
int n,m;

int go(int cur, int pos, vector<int> &elasp, bool chk)
{
    if(pos == n) 
    {
        return !chk && (cur == 0);
    }
    if(chk == false)
    {
        memo_t::iterator iter = memo.find(mp(elasp, cur));
        if(iter != memo.end()) return iter->second;
    }

    int ret = 0;
    for(int i=0;i<10;i++) if(elasp[i])
    {
        if(chk && vals[pos] < i) continue;
        elasp[i]--;
        ret += go((cur*10+i) % m,pos+1, elasp, chk && vals[pos] == i);
        ret %= MOD;
        elasp[i]++;
    }
    if(chk) return ret;
    return memo[mp(elasp, cur)] = ret;
}

void solve(int dataId)
{
    vector<int> tmp;
    for(int i=0;i<10;i++) tmp.pb(nn[i]);
    cout << go(0, 0, tmp, true) << endl;
}

void process(int dataId)
{
    cin >> str >> m;
    n = size(str);
    vals.clear();
    memset(nn, 0, sizeof(nn));
    for(int i=0;i<n;i++)
    {
        vals.pb(str[i]-'0');
        nn[vals.back()]++;
    }
    memo.clear();
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
        solve(i);
    }
}
