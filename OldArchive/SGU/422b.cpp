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

    long double ret = -1;
    int md = -1;
    for(int i=a;i<n;i++)
    {
        long double rec = prob[a];

        long double sum = t + (i+1-a) + rec * (i+1-a);
        long double elasp = (1.-prob[a]);
        for(int j=a+1;j<=i;j++)
        {
            long double pp = elasp * prob[j];
            elasp *= (1.0 - prob[j]);
            sum += pp * (i+1-j + calc(j));
        }
        sum += elasp * calc(i+1);

        long double tmp = sum / (1.0-rec);

        if(i==a || ret > tmp) { ret = tmp; md=i; }
    }

    cout << a << " " << md << " " << ret << endl;
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
