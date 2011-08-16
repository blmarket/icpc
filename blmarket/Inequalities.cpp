#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <complex>

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

class Inequalities 
{
public:
    int maximumSubset(vector <string> inequalities) 
    {
        vector<pair<string,int> > eqs;

        for(int i=0;i<inequalities.size();i++)
        {
            string tmp = inequalities[i];
            char tmp1[1024];
            int tmp2;
            sscanf(tmp.c_str(),"X %s %d",tmp1,&tmp2);
            cout << tmp1 << " " << tmp2 << endl;
            tmp2 *= 2;
            eqs.pb(mp(tmp1,tmp2));
        }

        int max = 0;
        for(int i=-2;i<=2002;i++)
        {
            int cnt=0;
            cout << i << " : ";
            for(int j=0;j<size(eqs);j++)
            {
                string tmp1 = eqs[j].first;
                int tmp2 = eqs[j].second;
                int tmp3 = cnt;
                if(tmp1 == "<")
                {
                    if(i < tmp2) cnt++;
                }
                else if(tmp1 == "<=")
                {
                    if(i <= tmp2) cnt++;
                }
                else if(tmp1 == "=")
                {
                    if(i == tmp2) cnt++;
                }
                else if(tmp1 == ">")
                {
                    if(i > tmp2) cnt++;
                }
                else if(tmp1 == ">=")
                {
                    if(i >= tmp2) cnt++;
                }

                cout << (tmp3==cnt?0:1) << " ";
            }
            cout << endl;
            if(max < cnt) max = cnt;
        }
        return max;
    }
};


// Powered by FileEdit
