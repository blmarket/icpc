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

int n;
long double t;
vector<long double> prob;

map<int,long double> memo;

long double calc(int a)
{
    if(a==n) return 0;
    if(memo.count(a)) return memo[a];

    long double sum1 = 1 + prob[a];
    long double tsum = sum1;
    long double sum2 = 0;
    long double elasp = (1 - prob[a]);
    long double ret = (t + tsum + elasp * calc(a+1)) / (1 - prob[a]);

    for(int i=a+1;i<n;i++)
    {
        sum1 += elasp * prob[i];
        tsum += sum1;
        sum2 += elasp * prob[i] * calc(i);
        elasp *= (1 - prob[i]);

        double tmp = (t + tsum + sum2 + elasp * calc(i+1)) / (1 - prob[a]);

        if(tmp < ret) ret = tmp;

    }

    return memo[a] = ret;
}

int main(void)
{    
    cin >> n >> t;
    prob.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> prob[i];
    }

    printf("%.16lf\n",(double)calc(0));
}
