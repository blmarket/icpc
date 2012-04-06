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

int main(void)
{
    int n,m;
    cin >> n >> m;
    n = (n-1) % m;
    for(int i=0;i<n;i++)
    {
        string str;
        cin >> str;
    }
    string str;
    cin >> str;
    cout << str << endl;
    return 0;
}
