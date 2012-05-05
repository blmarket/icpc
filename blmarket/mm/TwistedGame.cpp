#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
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

int N;
int pos = N;

class TwistedGame
{
public:
    int init(int N_, int firstTile[])
    {
        N = N_;
        return 0;
    }

    string placeTile(int tile[])
    {
        pos++;
        ostringstream ost;
        ost << pos << " " << N << " 0";
        return ost.str();
    }
};
