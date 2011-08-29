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
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
        process();
}
