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

int source[55];
int sink[55];
int links[55][55];
int M;
int visit[55];
bool check[55];

bool tryflow(int a)
{
    if(check[a]) return false;
    check[a] = true;
    for(int i=0;i<M;i++) if(links[a][i])
    {
        if(visit[i] == -1) continue;
        if(visit[i] == 0 || tryflow(visit[i]))
        {
            visit[i] = a;
            return true;
        }
    }
    return false;
}

char toc(int a)
{
    a++;
    if(a < 10) return a + '0';
    if(a <= 35) return a - 10 + 'A';
    return a - 36 + 'a';
}

class TheContest 
{
public:
    vector <string> getSchedule(int N, int M_) 
    {
        vector<string> ret;
        M = M_;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                links[i][j] = 1;

        for(int i=0;i<min(N,M);i++)
        {
            for(int j=0;j<M;j++) sink[j]=1;

            for(int j=0;j<N;j++)
            {
                for(int k=0;k<M;k++) if(sink[k]) if(links[j][k])
                {
                    sink[k] = 0;
                    bool good = true;

                    for(int l=0;l<M;l++)
                    {
                        if(sink[l] == 0)
                            visit[l] = -1;
                        else
                            visit[l] = 0;
                    }

                    for(int l=j+1;j<N;j++)
                    {
                        memset(check, 0, sizeof(check));
                        if(tryflow(l) == false)
                        {
                            good=false;
                            break;
                        }
                    }
                    if(good)
                    {
                        cout << j << " " << k << endl;
                        links[j][k] = 0;
                        ret[j] += toc(k);
                        break;
                    }
                    sink[k] = 1;
                }
            }
        }
        return ret;
    }
};
