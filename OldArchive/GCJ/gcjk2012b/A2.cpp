#include <iostream>
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

int n;
int p[20], s[20];
vector<int> perm;

int calc(void)
{
    int life=0;
    for(int i=0;i<size(perm);i++)
    {
        if(p[perm[i]] < life) return life;
        life += s[perm[i]];
    }
    return life;
}

void process(void)
{
    cin >> n;
    perm.clear();
    for(int i=0;i<n;i++)
    {
        perm.pb(i);
        cin >> p[i] >> s[i];
    }

    int ret = 0;
    do
    {
        ret = max(ret, calc());
    } while(next_permutation(perm.begin(), perm.end()));
    cout << ret << endl;
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
