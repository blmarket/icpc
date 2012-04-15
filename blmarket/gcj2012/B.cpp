#include <iostream>
#include <cmath>
#include <algorithm>
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

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

bool avail[31][11][2];

void precalc(void)
{
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++) if(abs(i-j)<=2)
        {
            for(int k=0;k<=10;k++) if(abs(i-k)<=2 && abs(j-k)<=2)
            {
                bool surp = false;
                if(abs(i-j) == 2 || abs(i-k) == 2 || abs(j-k) == 2) surp = true;

                int sum = i+j+k;
                int maxx = max(max(i,j),k);

                for(int a=0;a<=maxx;a++)
                {
                    avail[sum][a][surp] = true;
                }
            }
        }
    }
}

int n,s,p;
int dyna[105][105];

void process(void)
{
    cin >> n >> s >> p;
    memset(dyna, -1, sizeof(dyna));
    dyna[0][0]=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        for(int j=0;j<=i;j++) if(dyna[i][j] >= 0)
        {
            dyna[i+1][j] = max(dyna[i+1][j], dyna[i][j] + avail[tmp][p][0]);
            dyna[i+1][j+1] = max(dyna[i+1][j+1], dyna[i][j] + avail[tmp][p][1]);
        }
    }
    cout << dyna[n][s] << endl;
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
