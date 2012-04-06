#include <iostream>
#include <cstring>
#include <cstdlib>
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

struct req
{
    short a[4];
};

bool operator<(const req &a, const req &b)
{
    return false;
}

vector<int> V[4];
int gogo[55][55][55][55] = {0};

class IPv444 
{
public:
    long long getMaximumMoney(vector <string> request, vector <int> price) 
    {
        vector<pair<int, req> > VV;

        for(int i=0;i<4;i++)
            V[i].pb(-1);
        for(int i=0;i<size(request);i++)
        {
            char buff[1024];
            strcpy(buff, request[i].c_str());
            char *ptr = 
            strtok(buff, ".");

            req tmp;
            for(int j=0;j<4;j++)
            {
                if(ptr[0] == '*') { tmp.a[j] = -1;  ptr = strtok(NULL, "."); continue;}
                tmp.a[j] = atoi(ptr);
                V[j].pb(tmp.a[j]);
                ptr = strtok(NULL, ".");
            }

            VV.pb(mp(price[i], tmp));
        }

        for(int i=0;i<4;i++)
        {
            sort(V[i].begin(), V[i].end());
            V[i].erase(unique(V[i].begin(), V[i].end()),V[i].end());
        }

        sort(VV.begin(), VV.end());

        for(int i=0;i<size(VV);i++)
        {
            req &tmp = VV[i].second;
            for(int j=0;j<V[0].size();j++) if(tmp.a[0] == -1 || V[0][j] == tmp.a[0])
            {
                for(int k=0;k<V[1].size();k++) if(tmp.a[1] == -1 || V[1][k] == tmp.a[1])
                {
                    for(int l=0;l<V[2].size();l++) if(tmp.a[2] == -1 || V[2][l] == tmp.a[2])
                    {
                        for(int m=0;m<V[3].size();m++) if(tmp.a[3] == -1 || V[3][m] == tmp.a[3])
                        {
                            if(j == 0 && k == 0 && l == 0 && m == 0)
                            {
                                cout << "ANG?" << V[0][j] << " " << V[1][k] << " " << V[2][l] << " " << V[3][m] << endl;
                                cout << tmp.a[0] << " " << tmp.a[1] << " " << tmp.a[2] << " " << tmp.a[3] << endl;
                            }
                            gogo[j][k][l][m] = VV[i].first;
                        }
                    }
                }
            }
        }

        LL ret=0;

        for(int i=0;i<V[0].size();i++)
        {
            LL cnt1 = (i==0?1001-size(V[0]):1);
            for(int j=0;j<V[1].size();j++)
            {
                LL cnt2 = (j==0?1001-size(V[1]):1);
                for(int k=0;k<V[2].size();k++)
                {
                    LL cnt3 = (k==0?1001-size(V[2]):1);
                    for(int l=0;l<V[3].size();l++)
                    {
                        LL cnt4 = (l==0?1001-size(V[3]):1);

                        if(gogo[i][j][k][l])
                        {
                            cout << V[0][i] << " " << V[1][j] << " " << V[2][k] << " " << V[3][l] << " " << gogo[i][j][k][l] << endl;
                        }
                        ret += cnt1*cnt2*cnt3*cnt4*gogo[i][j][k][l];
                    }
                }
            }
        }

        return ret;
    }
};
