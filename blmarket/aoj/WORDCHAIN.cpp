#include <iostream>
#include <list>
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

vector<string> links[30][30];
typedef list<pair<string, int> > list_t;
list_t output;

int walk2(list_t::iterator it, int s, int t)
{
    if(s==t) return 0;
    for(int i=0;i<30;i++)
    {
        if(links[s][i].size())
        {
            output.insert(it, mp(links[s][i].back(),s));
            links[s][i].pop_back();
            return walk2(it, i,t);
        }
    }
    return -1;
}

int pump(list_t::iterator it)
{
    int pos = it->second;
redo:
    for(int i=0;i<30;i++)
    {
        if(links[pos][i].size())
        {
            output.insert(it, mp(links[pos][i].back(), pos));
            links[pos][i].pop_back();
            if(walk2(it, i, pos) == -1) return -1;
            goto redo;
        }
    }
    return 0;
}

void solve(int dataId)
{
    int s = -1, t= -1, use = -1;
    for(int i=0;i<26;i++)
    {
        int outd = 0, ind=0;
        for(int j=0;j<26;j++)
        {
            outd += links[i][j].size();
            ind += links[j][i].size();
        }
        if(outd || ind) use = i;
        if(outd > ind+1 || ind > outd+1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        if(outd > ind)
        {
            if(s != -1)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
            s = i;
        }
        if(ind > outd)
        {
            if(t != -1)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
            t = i;
        }
    }
    if(s == -1) s = t = use;

    if(walk2(output.end(), s, t) == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    output.pb(mp("", t));
    foreach(it, output)
    {
        if(pump(it) == -1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    for(int i=0;i<30;i++) for(int j=0;j<30;j++) if(links[i][j].size())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    output.pop_back();
    list_t::iterator it = output.begin();
    do
    {
        cout << it->first;
        ++it;
        if(it == output.end()) break;
        cout << " ";
    } while(true);
    cout << endl;
}

void process(int dataId)
{
    int n;
    cin >> n;
    for(int i=0;i<30;i++) for(int j=0;j<30;j++) links[i][j].clear();
    output.clear();
    for(int i=0;i<n;i++)
    {
        string tmp;
        cin >> tmp;
        int c1 = tmp[0] - 'a';
        int c2 = *(tmp.rbegin()) - 'a';
        links[c1][c2].pb(tmp);
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
