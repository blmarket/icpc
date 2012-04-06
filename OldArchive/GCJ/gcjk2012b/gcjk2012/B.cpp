#include <iostream>
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

string a,b,c;
map<pair<int,bool>, bool> memo;

bool go1(int i, bool ollim)
{
    if(i == size(c))
    {
        return !ollim;
    }

    if(memo.count(mp(i,ollim)) == 1)
    {
        return memo[mp(i,ollim)];
    }
    for(int j=0;j<10;j++)
    {
        if(c[i] == ' ' && j != 0) continue;
        if(i+1 < size(c) && c[i-1] == ' ' && c[i] == '?' && j == 0) continue;
        if(c[i] != '?' && c[i] != j+'0') continue;
        for(int k=0;k<10;k++)
        {
            if(a[i] == ' ' && k != 0) continue;
            if(i+1 < size(c) && a[i-1] == ' ' && a[i] == '?' && k ==0) continue;
            if((a[i] != ' ' && a[i] != '?') && a[i] != k+'0') continue;
            for(int l=0;l<10;l++)
            {
                if(b[i] == ' ' && l != 0) continue;
                if(i+1 < size(c) && b[i-1] == ' ' && b[i] == '?' && l == 0) continue;
                if((b[i] != ' ' && b[i] != '?') && b[i] != l+'0') continue;
                int tmp = j+(ollim?10:0) - (k+l);
                if(tmp == 0 || tmp == 1)
                {
                    if(go1(i+1, tmp))
                    {
                        c[i] = j+'0';
                        a[i] = k+'0';
                        b[i] = l+'0';
                        return memo[mp(i,ollim)] = true;
                    }
                }
            }
        }
    }
    return memo[mp(i,ollim)] = false;
}

bool calc(string aa,string bb,string cc)
{
    memo.clear();
    a = aa;
    b = bb;
    c = cc;
    c = ' ' + c;
    while(size(a) < size(c)) a = ' ' + a;
    while(size(b) < size(c)) b = ' ' + b;

    return go1(1, false);
}

void process(void)
{
    char num1[1024],num2[1024],num3[1024];

    string t[3];
    char op1,op2;
    scanf(" %s %c %s %c %s",num1, &op1, num2, &op2, num3);
    t[0] = num1; t[1] = num2; t[2] = num3;

    for(int aa=0;aa<3;aa++)
    {
        for(int i=0;i<size(t[aa]);i++)
        {
            if(t[aa][i] == '?')
            {
                int tmp=0;
                if(i==0 && 1 < size(t[aa]))
                    tmp=1;
                for(int j=tmp;j<10;j++)
                {
                    t[aa][i] = '0'+j;


                    if(op1 == '-')
                    {
                        if(calc(t[1],t[2],t[0])) break;
                    }
                    else
                    {
                        if(calc(t[0],t[1],t[2])) break;
                    }
                }
            }
        }
    }

    cout << t[0] << " " << op1 << " " << t[1] << " = " << t[2] << endl;
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
