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

map<int, map<int, int> > memo;

void process(int dataId)
{
    int n,k;
    cin >> n >> k;
    memo.clear();
    memo[0][0]=0;
    for(int i=0;i<n;i++)
    {
        vector<int> a,b,c;
        a=b=c=vector<int>();

        int t1,t2;
        cin >> t1 >> t2;

        foreach(it, memo)
        {
            foreach(jt, it->second)
            {
                a.pb(it->first + t2);
                b.pb(jt->first + 1);
                c.pb(jt->second + t1);
            }
        }

        for(int j=0;j<size(a);j++)
        {
            int aa=a[j], bb=b[j], cc=c[j];
            int &tmp = memo[aa][bb];
            if(tmp == 0 || tmp > cc)
                tmp = cc;
        }
    }
    double ret = 1;
    foreach(it, memo)
    {
        foreach(jt, it->second)
        {
            if(jt->first < k) continue;
            double tmp = (double)(jt->second) / it->first; 
            if(tmp < ret) ret = tmp;
        }
    }
    printf("%.12lf\n",ret);
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
