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

string ww;
map<pair<string, int>, int> memo[2];

int go(int turn, const string &str, int pos)
{
    if(pos >= size(str))
    {
        if(str > ww) return 1;
        return -1;
    }

    int &ret = memo[turn][mp(str,pos)];
    if(ret != 0) return ret;

    for(int i=pos;i<size(str);i++)
    {
        string tmp = str.substr(0,i) + str.substr(i+1);
        if(turn == 0)
        {
            int tt= go(1,tmp,i);
            ret = min(ret, tt);
        }
        else
        {
            int tt = go(0, tmp, i);
            ret = max(ret, tt);
        }
    }

    cout << turn << " " << str << " " << pos << " = " << ret << endl;
    if(ret == 0)
    {
        if(turn == 0) return ret=1;
        return ret=-1;
    }
    return ret;
}

class SistersErasingLetters 
{
public:
    string whoWins(string word) 
    {		
        ww = word;
        if(go(0,word,0) == 1)
            return "Camomile";
        return "Romashka";
    }
};
