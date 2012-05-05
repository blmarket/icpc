#include <algorithm>
#include <iostream>
#include <cstdlib>
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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int n;
vector<int> data;
vector<int> sorted;
int sum = 0;

bool check(int a, double rate)
{
    double myp = rate * sum + a;
    bool meet = false;

    double otl = 0;
    for(int i=0;i<n;i++)
    {
        if(meet == false && sorted[i] == a)
        {
            meet = true;
            continue;
        }

        if(myp < sorted[i]) break;
        double need = (myp - sorted[i]);
        otl += need;
    }

    return otl > sum;
}

double go(int a)
{
    double s=0, e=1;
    for(int i=0;i<200;i++)
    {
        double m = (s+e)/2;
        if(check(a,m))
            e = m;
        else
            s=m;
    }
    return e;
}

void process(int dataId)
{
    scanf("%d",&n);
    data.resize(n);
    sum = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
        sum += data[i];
    }
    sorted = data;
    sort(sorted.begin(), sorted.end());
    for(int i=0;i<n;i++)
    {
        printf("%.12lf ", go(data[i]));
    }
    printf("\n");
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process(i);
    }
}
