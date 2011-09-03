#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

LL p1,p2,v1,v2,K;

PII calc(int K)
{
    int sz = 1;
    while((1<<sz) <= K)
    {
        K -= (1<<sz);
        sz++;
    }

    return mp(sz,K);
}

LL makeit(PII key)
{
    const int &len = key.first;
    int v = key.second;

    LL ret = 0;
    LL mul = 1;
    for(int i=0;i<len;i++)
    {
        if(v & 1)
            ret += 7 * mul;
        else
            ret += 4 * mul;
        v>>=1;
        mul *= 10;
    }

    return ret;
}

int main(void)
{
    cin >> p1 >> p2 >> v1 >> v2 >> K;

    LL l1 = 1;

    LL retcnt = 0;
    LL totcnt = (p2-p1)+1;
    totcnt *= (v2-v1+1);

    for(int i=0;i<5;i++)
    {
        LL l2 = makeit(calc(i));
        LL r1 = makeit(calc(K+i-1));
        LL r2 = makeit(calc(K+i))-1;

        LL leftlen, rightlen;

        leftlen = min(l2, p2) - max(l1,p1) + 1;
        cout << l1 << " " << l2 << " " << r1 << " " << r2 << " " << leftlen << endl;

        if(leftlen > 0)
        {
            rightlen = min(r2,v2) - max(r1,v1) + 1;
            if(rightlen > 0)
                retcnt += leftlen * rightlen;
        }

        leftlen = min(l2, v2) - max(l1,v1) + 1;
        if(leftlen > 0)
        {
            rightlen = min(r2,p2) - max(r1,p1) + 1;
            if(rightlen > 0)
                retcnt += leftlen * rightlen;
        }

        l1 = l2 + 1;
    }

    printf("%.12lf\n", (double)retcnt / totcnt);

    return 0;
}

