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
    int u,n,a,b;
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

    if(go(apos, bpos))
    {
        cout << "YES" << endl;
    }
    else
    {
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
