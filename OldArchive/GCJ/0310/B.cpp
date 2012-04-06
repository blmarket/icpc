#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
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

string arr[] = { "Do", "Gae", "Gul", "Yut", "Mo" };
int onmove[] = { -2, 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,0,21,22,23,24,15,26,22,28,0 };
int spmove[] = { -2, 2,3,4,5,20,7,8,9,10,25,12,13,14,15,16,17,18,19,0,21,22,27,24,15,26,22,28,0 };

vector<int> seq;
void move(int &cur, int m)
{
    int prev = cur;
    if(cur == -2) return;
    if(cur == -1)
        cur = 1;
    else
        cur = spmove[cur];

    for(int i=0;i<m;i++)
    {
        if(cur == -2) continue;
        if(prev == 26 && cur == 22) { cur = 27; continue; }
        prev = cur;
        cur = onmove[cur];
    }
}

struct state
{
    int ap[2][2];
    int idx, turn;

    bool operator<(const state &rhs)
    {
        if(ap[0][0] != rhs.ap[0][0]) return ap[0][0] < rhs.ap[0][0];
        if(ap[0][1] != rhs.ap[0][1]) return ap[0][1] < rhs.ap[0][1];
        if(ap[1][0] != rhs.ap[1][0]) return ap[1][0] < rhs.ap[1][0];
        return ap[1][1] < rhs.ap[1][1];
    }
};

set<state> S;
int u;

bool go(const state &st)
{
    if(S.count(st) != 0) return false;

    S.insert(st);

    int turn = st.turn;

    

    int turn = 0;
    for(int i=0;i<size(seq);i++)
    {
        bool eat = false;
        move(ap[turn], seq[i]);
        if(ap[0] == ap[1])
        {
            ap[!turn] = -1;
            eat = true;
        }
        cerr << arr[seq[i]] << " " << ap[0] << " " << ap[1] << endl;
        if(ap[turn] == -2)
        {
            turn = !turn;
            continue;
        }
        if(seq[i] != 3 && seq[i] != 4 && eat == false)
            turn = !turn;
    }

    cerr << "Result  " << ap[0] << " " << ap[1] << endl;
    if(ap[0] == -2) ap[0] = -1;
    if(ap[1] == -2) ap[1] = -1;

    if(ap[0] == apos && ap[1] == bpos)
        return true;
    if(ap[1] == apos && ap[0] == bpos)
        return true;
    return false;
}

void process(void)
{
    int n,a,b;
    int apos, bpos;
    seq.clear();
    cin >> u >> n >> a >> b;
    apos = bpos = -1;
    for(int i=0;i<n;i++)
    {
        string tmp;
        cin >> tmp;
        for(int j=0;j<5;j++) if(arr[j] == tmp)
        {
            seq.pb(j);
            break;
        }
    }
    if(a) cin >> apos;
    if(b) cin >> bpos;

    S.clear();

    state tmp;
    memset(tmp, -1, sizeof(tmp));
    tmp.idx = 0;
    tmp.turn = 0;

    go(tmp);
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
