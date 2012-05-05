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
#include <algorithm>

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

struct frac {
    frac(int a,int b, bool f, int c, int d)
    {
        up = a;
        down = b;
        flag = f;
        pa = c;
        pb = d;
    }

    int up, down;
    bool flag;
    int pa, pb;

    bool operator<(const frac &rhs) const
    {
        long long my = (LL)up * rhs.down;
        long long opp = (LL)down * rhs.up;

        if(my != opp) return my < opp;
        return flag > rhs.flag;
    }
};

ostream& operator<<(ostream& ost, const frac &rhs)
{
    return ost << (double)rhs.up / rhs.down << " : " << rhs.flag << " " << rhs.pa << "-" << rhs.pb;
}

int n;
int spd[55], pos[55];
char lane[55];
set<int> links[55];

vector<frac> meet;

void addcol(int a,int b) // faster, slower
{
    int dspd = spd[a] - spd[b];
    if(pos[a] <= pos[b] - 5)
    {
        int dist = pos[b]-5-pos[a];
        meet.pb(frac(dist, dspd, false, a ,b));
    }
    if(pos[a] < pos[b] + 5)
    {
        int dist = pos[b] + 5 - pos[a];
        meet.pb(frac(dist, dspd, true, a ,b));
    }
}

double out(const frac &rhs)
{
    return (double)rhs.up / rhs.down;
}

bool go(int a)
{
    int oth = -3;
    if(lane[a] == -3) oth = -2;
    foreach(it, links[a])
    {
        int b = *it;
        if(lane[b] == -1)
        {
            lane[b] = oth;
            if(go(b) == false) return false;
        }
        if(lane[b] != oth) return false;
    }
    return true;
}

bool check(int a)
{
    for(int i=0;i<n;i++) if(lane[i] < 0) lane[i] = -1;
    lane[a] = -2;
    return go(a);
}

bool populate(int a)
{
    char oth = 'L';
    if(lane[a] == 'L') oth = 'R';
    foreach(it, links[a])
    {
        if(lane[*it] == oth) continue;
        if(lane[*it] > 0) return false;
        lane[*it] = oth;
        if(populate(*it) == false) return false;
    }
    return true;
}

void solve(int dataId)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++) 
        {
            if(abs(pos[i] - pos[j]) < 5) // already overlapping
            {
                links[i].insert(j);
                links[j].insert(i);
            }
            if(spd[i] != spd[j])
            {
                if(spd[i] > spd[j]) addcol(i,j);
                else addcol(j,i);
            }
        }
    }

    for(int i=0;i<n;i++)
        if(links[i].size() == 0) lane[i] = -1;
    
    sort(meet.begin(), meet.end());
    for(int i=0;i<size(meet);i++)
    {
        int a = meet[i].pa, b = meet[i].pb;
        cout << meet[i] << " " << (int)lane[a] << " n " << (int)lane[b] << endl;
        if(meet[i].flag) // removing exist flag.
        {
            links[a].erase(b);
            links[b].erase(a);

            if(links[a].size() == 0) lane[a] = -1;
            if(links[b].size() == 0) lane[b] = -1;
        }
        else
        {
            links[a].insert(b);
            links[b].insert(a);
            if(lane[a] > 0)
            {
                if(lane[b] > 0)
                {
                    if(lane[a] == lane[b])
                    {
                        printf("%.12lf\n", out(meet[i]));
                        return;
                    }
                }
                else
                {
                    if(lane[a] == 'R') lane[b] = 'L'; else lane[b] = 'R';
                    if(populate(b) == false)
                    {
                        printf("%.12lf\n", out(meet[i]));
                        return;
                    }
                }
            }
            else
            {
                if(lane[b] > 0)
                {
                    if(lane[b] == 'R') lane[a] = 'L'; else lane[a] = 'R';
                    if(populate(a) == false)
                    {
                        printf("%.12lf\n", out(meet[i]));
                        return;
                    }
                }
                else
                {
                    if(check(a) == false)
                    {
                        printf("%.12lf\n", out(meet[i]));
                        return;
                    }
                }
            }
        }
    }
    printf("Possible\n");
}

void process(int dataId)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char a;
        int b,c;
        scanf(" %c %d %d",&a,&b,&c);
        lane[i] = a;
        spd[i] = b;
        pos[i] = c;
    }
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
