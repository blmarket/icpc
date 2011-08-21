#include <iostream>
#include <cstdio>
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

struct asdf
{
    asdf() {};
    asdf(int ppl,int c) : ppl(ppl), c(c) { last = false; }
    int ppl,c;
    double p;
    bool last;
};

asdf visitor[24];

inline void setmax(double &a, double b) { if(a<b) a=b; }

map<pair<pair<int, int>,int>, double> memo;

double go(int turn, int mask, int sw)
{
    if(sw == 0) return 0;
    if(turn == 24) return 0;
    if(visitor[turn].ppl == -1) return go(turn+1, mask, sw);

    if(mask & (1<<visitor[turn].ppl))
        return go(turn+1, mask, sw);

    if(memo.count(mp(mp(turn, mask), sw)) != 0)
        return memo[mp(mp(turn,mask),sw)];
    double &ret = memo[mp(mp(turn,mask),sw)];

    const double &prob = visitor[turn].p;

    double t1 = go(turn+1, mask | (1<<visitor[turn].ppl), sw-1) + visitor[turn].c;
    double t2 = go(turn+1, mask | (1<<visitor[turn].ppl), sw);

    if(visitor[turn].last) mask |= (1<<visitor[turn].ppl);
    double t3 = go(turn+1, mask, sw);

    return ret = (max(t1,t2) * prob + t3 * (1-prob));
}

class NewItemShop 
{
public:
    double getMaximum(int swords, vector <string> customers) 
    {		
        for(int i=0;i<24;i++) visitor[i].ppl = -1;

        for(int i=0;i<size(customers);i++)
        {
            string str;
            istringstream sin(customers[i]);
            int total = 100;
            int a,b,c;
            while(sin >> str)
            {
                sscanf(str.c_str(), "%d,%d,%d", &a, &b, &c);
                visitor[a] = asdf(i, b);
                visitor[a].p = (double)c / total;
                total -= c;
            }
            visitor[a].last = true;
        }

        return go(0, 0, swords);
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
