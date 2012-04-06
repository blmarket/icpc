import java.util.*;
import java.math.*;

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

int mul[2][30];

struct bigint
{
    static const int mod = 10000;

    vector<int> array;

    bigint& operator+=(const bigint &a)
    {
        array.resize(max(array.size(),a.array.size())+5);
        for(int i=0;i<a.array.size();i++)
        {
            array[i] += a.array[i];
            array[i+1] += array[i]/mod;
            array[i] %= mod;
        }
        while(array.back() == 0) array.pop_back();
        return (*this);
    }

    bigint& operator*=(const int num)
    {
        array.resize(array.size()+5,0);
        for(int i=array.size()-2;i>=0;i--)
        {
            array[i] *= num;
            array[i+1] += (array[i])/mod;
            array[i] %= mod;
        }
        while(array.back() == 0) array.pop_back();
        return (*this);
    }

    void print(void) const
    {
        if(array.size() == 0)
        {
            printf("0\n");
            return;
        }
        printf("%d",array.back());
        for(int i=array.size()-1; i>0; i--)
        {
            printf("%04d",array[i-1]);
        }
        printf("\n");
        return;
    }
};

bigint zero;

bigint go(string str)
{
    vector<int> V;
    int i=0;
    if(str.size() == 1) return zero;
    int lastpos = str.size()-2;
    for(;i+1<lastpos;i++,lastpos--)
    {
        int t1,t2;

        if(str[i] < 0)
        {
            str[i] += 10;
            str[i+1]--;
        }
        t1 = str[i];
        if(str[lastpos] < t1)
        {
            if(str[lastpos+1] == 0) return zero;
            str[lastpos] = str[lastpos] + 10;
            str[lastpos+1]--;
        }

        str[lastpos] -= t1;
        t2 = str[lastpos+1];
        int tmp = t2*10 + t1;
        if(tmp > 18) return zero;
        str[i+1] -= t2;
        V.pb(mul[i==0][tmp]);
    }

    if(i+1==lastpos)
    {
        int num = str[i] + str[i+1]*10 + str[i+2]*100;
        if((num % 11)!=0 || (num/11)>18) return zero;
        V.pb(mul[i==0][num/11]);
    }
    else if(i==lastpos)
    {
        int num = str[i] + str[i+1]*10;
        if((num % 2) || (num>18)) return zero;
    }

    bigint ret;
    ret.array.push_back(1);
    for(int i=0;i<V.size();i++)
        ret *= V[i];
    return ret;
}

int main(void)
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            mul[0][i+j]++;
            if(i != 0) mul[1][i+j]++;
        }
    }

    string str;
    while(true)
    {
        cin >> str;
        if(str == "0") return 0;
        reverse(str.begin(),str.end());
        for(int i=0;i<str.size();i++) str[i] -= '0';
        bigint tmp = go(str);
        str.resize(str.size()+1,0);
        tmp += go(str);
        tmp.print();
    }
}
