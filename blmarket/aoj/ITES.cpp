#include <iostream>
#include <list>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <deque>
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

deque<int> lllll;
int k,n;

void process(int dataId)
{
    cin >> k >> n;
    long long cur = 1983;
    long long sum = 0;
    int ret = 0;
    lllll.clear();
    for(int i=0;i<n;i++)
    {
        int tmp = (cur % 10000) + 1;

        lllll.pb(tmp);
        sum += tmp;

        while(sum > k)
        {
            sum -= lllll.front();
            lllll.pop_front();
        }

        if(sum == k) ret++;

        cur = (cur * 214013LL + 2531011LL) % (1LL<<32);
    }
    cout << ret << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
