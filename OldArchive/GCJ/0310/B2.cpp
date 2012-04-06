#include <iostream>
#include <algorithm>
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

    bool operator<(const state &rhs) const
    {
        if(ap[0][0] != rhs.ap[0][0]) return ap[0][0] < rhs.ap[0][0];
        if(ap[0][1] != rhs.ap[0][1]) return ap[0][1] < rhs.ap[0][1];
        if(ap[1][0] != rhs.ap[1][0]) return ap[1][0] < rhs.ap[1][0];
        return ap[1][1] < rhs.ap[1][1];
    }

    bool go();
    bool go(int);
};

set<state> S;
int u;
vector<int> t[2];

bool state::go(int i)
{
    if(ap[turn][i] == -2) return false;
    if(ap[turn][i] == -3) return false;

    bool eat = false;
    move(ap[turn][i], seq[idx]);

    if(ap[turn][i] == -2)
    {
        if(seq[i] != 3 && seq[i] != 4)
            turn = !turn;
        idx++;
        return go();
    }

    for(int j=0;j<2;j++)
    {
        if(ap[turn][i] == ap[!turn][j])
        {
            eat = true;
            ap[!turn][j] = -1;
            if(ap[!turn][1] == -3) ap[!turn][1] = -1;
        }
    }

    if(ap[turn][i] >= 0 && ap[turn][0] == ap[turn][1])
    {
        ap[turn][1] = -3;
    }

    if(seq[idx] != 3 && seq[idx] != 4 && eat == false)
        turn = !turn;
    idx++;
    return go();
}

bool state::go()
{
//    cerr << "normal : " << turn << " " << idx << " " << ap[0][0] << " " << ap[0][1] << " " << ap[1][0] << " " << ap[1][1] << endl;
    if(idx >= size(seq))
    {
        vector<int> v[2];

//        cerr << "endpos : " << ap[0][0] << " " << ap[0][1] << " " << ap[1][0] << " " << ap[1][1] << endl;
        for(int i=0;i<2;i++)
        {
            if(ap[i][0] >= 0) v[i].pb(ap[i][0]);
            if(ap[i][1] >= 0) v[i].pb(ap[i][1]);
            if(ap[i][1] == -3) v[i].pb(ap[i][0]);
            sort(v[i].begin(), v[i].end());
        }

        if(t[0] == v[0] && t[1] == v[1]) return true;
        if(t[0] == v[1] && t[1] == v[0]) return true;

        return false;
    }

    state tmp = *this;
    if(S.count(tmp) != 0) return false;

    S.insert(tmp);

    if(ap[turn][0] == -2 && ap[turn][1] == -2)
    {
        turn = !turn;
    }

    if(tmp.go(0)) return true;
    if(go(1)) return true;
    return false;
}

bool go(int apos, int bpos)
{
    int ap[2] = {-1,-1};
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
    t[0].resize(a);
    t[1].resize(b);
    for(int i=0;i<a;i++)
        cin >> t[0][i];
    for(int i=0;i<b;i++)
        cin >> t[1][i];

    sort(t[0].begin(), t[0].end());
    sort(t[1].begin(), t[1].end());

    if(u == 2)
    {
        S.clear();

        state tmp;
        memset(&tmp, -1, sizeof(tmp));
        tmp.idx = 0;
        tmp.turn = 0;

        if(tmp.go())
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    else
    {
        S.clear();

        state tmp;
        memset(&tmp, -1, sizeof(tmp));
        tmp.ap[0][1] = -2;
        tmp.ap[1][1] = -2;
        tmp.idx = 0;
        tmp.turn = 0;

        if(tmp.go())
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
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
