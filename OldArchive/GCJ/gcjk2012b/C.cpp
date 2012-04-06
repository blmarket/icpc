#include <iostream>
#include <cstring>
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
#define mod 32749

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int b,w,kk,idx;
int combi[2002][2002];
int avail[2002][2002];

void process(void)
{
    memset(combi, 0, sizeof(combi));
    memset(avail, 0, sizeof(avail));
    cin >> b >> w >> kk >> idx;

    // initial state
    int cnt = 0;
    for(int i=0;i<=kk;i++)
    {
        int j = kk-i;
        if(i<=b && j<=w)
        {
            combi[i][j] = 1;
            avail[i][j] = 1;
        }
    }

    int turn;
    for(turn = 1; turn <= kk; turn++)
    {
        #define b(x) ((x)==0?0:1)
        for(int i=0;i<=kk - turn;i++)
        {
            int j = kk - turn - i;
            avail[i][j] = b(avail[i+1][j]) + b(avail[i][j+1]);
        }

        int erase;
        if(turn > idx)
            erase = -1;
        else if(turn == idx)
            erase = 2;
        else
            erase = 1;

        for(int i=0;i<=kk - turn;i++)
        {
            int j = kk - turn - i;
            if(avail[i][j] == erase)
            {
                combi[i][j] = 0;
                avail[i][j] = 0;
            }
            else
            {
                combi[i][j] = (combi[i+1][j] + combi[i][j+1]) % mod;
            }
        }
    }

    cout << combi[0][0] << endl;
}

void precalc(void)
{
    combi[0][0]=combi[1][0]=combi[1][1]=1;
    for(int i=2;i<=2000;i++)
    {
        combi[i][0]=combi[i][i]=1;
        for(int j=1;j<i;j++)
        {
            combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]) % mod;
        }
    }
}

int main(void)
{
    precalc();
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
