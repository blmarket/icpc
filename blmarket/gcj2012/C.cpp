#include <iostream>
#include <algorithm>
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

int a,b;

void process(void)
{
    long long ret = 0;
    cin >> a >> b;
    for(int i=a;i<b;i++)
    {
        if((i % 10000) == 0)
        {
            cerr << i << endl;
        }
        vector<int> V;
        ostringstream ost;
        ost << i;
        string str = ost.str();
        V.clear();
        for(int j=size(str)-1;j>0;j--) if(str[j] != '0')
        {
            string tmp = str.substr(j) + str.substr(0,j);
            if(str.size() != tmp.size())
            {
                cerr << "ang?" << endl;
                exit(-1);
            }
            istringstream sin(tmp);
            int tmp2;
            sin >> tmp2;
            if(tmp2 > i && tmp2 <= b)
            {
                V.pb(tmp2);
            }
        }
        sort(V.begin(), V.end());
        ret += unique(V.begin(), V.end()) - V.begin();
    }
    cout << ret << endl;
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
