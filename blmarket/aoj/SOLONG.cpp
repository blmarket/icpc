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

int n,m;
map<string, string> mapper;
map<string, int> dict;

void updatedict(string tmp)
{
    int tmp2 = dict[tmp];
    string tmp3 = tmp;
    while(tmp3 != "")
    {
        string oth = mapper[tmp3];
        int occ = dict[oth];

        if(occ < tmp2 || (occ == tmp2 && tmp < oth))
            mapper[tmp3] = tmp;
        tmp3 = tmp3.substr(0, size(tmp3)-1);
    }
}

void process(int dataId)
{
    mapper.clear();
    dict.clear();
    scanf("%d %d",&n, &m);
    char tmp[1024];
    for(int i=0;i<n;i++)
    {
        int tmp2;
        scanf(" %s %d",tmp, &tmp2);
        dict[tmp] = tmp2;

        updatedict(tmp);
    }

    int ret = 0;
    for(int i=0;i<m;i++)
    {
        scanf(" %s", tmp);
        string tmp2(tmp);
        bool done = false;
        for(int j=0;j<size(tmp2) - 1;j++)
        {
            if(mapper[tmp2.substr(0,j+1)] == tmp2)
            {
                done = true;
                cout << tmp2 << " " << j+1+1 << endl;
                ret += j+1+1+1;
                break;
            }
        }
        if(!done)
        {
            cout << tmp2 << " " << size(tmp2)+1 << endl;
            ret += size(tmp2)+1;
        }

        dict[tmp2] += 1;
        updatedict(tmp2);
    }

    cout << ret-1 << endl;
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
