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

int n,m;

int main(void)
{
    cin >> n >> m;
    vector<int> score(n,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        for(int j=0;j<n;j++)
        {
            int aa,bb;
            cin >> aa >> bb;
            int ss = 0;
            if(a==b && aa==bb) ss+= 2;
            if(a<b && aa<bb) ss+= 2;
            if(a>b && aa>bb) ss+= 2;

            if(a-b == aa-bb) ss+=3;
            if(a==aa) ss++;
            if(b==bb) ss++;
            score[j] += ss;
        }
    }
    
    for(int i=0;i<n;i++)
        cout << score[i] << " ";
    cout << endl;
}
