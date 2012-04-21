#include <iostream>
#include <list>
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

template<typename T> int size(const T &a) { return a.size(); } 

int nums[55][55];
bool chks[55][55];
int n;

int go(int s,int e)
{
    if(chks[s][e]) return nums[s][e];

    chks[s][e] = true;
    nums[s][e] = nums[s][s+1] - go(s+1,e);
    int tmp;

    tmp = nums[e-1][e] - go(s,e-1);
    nums[s][e] = max(nums[s][e], nums[e-1][e] - go(s,e-1));

    if(e-s >= 2)
    {
        nums[s][e] = max(nums[s][e], -go(s,e-2));
        nums[s][e] = max(nums[s][e], -go(s+2,e));
    }

    cout << s << " " << e << " = " << nums[s][e] << endl;
    return nums[s][e];
}

void process(int dataId)
{
    memset(chks, 0, sizeof(chks));
    for(int i=0;i<55;i++)
    {
        chks[i][i] = true;
        nums[i][i] = 0;
    }
    cin >> n;
    for(int i=0;i<n;i++)
    {
        chks[i][i+1] = true;
        cin >> nums[i][i+1];
    }
    cout << go(0,n) << endl;
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
