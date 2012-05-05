#include <iostream>
#include <cstring>
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
int x,y;
int hole = 0;

void convert(int tile[])
{
    int ret[8];
    for(int i=0;i<8;i+=2)
    {
        ret[tile[i]] = tile[i+1];
        ret[tile[i+1]] = tile[i];
    }
    memcpy(tile, ret, sizeof(ret));
}

void move(int &x, int &y, int &hole)
{
    switch(hole)
    {
        case 0:
        case 1:
            y++;
            hole = 5-hole;
            return;
        case 2:
        case 3:
            x++;
            hole = 9-hole;
            return;
        case 4:
        case 5:
            y--;
            hole = 5-hole;
        case 6:
        case 7:
            x--;
            hole = 9-hole;
    }
}

class TwistedGame
{
public:
    int init(int N_, int firstTile[])
    {
        N = N_;
        x=N, y =N;
        hole = 0;
        return 0;
    }

    string placeTile(int tile[])
    {
        convert(tile);

        move(x,y,hole);

        ostringstream ost;
        ost << x << " " << y << " 0";
        return ost.str();
    }
};
