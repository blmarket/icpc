#include <iostream>
#include <cstdio>
#include <algorithm>
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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

void atob(int a,int b)
{
    string rr;
    if(b==1)
    {
        rr="A";
    }
    else
    {
        int sz=1,cur=26;
        b--;
        while(b >= cur)
        {
            b -= cur;
            cur *= 26;
            sz++;
        }

        for(int i=0;i<sz;i++)
        {
            rr += 'A' + (b % 26);
            b /= 26;
        }
        reverse(rr.begin(),rr.end());
    }
    cout << rr << a << endl;
}

void btoa(string alpha, string beta)
{
    int var = 0;
    int mul = 1;
    for(int i=0;i<size(alpha);i++)
    {
        char chr = alpha[size(alpha)-1-i];
        var += mul * (chr - 'A' + 1);
        mul *= 26;
    }
    cout << "R" << beta << "C" << var << endl;
}

void process(void)
{
    string str;
    cin >> str;
    int a,b;
    if( sscanf(str.c_str(), "R%dC%d", &a ,&b) == 2)
    {
        atob(a,b);
    }
    else
    {
        for(int i=0;;i++)
        {
            if(str[i] >= '0' && str[i] <='9')
            {
                string alpha = str.substr(0,i);
                string beta = str.substr(i);
                btoa(alpha, beta);
                break;
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        process();
    return 0;
}
