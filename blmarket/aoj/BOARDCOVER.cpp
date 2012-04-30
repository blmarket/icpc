#include <iostream>
#include <list>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
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

int mmm(const string &str)
{
    int ret = 0;
    for(int i=0;i<size(str);i++)
    {
        ret <<= 1;
        if(str[i] == '#')
            ret |= 1;
    }
    return ret;
}

map<int,int> step[2];
int n,m;

bool chk(int mask, int pos)
{
    if(pos < 0 || pos >= m) return true;
    return (mask & (1<<pos)) != 0;
}

void set(int &mask, int pos)
{
    mask ^= (1<<pos);
}

struct bitout
{
    bitout(int a) { data = a; }
    int data;
};

ostream& operator<<(ostream &ost, const bitout &a)
{
    for(int i=0;i<m;i++)
        ost << ((a.data & (1<<i))!=0?1:0);
    return ost;
}

void iterate(int pos, int mask, int cnt, int nmask, map<int,int> &ret)
{
    if(pos == m)
    {
        ret[nmask] += cnt;
        return;
    }
    if(chk(mask, pos)) return iterate(pos+1, mask, cnt, nmask, ret);
    if(chk(nmask, pos)) return;
    set(nmask, pos);
    cout << bitout(nmask) << endl;
    if(chk(nmask, pos-1) == false)
    {
        set(nmask, pos-1);
        iterate(pos+1, mask, cnt, nmask, ret);
        set(nmask, pos-1);
    }
    if(chk(nmask, pos+1) == false)
    {
        set(nmask, pos+1);
        iterate(pos+1, mask, cnt, nmask, ret);
        set(nmask, pos+1);
    }
    set(nmask, pos);
    if(chk(mask, pos+1) == false)
    {
        if(chk(nmask, pos))
        {
            set(nmask, pos);
            iterate(pos+2, mask, cnt, nmask, ret);
            set(nmask, pos);
        }
        if(chk(nmask, pos+1))
        {
            set(nmask, pos+1);
            iterate(pos+2, mask, cnt, nmask, ret);
            set(nmask, pos+1);
        }
    }
}

void process(int dataId)
{
    cin >> n >> m;
    string str;
    cin >> str;
    int mask = mmm(str);
    step[1][mask] = 1;
    for(int i=1;i<n;i++)
    {
        map<int,int> &cur = step[i%2];
        map<int,int> &next = step[(i+1)%2];

        next.clear();
        cin >> str;
        int nmask = mmm(str);

        cout << i << endl;
        foreach(it, cur)
        {
            iterate(0, it->first, it->second, nmask, next);
        }
    }
    cout << step[n%2][(1<<m)-1] << endl;
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
