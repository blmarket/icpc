#include <algorithm>
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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 
template<typename T1> void setbit(T1 &a, int pos) { a |= (1LL<<pos); }
template<typename T1> void zerobit(T1 &a, int pos) { a &= ~(1LL<<pos); }
template<typename T1> bool getbit(T1 &a, int pos) { return (a>>pos)&1; }

int n;
char lane[54];
int spd[55],pos[55];
set<int> links[55];

struct asdf
{
    int up,down;
    bool flag;
    int pa,pb;

    bool operator<(const asdf &rhs) const
    {
        long long t1 = (long long)up * rhs.down;
        long long t2 = (long long)down * rhs.up;
        if(t1 == t2) return flag > rhs.flag;
        return t1 < t2;
    }
};

vector<asdf> moves;
vector<long long> masks;

void crash(int a,int b)
{
    int relspd = spd[a] - spd[b];
    if(pos[a] <= pos[b]-5)
    {
        int elaspdist = pos[b]-5-pos[a];
        asdf tmp;
        tmp.up = elaspdist;
        tmp.down = relspd;
        tmp.flag = false;
        tmp.pa = a;
        tmp.pb = b;
        moves.pb(tmp);
    }
    if(pos[a] <= pos[b]+5)
    {
        int elaspdist = pos[b]+5 - pos[a];
        asdf tmp;
        tmp.up = elaspdist;
        tmp.down = relspd;
        tmp.flag = true;
        tmp.pa = a;
        tmp.pb = b;
        moves.pb(tmp);
    }
}

map<long long, int> memo[2505];
int go(int a, long long state)
{
    cout << "::" << a << " " << state << endl;
    if(a == moves.size())
        return moves.size();

    long long mask = 0;
    if(masks.size() <= a)
    {
        for(int i=0;i<n;i++)
        {
            if(links[i].size())
                setbit(mask, i);
        }
        masks.pb(mask);
    }
    else
    {
        mask = masks[a];
    }
    state = state & mask;

    if(memo[a].count(state) != 0)
        return memo[a][state];

    asdf &cur = moves[a];
    links[cur.pa].insert(cur.pb);
    links[cur.pb].insert(cur.pa);

    int ret = a;
    for(int i=0;i<=1;i++)
    {
        if(getbit(mask, cur.pa) && getbit(state, cur.pa) != i) continue;
        for(int j=0;j<=1;j++)
        {
            if(getbit(mask, cur.pb) && getbit(state, cur.pb) != j) continue;
            if(i == j) continue;
            cout << i << " " << j << endl;
            if(i) setbit(state, cur.pa); else zerobit(state, cur.pa);
            if(j) setbit(state, cur.pb); else zerobit(state, cur.pb);
            int tmp = go(a+1, state);
            if(ret < tmp) ret = tmp;
        }
    }

    links[cur.pa].erase(cur.pb);
    links[cur.pb].erase(cur.pa);

    return memo[a][state] = ret;
}

void process(int dataId)
{
    scanf("%d",&n);
    moves.clear();
    masks.clear();
    for(int i=0;i<2500;i++)
        memo[i].clear();
    long long state = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%c %d %d",&lane[i],&spd[i],&pos[i]);
        if(lane[i] == 'R')
        {
            setbit(state, i);
        }
        links[i].clear();
    }

    set<int> links[55];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(pos[i] - pos[j]) < 5)
            {
                links[i].insert(j);
                links[j].insert(i);
            }
            if(spd[i] == spd[j]) continue;
            if(spd[i] > spd[j]) crash(i,j);
            else crash(j,i);
        }
    }
    sort(moves.begin(), moves.end());
    cout << go(0, state) << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
