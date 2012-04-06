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

class BlackWhiteMagic 
{
public:
    int count(string creatures) 
    {
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<size(creatures);i++) if(creatures[i] == 'W') cnt1++;

        for(int i=0;i<cnt1;i++)
        {
            if(creatures[i] == 'W') cnt2++;
        }
        
        return cnt1 - cnt2;
    }
};
