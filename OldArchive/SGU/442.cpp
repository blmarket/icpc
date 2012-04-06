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

struct bigint
{
    vector<long long> array;

    bigint& operator+=(const bigint &a)
    {
        array.resize(max(array.size(),a.array.size())+5);
        for(int i=0;i<a.array.size();i++)
        {
            array[i] += a.array[i];
            array[i+1] += array[i]/1000000000000000000LL;
            array[i] %= 1000000000000000000LL;
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
        printf("%lld",array.back());
        for(int i=array.size()-1; i>0; i--)
        {
            printf("%018lld",array[i-1]);
        }
        printf("\n");
        return;
    }
};

bigint zero,one;

void init()
{
    one.array = vector<long long>(1,1);
}

map<string,bigint> memo;

bigint go(const string &astr,bool isfirst = false)
{
    if(astr.size() == 0) return one;
    if(astr.size() == 1) return (astr[0]==0)?one:zero;
    if(astr.size() == 2)
    {
        int tmp = astr[1] * 10 + astr[0];
        return ((tmp % 2) == 0 && (tmp / 2) < 10)?one:zero;
    }

    if(isfirst == false && memo.count(astr)) return memo[astr];

    int sz = astr.size()-1;
    if(astr[sz] > 1) return zero;

    bigint ret;
    for(int i=isfirst?1:0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            int tt1 = (astr[sz]*10 + astr[sz-1]) - (i+j);
            if(tt1<0 || tt1>1) continue;
            int tmp1 = (i+j)/10;
            int tmp2 = (i+j)%10;
            if((astr[0] - tmp2) % 10 != 0) continue;

            string str = astr;
            str[sz] -= tmp1;
            str[sz-1] -= tmp2;
            str[0] -= tmp2;
            str[1] -= tmp1;
            if(str[sz-1] < 0)
            {
                str[sz-1] += 10;
                str[sz]--;
            }
            if(str[0] < 0)
            {
                str[0] += 10;
                str[1]--;
            }
            if(str[1] < 0)
            {
                str[1] += 10;
                str[2]--;
            }

            if(str[0] == 0 && str[sz] == 0)
            {
                string next = str.substr(1,str.size()-2);
                ret += go(next);
            }
        }
    }
    if(isfirst == false) memo[astr] = ret;
    return ret;
}

int main(void)
{
    init();

    while(true)
    {
        string str;
        cin >> str;
        if(str == "0") return 0;

        for(int i=0;i<str.size();i++)
        {
            str[i] -= '0';
        }

        reverse(str.begin(),str.end());

        bigint ret;
        ret += go(str,true);
        str.resize(str.size()+1,0);
        ret += go(str,true);
        ret.print();
    }
}
