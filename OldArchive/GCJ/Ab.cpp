#include <iostream>
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

VS board;
int n,m;
vector<PII> tgt;

set<vector<PII> > visited;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool check(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m;
}

bool avail(int x,int y,int d,const vector<PII> &state)
{
    int nx = x+dx[d],ny = y + dy[d];
    if(!check(nx,ny)) return false;
    if(board[nx][ny] == '#') return false;
    for(int i=0;i<state.size();i++)
        if(state[i] == mp(nx,ny)) return false;
    nx = x-dx[d], ny = y-dy[d];
    if(!check(nx,ny)) return false;
    if(board[nx][ny] == '#') return false;
    for(int i=0;i<state.size();i++)
        if(state[i] == mp(nx,ny)) return false;
    return true;
}

bool isconn(const PII &a, const PII &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second) == 1;
}

void goup(VI &v, int a)
{
    if(v[a] == a) return;
    goup(v,v[a]);
    v[a] = v[v[a]];
}

bool isstable(const vector<PII> &state)
{
    VI group;
    for(int i=0;i<state.size();i++)
        group.pb(i);

    for(int i=0;i<state.size();i++)
    {
        for(int j=i+1;j<state.size();j++)
        {
            if(isconn(state[i],state[j]))
            {
                goup(group,i);
                goup(group,j);
                group[group[j]] = group[i];
            }
        }
    }
    for(int i=0;i<state.size();i++)
    {
        goup(group,i);
        if(group[i] != group[0]) return false;
    }
    return true;
}

void process(void)
{
    tgt.clear();
    visited.clear();
    vector<PII> state;
    cin >> n >> m;
    board.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> board[i];
        for(int j=0;j<m;j++)
        {
            if(board[i][j] == 'x' || board[i][j] == 'w') tgt.pb(mp(i,j));
            if(board[i][j] == 'o' || board[i][j] == 'w') state.pb(mp(i,j));
        }
    }

    queue<pair<vector<PII>,bool> > Q;
    queue<int> sol;
    Q.push(mp(state,true));
    sol.push(0);

    while(!Q.empty())
    {
        vector<PII> state = Q.front().first;
        bool stable = Q.front().second;
        int depth = sol.front();
        Q.pop();
        if(state == tgt)
        {
            cout << sol.front() << endl;
            return;
        }
        sol.pop();

//        cout << depth << " " << stable << " : ";
//        for(int i=0;i<state.size();i++)
//            printf("(%d,%d) ",state[i].first,state[i].second);
//        printf("\n");

        for(int i=0;i<state.size();i++)
        {
            int x = state[i].first;
            int y = state[i].second;
            for(int j=0;j<4;j++)
            {
                if(avail(x,y,j,state))
                {
                    vector<PII> tmp = state;
                    tmp[i].first = x + dx[j];
                    tmp[i].second = y + dy[j];
                    sort(tmp.begin(),tmp.end());
                    if(visited.count(tmp)) continue;
                    bool sta = isstable(tmp);
                    if(!stable && !sta) continue;
                    visited.insert(tmp);
                    Q.push(mp(tmp,sta));
                    sol.push(depth+1);
                }
            }
            state[i].first = x;
            state[i].second = y;
        }
    }
    cout << -1 << endl;
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
