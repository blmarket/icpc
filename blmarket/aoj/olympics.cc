#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

struct team
{
    int a[3];

    bool operator<(const team &oth) const
    {
        if(a[0] != oth.a[0]) return a[0] < oth.a[0];
        if(a[1] != oth.a[1]) return a[1] < oth.a[1];
        return a[2] < oth.a[2];
    }
};

int N,K;
vector<team> V;
vector<int> sum;

bool check1(int myp, const vector<int> &VV)
{
    if(VV[0] > myp) return false;
    int elasp = 0;
    for(int i=0;i<size(VV);i++)
    {
        elasp += min(K, myp - VV[i]);
    }
    return elasp >= 2*K;
}

bool check2(int myp, const vector<int> &VV)
{
    if(VV[1] > myp) return false;
    int elasp = 0;
    for(int i=1;i<size(VV);i++)
        elasp += min(K, myp - VV[i]);
    return elasp >= K;
}

bool check2x(const team &myt, const vector<team> &VV, int idx, int silver, int bronze)
{
    if(myt < VV[idx]) return false;

    if(silver == 0 && bronze == 0) return true;

    if(idx == size(VV))
    {
        return false;
    }

    if(VV[idx].a[0] == myt.a[0])
    {
        int e1 = myt.a[1] - VV[idx].a[1];
        int e2 = myt.a[2] - VV[idx].a[2];

        if(e1 == 0)
        {
            e2 = min(e2, bronze);
            return check2x(myt, VV, idx+1, silver, bronze - e2);
        }
        else
        {
            if(silver < e1)
            {
                return check2x(myt, VV, idx+1, 0, bronze - min(bronze, K - silver));
            }

            e2 = min(e2, min(bronze, K-e1));

            if(check2x(myt, VV, idx+1, silver - e1, bronze - e2)) return true;

            if(bronze != 0)
            {
                e1--;
                e2 = min(bronze, K - e1);
                return check2x(myt, VV, idx+1, silver - e1, bronze - e2);
            }
            return false;
        }
    }
    else
    {
        return check2x(myt, VV, idx+1, 0, bronze - min(bronze, K - silver));
    }
    return false;
}

void process(void)
{
    scanf("%d %d",&N,&K);
    V.resize(N);
    sum.resize(N);
    for(int i=0;i<N;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        V[i].a[0] = a;
        V[i].a[1] = b;
        V[i].a[2] = c;
        sum[i] = a+b+c;
    }

    for(int i=0;i<N;i++)
    {
        vector<int> VV = sum;
        swap(VV[i], VV.back());
        int myp = VV.back() + K;
        VV.pop_back();
        sort(VV.rbegin(), VV.rend());

        if(check1(myp, VV))
        {
            printf("1 ");
        }
        else if(check2(myp, VV))
        {
            printf("2 ");
        }
        else
        {
            VV[0] += K;
            VV[1] += K;
            VV.pb(0);
            for(int j=0;j<size(VV);j++)
            {
                if(VV[j] <= myp)
                {
                    printf("%d ",j+1);
                    break;
                }
            }
        }
    }
    printf("\n");

    for(int i=0;i<N;i++)
    {
        vector<team> VV = V;
        swap(VV[i], VV.back());
        team myt = VV.back();
        myt.a[0] += K;
        VV.pop_back();
        sort(VV.rbegin(), VV.rend());

        if(check2x(myt, VV, 0, K, K))
            printf("1 ");
        else if(check2x(myt, VV, 1, 0, K))
            printf("2 ");
        else
        {
            team t2; t2.a[0]=t2.a[1]=t2.a[2] = 0;
            VV.pb(t2);
            for(int j=2;j<size(VV);j++)
            {
                if((myt < VV[j]) == false)
                {
                    printf("%d ",j+1);
                    break;
                }
            }
        }
    }

    printf("\n");
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
        process();
}
