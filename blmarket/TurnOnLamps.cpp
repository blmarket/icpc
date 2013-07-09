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

vector<pair<int, int> > data;

pair<int, bool> go(int pos, int parent) {
    vector<int> childs;
    vector<int> states;
    for(int i=0;i<size(data);i++) {
        if(i+1 == pos || data[i].first == pos) {
            int oth = i+1+data[i].first-pos;
            if(oth == parent) continue;
            childs.pb(oth);
            states.pb(data[i].second);
        }
    }

    int ret = 0;
    bool have = false;
    for(int i=0;i<size(childs);i++) {
        pair<int, bool> key = go(childs[i], pos);
        if(states[i] == 3) {
            key.first += key.second;
            key.second = false;
        } else if(states[i] == 2) {
            key.second = true;
        }

        ret += key.first;
        ret += (have && key.second);
        have ^= key.second;
    }

    // cout << pos << " : " << ret << " " << have << endl;

    return mp(ret, have);
}

class TurnOnLamps 
{
public:
    int minimize(vector <int> roads, string initState, string isImportant) 
    {
        data.clear();
        for(int i=0;i<size(roads);i++) {
            int state = (initState[i] == '1') + 2 * (isImportant[i] == '1');
            data.pb(mp(roads[i], state));
        }

        int N = size(data);
        pair<int, bool> ret = go(N, -1);
        return ret.first + ret.second;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
