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

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int k,n,m,h;
double fort[25];

map<pair<vector<int>, int>, double> memo1, memo2;

double go2(vector<int> V, int cnt)
{
    if(V.back() == 0) V.pop_back();
    pair<vector<int>,int> key = mp(V,cnt);
    if(memo2.count(key) == 1) return memo2[key];

    if(cnt == 0) return 1;
    double ret = 0;
    for(int i=1;i<size(V);i++) if(V[i])
    {
        double p = (double)V[i] / k;
        V[i]--; V[i-1]++;
        ret += p * go2(V, cnt-1);
        V[i]++; V[i-1]--;
    }

    return memo2[key] = ret;
}

double go1(vector<int> V, int cnt)
{
    if(V.back() != 0) V.pb(0);
    pair<vector<int>,int> key = mp(V,cnt);
    if(memo1.count(key) == 1) return memo1[key];

    if(cnt == 0) return go2(V, n);

    double ret = 0;
    for(int i=0;i+1<size(V);i++) if(V[i])
    {
        double p = (double)V[i] / k;
        V[i]--; V[i+1]++;
        ret += p * go1(V, cnt-1);
        V[i]++; V[i+1]--;
    }

    //for(int i=0;i<size(V);i++) cerr << V[i] << " ";
    //cerr << ", " << cnt << " A= " << ret << endl;

    return memo1[key] = ret;
}

void process(void)
{
    cin >> k >> n >> m >> h;
    memo1.clear(); memo2.clear();

    vector<int> state;
    state.pb(k-h);
    state.pb(h);

    double ret = go1(state, m);
    printf("%.12lf\n",1 - ret);
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
