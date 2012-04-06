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

bool go1(int i, bool ollim)
{
    if(i == size(c))
    {
        return !ollim;
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
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool go2(int i,bool ollim)
{
    if(i == size(c))
    {
        return !ollim;
    }
    for(int k=0;k<10;k++)
    {
        if(a[i] == ' ' && k != 0) continue;
        if(a[i-1] == ' ' && a[i] == '?' && k ==0) continue;
        if((a[i] != ' ' && a[i] != '?') && a[i] != k+'0') continue;
        for(int l=0;l<10;l++)
        {
            if(b[i] == ' ' && l != 0) continue;
            if(b[i-1] == ' ' && b[i] == '?' && l == 0) continue;
            if((b[i] != ' ' && b[i] != '?') && b[i] != l+'0') continue;
            for(int j=0+(i==1);j<10;j++)
            {
                if(c[i] == ' ' && j != 0) continue;
                if(c[i] != '?' && c[i] != j+'0') continue;
                int tmp = j+(ollim?10:0) - (k+l);
                if(tmp == 0 || tmp == 1)
                {
                    if(go2(i+1, tmp))
                    {
                        c[i] = j+'0';
                        a[i] = k+'0';
                        b[i] = l+'0';
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void calc(string aa,string bb,string cc, bool chk)
{
    a = aa;
    b = bb;
    c = cc;
    c = ' ' + c;
    while(size(a) < size(c)) a = ' ' + a;
    while(size(b) < size(c)) b = ' ' + b;

    if(chk)
        go1(1, false);
    else
        go2(1, false);

    while(a[0] == ' ' || a[0] == '0') a = a.substr(1);
    while(b[0] == ' ' || b[0] == '0') b = b.substr(1);
    if(a == "") a = "0";
    if(b == "") b = "0";
    c = c.substr(1);
}

void process(void)
{
    char num1[1024],num2[1024],num3[1024];
    char op1,op2;
    scanf(" %s %c %s %c %s",num1, &op1, num2, &op2, num3);
    if(op1 == '-')
    {
        calc(num2,num3,num1, true);
        cout << c << " - " << a << " = " << b << endl;
    }
    else
    {
        calc(num1,num2,num3, false);
        cout << a << " + " << b << " = " << c << endl;
    }
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
