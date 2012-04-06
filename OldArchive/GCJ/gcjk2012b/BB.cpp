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

int move1(int nowpos, int dist)
{
    if(nowpos == 5) return 20 + dist;
    if(nowpos == 10) 
    {
        int ret = 25 + dist;
        if(ret < 27) return ret;
        if(ret == 27) return 22;
        return ret - 1;
    }
    if(nowpos == 22)
        return 27 + dist;
    if(nowpos == 26)
    {
        if(dist == 0) return 22;
        return 26 + dist;
    }
    return nowpos + dist + 1;
}

int move(int nowpos, int dist)
{
    if(nowpos == -1) nowpos = 0;
    int tmp = move1(nowpos, dist);
    if(tmp >= 29) tmp = -2;
    return tmp;
}

void process(void)
{
    for(int i=0;i<29;i++)
    {
        cout << i << " : ";
        for(int j=0;j<5;j++)
        {
            cout << move(i,j) << " ";
        }
        cout << endl;
    }
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
