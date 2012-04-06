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

int n,x;
VI data;

bool check(int a)
{
    bool able[20005] = {0};
    able[0]=true;
    for(int i=0;i<n;i++) if(i!=a)
    {
        for(int j=x;j>=data[i];j--) if(able[j-data[i]])
        {
            able[j]=true;
        }

        if(able[x]) return true;
    }
    return false;
}

int main(void)
{
    cin >> n >> x;
    data.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> data[i];
    }

    vector<int> result;
    for(int i=0;i<n;i++)
    {
        if(check(i) == false)
            result.pb(data[i]);
    }
    cout << result.size() << endl;
    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";
    cout << endl;
}
