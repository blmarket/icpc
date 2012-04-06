#include <iostream>
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

vector<PII> nodes;
VVI edges;
vector<vector<PII> > yvals;

vector<int> color;

bool go2(int a,int b)
{
    if(color[a] != -1 && color[a] != b) return false;
    if(color[a] == b) return true;
    color[a]=b;
    for(int i=0;i<edges[a].size();i++)
    {
        if(go2(edges[a][i],1-b) == false) return false;
    }
    return true;
}

bool check2(void)
{
    color = VI(nodes.size(),-1);
    for(int i=0;i<color.size();i++)
    {
        if(color[i]==-1)
        {
            if(!go2(i,0)) return false;
        }
    }
    return true;
}



vector<set<int> > edguy;

bool findK4(int a, set<int> &S)
{
    S.insert(a);
    if(S.size() == 4) 
    {
        return true;
    }
    if(edguy[a].size() < 4) 
    {
        S.erase(a);
        return false;
    }
    foreach(iter, edguy[a])
    {
        if(S.count(*iter)) continue;
        bool nofound = false;
        foreach(jter, S)
        {
            if(edguy[*iter].count(*jter) == 0)
            {
                nofound=true;
                break;
            }
        }
        if(nofound) continue;
        if(findK4(*iter,S)) return true;
    }
    S.erase(a);
    return false;
}

bool findK23(int a,int b)
{
    set<int>& A = edguy[a];
    set<int>& B = edguy[b];
    vector<int> result;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_insert_iterator<vector<int> >(result));
    return result.size() >= 3;
}

bool check3(void)
{
    edguy.clear();
    for(int i=0;i<edges.size();i++)
        edguy.push_back(set<int>(edges[i].begin(), edges[i].end()));

    for(int i=0;i<edguy.size();i++)
    {
        if(edguy[i].size() == 2)
        {
            int a = *(edguy[i].begin());
            int b = *(edguy[i].rbegin());
            edguy[a].erase(i);
            edguy[b].erase(i);
            edguy[a].insert(b);
            edguy[b].insert(a);
            edguy[i].clear();
        }
    }

    set<int> S;
    for(int i=0;i<nodes.size();i++)
    {
        if(edguy[i].size() > 3)
        {
            S.clear();
            if(findK4(i,S)) return false;
        }
    }

    for(int i=0;i<nodes.size();i++)
    {
        for(int j=i+1;j<nodes.size();j++)
        {
            if(findK23(i,j)) return false;
        }
    }

    return true;
}

void process(void)
{
    int n;
    cin >> n;
    nodes.resize(n);
    edges.clear();
    yvals.clear();
    yvals.resize(55);
    for(int i=0;i<n;i++)
    {
        cin >> nodes[i].first >> nodes[i].second;
        nodes[i].second++;
        int y = nodes[i].second;
        yvals[y].pb(mp(nodes[i].first,i));
    }
    for(int i=0;i<55;i++)
        sort(yvals[i].begin(), yvals[i].end());

    bool edge = false;
    edges.resize(n);
    for(int i=0;i<n;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            int y = nodes[i].second + j;
            vector<PII>::reverse_iterator iter;
            iter = upper_bound(yvals[y].rbegin(),yvals[y].rend(),mp(nodes[i].first,0),greater<PII>());
            if(iter != yvals[y].rend())
            {
                edges[i].pb(iter->second);
                edges[iter->second].pb(i);
                edge=true;
            }
        }
    }
    if(!edge)
    {
        cout << 1 << endl;
        return;
    }

    if(check2())
    {
        cout << 2 << endl;
        return;
    }

    if(check3())
    {
        cout << 3 << endl;
        return;
    }

    cout << 4 << endl;
    return;
}


int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
