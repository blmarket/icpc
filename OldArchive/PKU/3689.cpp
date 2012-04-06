#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
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

struct state
{
    double a,b,c;

    bool operator<(const state &aa) const
    {
        if(a*aa.b != b*aa.a)
            return a*aa.b < b*aa.a;
        return (a+b) * aa.c < (aa.a+aa.b) * c;
    }
};

vector<state> st,st2;

int main(void)
{
    int n,m;
    cin >> n >> m;
    st.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> st[i].a >> st[i].b >> st[i].c;
    }

    sort(st.begin(),st.end());

    for(int i=0;i<st.size();i++)
    {
        while(st2.size() >= 2)
        {
            state aa = st[i];
            state bb = st2.back();
            state cc = *(st2.rbegin()+1);
            double a = aa.a, b = aa.b, c = bb.a, d = bb.b, e = cc.a, f = cc.b;

            if( a*f - b*e == 0 )
            {
                st2.pop_back();
                continue;
            }

            double x = (double)(f*c - e*d) / (a*f - b*e);
            double y = (double)(b*c - a*d) / (b*e - a*f);

            if(aa.c * x + cc.c * y > bb.c)
            {
                st2.pop_back();
            }
            else
            {
                break;
            }
        }
        st2.pb(st[i]);
    }

    for(int i=0;i<m;i++)
    {
        double xx,yy;
        cin >> xx >> yy;
        state tmp;
        tmp.a = xx;
        tmp.b = yy;
        tmp.c = 10000000000LL;
        vector<state>::iterator iter = lower_bound(st2.begin(),st2.end(),tmp);
        if(iter == st2.end())
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        state tt = *iter;
        if(iter == st2.begin())
        {
            if(tt.b * tmp.a != tt.a * tmp.b)
            {
                cout << "IMPOSSIBLE" << endl;
                continue;
            }
            double x = (double)(tmp.a+tmp.b) / (tt.a+tt.b);
            double result = floor((x*tt.c)*100000)/100000;
            printf("%.5lf\n",result);
            continue;
        }

        state tt2 = *(--iter);

        double a = tt.a, b = tt.b, c = tmp.a, d = tmp.b, e = tt2.a, f = tt2.b;
        double x = (double)(f*c - e*d) / (a*f - b*e);
        double y = (double)(b*c - a*d) / (b*e - a*f);
        double result = floor((x*tt.c + y*tt2.c)*100000)/100000;
        printf("%.5lf\n",result);
    }
}
