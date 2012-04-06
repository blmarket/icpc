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

int n,m;
vector<vector<pair<int,int> > > edge;
vector<int> visit;
vector<int> flow;

int go(int s,int e)
{
	if(s==e) return 500;
	for(int i=0;i<edge[s].size();i++)
	{
		int node = edge[s][i].first;
		int flow = edge[s][i].second;
		if(flow && visit[node] == -1)
		{
			visit[node] = s;
			int tmp = go(node,e);
			if(tmp)
			{
				return min(tmp,flow);
			}
		}
	}
	return 0;
}

void add_edge(int s,int e,int flow)
{
	for(int i=0;i<edge[s].size();i++)
	{
		if(edge[s][i].first == e)
		{
			edge[s][i].second += flow;
			return;
		}
	}
	edge[s].pb(mp(e,flow));
}

int try_flow(int s,int e)
{
	visit = vector<int>(n*m,-1);
	flow = vector<int>(n*m,0);
	visit[s]=s;
	flow[s]=9999;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int node = Q.front();
		if(node == e) break;
		Q.pop();
		for(int i=0;i<edge[node].size();i++)
		{
			int n2 = edge[node][i].first;
			int f2 = edge[node][i].second;
			if(f2 && visit[n2] == -1)
			{
				visit[n2] = node;
				flow[n2] = min(flow[node],f2);
				Q.push(n2);
			}
		}
	}
	
	if(visit[e] != -1)
	{
		int node = e;
		int tmp = flow[e];
		while(visit[node] != node)
		{
			add_edge(visit[node],node,-tmp);
			add_edge(node,visit[node],tmp);
			node = visit[node];
		}
		return tmp;
	}
	else return 0;
}

void process(void)
{
	int s,e;
	scanf("%d %d",&n,&m);
	int x,y;
	scanf("%d %d",&x,&y);
	s = (x * m + y);
	scanf("%d %d",&x,&y);
	e = (x*m+y);

	edge.clear();
	edge.resize(n*m);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			int p1 = i*m+j;
			int p2 = p1+1;
			int tmp;
			scanf("%d",&tmp);
			if(tmp) tmp++;
			if(tmp)
			{
				edge[p1].pb(mp(p2,tmp));
				edge[p2].pb(mp(p1,tmp));
			}
		}
	}

	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			int p1 = i*m+j;
			int p2 = p1+m;
			int tmp;
			scanf("%d",&tmp);
			if(tmp) tmp++;
			if(tmp)
			{
				edge[p1].pb(mp(p2,tmp));
				edge[p2].pb(mp(p1,tmp));
			}
		}
	}

	int ret = 0;
	while(true)
	{
		int tmp = try_flow(s,e);
		if(tmp == 0) break;
		ret += tmp;
	}
	cout << ret*1000 << endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++) 
	{
		process();
	}
}
