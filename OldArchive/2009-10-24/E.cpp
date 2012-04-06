#include <iostream>
#include <cstdlib>
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

int n,m;
VS data;
VVI pos;
int link[105][4];
int visit[105][105][105];
const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};

struct state
{
	state(int s,int x1,int x2) : s(s),x1(x1),x2(x2) {}
	int s,x1,x2;
};

void process(void)
{
	memset(visit,-1,sizeof(visit));
	cin >> n >> m;
	data.resize(n);
	for(int i=0;i<n;i++)
		cin >> data[i];

	pos = VVI(n,VI(m,-1));

	int npos = 0;
	vector<int> xpos;
	vector<int> bpos;
	int spos = -1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(data[i][j] == 'S')
				spos = npos;
			if(data[i][j] == 'X')
				xpos.pb(npos);
			if(data[i][j] == 'B')
				bpos.pb(npos);

			if(data[i][j] != '#' && data[i][j] != 'E')
			{
				pos[i][j] = npos++;
			}
		}
	}

	int epos = -1;

	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(pos[i][j] != -1) for(int k=0;k<4;k++)
	{
		int nx = i + dx[k];
		int ny = j + dy[k];
		if(data[nx][ny] == 'E') epos = pos[i][j];
	}

	if(epos == -1)
	{
		cout << "impossible" << endl;
		return;
	}

	xpos.resize(2,npos);
	bpos.resize(max(2,size(bpos)),npos);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) if(pos[i][j] != -1)
		{
			int p1 = pos[i][j];
			for(int k=0;k<4;k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				link[p1][k] = pos[nx][ny];
			}
		}
	}

	visit[spos][xpos[0]][xpos[1]] = 0;
	queue<state> Q;
	Q.push(state(spos,xpos[0],xpos[1]));

	while(!Q.empty())
	{
		int sp = Q.front().s;
		int xp1 = Q.front().x1;
		int xp2 = Q.front().x2;
		int move = visit[sp][xp1][xp2];

		Q.pop();
		for(int i=0;i<4;i++) if(link[sp][i] != -1)
		{
			int npos = link[sp][i];
			if(npos == -1) continue;
			if(xp1 == npos)
			{
				int nnpos = link[xp1][i];
				if(nnpos == -1) continue;
				if(nnpos == xp2) continue;

				if(visit[npos][nnpos][xp2] < 0)
				{
					visit[npos][nnpos][xp2] = move+1;
					Q.push(state(npos,nnpos,xp2));
				}
				if(visit[npos][xp2][nnpos] < 0)
				{
					visit[npos][xp2][nnpos] = move+1;
					Q.push(state(npos,xp2,nnpos));
				}
			}
			else if(xp2 != npos)
			{
				if(visit[npos][xp1][xp2] < 0)
				{
					visit[npos][xp1][xp2] = move+1;
					Q.push(state(npos,xp1,xp2));
					visit[npos][xp2][xp1] = move+1;
					Q.push(state(npos,xp2,xp1));
				}
			}
		}
	}

	int ret = -1;
	for(int i=0;i<=npos;i++)
	{
		if(bpos[0] != npos && i != bpos[0]) continue;
		for(int j=0;j<=npos;j++)
		{
			if(bpos[1] != npos && j != bpos[1]) continue;
			if(visit[epos][i][j] == -1) continue;
			if(ret == -1 || ret > visit[epos][i][j])
				ret = visit[epos][i][j];
		}
	}

	if(bpos.size() > 2 || ret == -1)
	{
		cout << "impossible" << endl;
		return;
	}

	cout << ret+1 << endl;
}

int main(void)
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++) process();
}
