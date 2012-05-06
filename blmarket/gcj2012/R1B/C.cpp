#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <bitset>
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
#define abs(x) ((x)<0?-(x):(x))

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned int UI;

template<typename T> int size(const T &a) { return a.size(); } 

int n;
vector<long long> data;

template<typename T> bool comp(const T &a, const T &b)
{
    return a.first < b.first;
}

void process(int dataId)
{
    cin >> n;
    data.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> data[i];
    }
    sort(data.begin(), data.end());

    typedef vector<pair<long long, pair<bitset<505>, bitset<505> > > > vec_t;
    
    vec_t arr, arr2;

    printf("\n");
    long long numRange = 1000000000000LL;
    for(int i=0;i<size(data);i++)
    {
        bitset<505> ab, bb;
        ab.set(i);
        arr.pb(mp(data[i], mp(ab,bb)));
        ab.set(i,0);
    }

    while(true)
    {
        arr2.clear();


        arr.swap(arr2);
        sort(arr.begin(), arr.end(), comp<vec_t::value_type>);
        numRange /= 2;
    }
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process(i);
        cerr << i << endl;
    }
}
