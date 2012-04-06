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

class RevealTriangle 
{
public:
    vector <string> calcTriangle(vector <string> row) 
    {
        for(int i=1;i<size(row);i++)
        {
            string &cur = row[size(row)-1-i];
            string &prev = row[size(row)-i];

            for(int j=0;j<size(cur);j++) if(cur[j] != '?')
            {
                for(int k=j+1;k<size(cur);k++)
                {
                    cur[k] = (((prev[k-1] - cur[k-1])+100)%10)+'0';
                }
                for(int k=j-1;k>=0;k--)
                {
                    cur[k] = (((prev[k] - cur[k+1])+100)%10)+'0';
                }

                break;
            }
        }

        return row;
    }
};
