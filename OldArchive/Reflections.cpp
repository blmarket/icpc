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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

long long go(vector<int> &V, int pos)
{
    vector<LL> ss[21];
    for(int i=0;i<size(V);i++) V[i]*=2;
    int N = size(V);
    for(int i=0;i<(1<<N);i++)
    {
        int cnt=0;
        LL sum = 0;
        for(int j=0;j<N;j++) if( i & (1<<j))
        {
            cnt ++;
            sum += V[j];
        }
        ss[cnt].push_back(sum);
    }

    for(int i=0;i<21;i++)
    {
        sort(ss[i].begin(), ss[i].end());
        ss[i].erase(unique(ss[i].begin(), ss[i].end()), ss[i].end());
    }

    LL ret = abs(pos);

    for(int i=0;i<=N/2;i++)
    {
        for(int j=i;j<=i+1;j++)
        {
            if(size(ss[j]) == 0) continue;
            int l = 0;
            for(int k=0;k<size(ss[i]);k++)
            {
                LL tmp, tmp2;

                do
                {
                    tmp = (ss[j][l] - ss[i][k] - pos);
                    if(l+1 == size(ss[j])) { tmp2 = tmp; break; }
                    tmp2 = ss[j][l+1] - ss[i][k] - pos;
                    if(tmp>0 || tmp2>0 || l+1 >= size(ss[j])) break;
                    l++;
                } while(l+1 < size(ss[j]));

                ret = min(ret, min(abs(tmp), abs(tmp2)) + j + i);
            }
        }
    }

    cout << ret << endl;

    return ret;
}

class Reflections 
{
public:
    long long minimumMoves(vector <int> mirrorX, vector <int> mirrorY, vector <int> mirrorZ, vector <int> finalPosition) 
    {
        return go(mirrorX, finalPosition[0]) + go(mirrorY, finalPosition[1]) + go(mirrorZ, finalPosition[2]);
    }
};


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
