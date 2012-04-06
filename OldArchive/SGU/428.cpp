#include <iostream>
#include <sstream>
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

int main(void)
{
    for(int i=100;i<1000;i++)
    {
        for(int j=100;j<1000;j++)
        {
            int k = i+j;
            if(k>=1000) break;
            ostringstream ost;
            ost.clear();
            ost << i << "+" << j << "=" << k;
            string str = ost.str();
        }
    }
}
