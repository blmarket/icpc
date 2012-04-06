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

vector<vector<int> > edges;
vector<int> group;
int ngroup;
int ret;

void go(int a,int back)
{
	if(group[a] != -1) return;
	group[a] = ngroup++;
	for(int i=0;i<edges[a].size();i++)
	{
		int node = edges[a][i];
		go(node,back);
		if(group[node] < group[a]) group[a] = group[node];
	}
	if(group[a] != back)
	{
		ret++;
		group[a]=back;
	}
}

void process(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	edges.clear(); edges.resize(n);
	group.clear(); group.resize(n,-1);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		edges[a].pb(b);
	}

	set<int> S;
	ngroup = 0;
	ret = 0;
	for(int i=0;i<n;i++)
	{
		go(i,ngroup);
//		cout << group[i] << " ";
		S.insert(group[i]);
	}
//	cout << endl;
//	cout << ret << endl;

	if(S.size() == 1)
	{
		cout << ret << endl;
	}
	else
	{
		cout << ret + S.size() << endl;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
		process();
}
