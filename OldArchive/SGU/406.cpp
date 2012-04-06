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

int n,m;
VVI seq;
vector<set<int> > sets;

int main(void)
{
    cin >> n >> m;
    sets.resize(n);
    for(int i=0;i<n;i++)
    {
        int sz;
        cin >> sz;
        seq.pb(VI(sz));
        for(int j=0;j<sz;j++)
        {
            cin >> seq.back()[j];
            sets[i].insert(seq.back()[j]);
        }
    }

    VI query;
    for(int i=0;i<m;i++)
    {
        int sz;
        cin >> sz;
        query.resize(sz);
        for(int j=0;j<sz;j++)
            cin >> query[j];
        vector<int> idx;
        idx.clear();
        for(int j=0;j<n;j++)
        {
            bool nogood = false;
            for(int k=0;k<query.size();k++)
            {
                int q = query[k];
                if(q>0 && sets[j].count(q) == 0)
                {
                    nogood=true;
                    break;
                }

                if(q<0 && sets[j].count(-q) > 0)
                {
                    nogood = true;
                    break;
                }
            }
            if(!nogood) idx.push_back(j);
        }

        cout << idx.size() << endl;
        for(int j=0;j<idx.size();j++)
        {
            cout << seq[idx[j]].size() << " ";
            for(int k=0;k<seq[idx[j]].size();k++)
                cout << seq[idx[j]][k] << " ";
            cout << endl;
        }
    }

    return 0;
}
