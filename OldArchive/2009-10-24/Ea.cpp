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

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

struct state
{
	state(const vector<PII> &pos, int bpos) : pos(pos), bpos(bpos) {}

	vector<PII> pos;
	int bpos;

	bool operator<(const state &a) const
	{
		if(bpos != a.bpos) return bpos < a.bpos;
		return pos < a.pos;
	}
};

bool movable(char chr)
{
	return chr == '.' || chr == 'B';
}

VS data;
int n,m;
map<state,int> memo;

pair<int,int> reachable(const vector<PII> &Xs, int pos)
{
	int x = Xs[pos/4].first + dx[pos % 4];
	int y = Xs[pos/4].second + dy[pos % 4];
	return mp(x,y);
}

inline bool exist(const vector<PII> &Xs, const PII &pp)
{
	for(int i=0;i<Xs.size();i++)
		if(Xs[i] == pp) return true;
	return false;
}

void gogo(PII start, PII end, VVI &visited, const vector<PII> &Xs)
{
	queue<PII> Q;
	Q.push(start);
	visited[start.first][start.second]=0;

	while(!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		int move = visited[x][y];
		Q.pop();
		if(mp(x,y) == end) continue;

		for(int i=0;i<4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(exist(Xs,mp(nx,ny))) continue;
			if(movable(data[nx][ny]) && visited[nx][ny] == -1)
			{				
				visited[nx][ny] = move + 1;
				Q.push(mp(nx,ny));
			}
		}
	}
}

void process(void)
{
	memo.clear();
	cin >> n >> m;
	PII start,end;
	data.resize(n);
	vector<PII> Xs, Bs;
	for(int i=0;i<n;i++)
	{
		cin >> data[i];
		for(int j=0;j<m;j++)
		{
			if(data[i][j] == 'S') 
			{
				start = mp(i,j);
				data[i][j] = '.';
			}
			if(data[i][j] == 'X')
			{
				Xs.pb(mp(i,j));
				data[i][j] = '.';
			}
			if(data[i][j] == 'E')
			{
				end = mp(i,j);
				data[i][j] = '.';
			}
			if(data[i][j] == 'B')
			{
				Bs.pb(mp(i,j));
			}
		}
	}

	if(Xs.size() == 0) data[end.first][end.second] = '.';

	vector<vector<int> > visited(n,vector<int>(m,-1));

	gogo(start,end,visited,Xs);

	if(Xs.size() == 0)
	{
		if(visited[end.first][end.second] == -1)
		{
			cout << "impossible" << endl;
			return;
		}
		else
		{
			cout << visited[end.first][end.second] << endl;
			return;
		}
	}

	priority_queue<pair<int, state> > Q;
	for(int i=0;i<Xs.size()*4;i++)
	{
		PII pos = reachable(Xs,i);
		if(visited[pos.first][pos.second] != -1)
		{
			int move = visited[pos.first][pos.second];
			state st(Xs,i);
			memo[st] = move;
			Q.push(mp(move,st));
		}
	}

	sort(Bs.begin(),Bs.end());

	int ret = -1;

	while(!Q.empty())
	{
		int move = Q.top().first;
		Xs = Q.top().second.pos;
		int bpos = Q.top().second.bpos;
		PII Spos = reachable(Xs, bpos);

		if(memo.size() % 1000 == 0) cout << size(memo) << endl;

		if(Spos == end) continue;

		cout << size(memo) << endl;
		//cout << move << " : ";
		//for(int i=0;i<Xs.size();i++)
		//	cout << Xs[i].first << "," << Xs[i].second << " ";
		//cout << Spos.first << "," << Spos.second << endl;
		
		int idx = bpos / 4;
		bpos %= 4;
		Q.pop();


		PII Npos = mp(Spos.first + dx[3-bpos]*2,Spos.second + dy[3-bpos]*2);
		if(Npos != end && movable(data[Npos.first][Npos.second]) && exist(Xs,Npos) == false)
		{
			state tmp(Xs, idx*4+bpos);
			tmp.pos[idx] = Npos;
			if(memo.count(tmp)==0 || memo[tmp] > move+1)
			{
				memo[tmp] = move+1;
				Q.push(mp(move+1,tmp));
			}
		}

		VVI visited(n,VI(m,-1));
		gogo(Spos, end, visited, Xs);

		vector<PII> tmp = Xs;
		sort(Xs.begin(), Xs.end());
		if(Xs == Bs)
		{
			if(visited[end.first][end.second] != -1)
			{
				int move2 = move + visited[end.first][end.second];
				if(ret == -1 || ret > move2) 
					ret = move2;
			}
		}


		for(int i=0;i<Xs.size()*4;i++)
		{
			PII pos = reachable(Xs,i);
			if(visited[pos.first][pos.second] != -1)
			{
				int move2 = move + visited[pos.first][pos.second];
				state st(Xs,i);
				if(memo.count(st) == 0 || memo[st] > move2) 
				{
					memo[st] = move2;
					Q.push(mp(move2,st));
				}
			}
		}
	}

	if(ret == -1)
	{
		cout << "impossible" << endl;
		return;
	}
	cout << ret << endl;
}

int main(void)
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++) process();
}
