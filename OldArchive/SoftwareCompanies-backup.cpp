#include <string>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <numeric>

#define INFINITE 99999999
#define foreach(i,c) for(typeof((c).begin) i=(c).begin();i!=(c).end();++i)

using namespace std;

int graph[55][55];

class SoftwareCompanies {
    public:
    map<string,int> M;
    vector<vector<int> > V;
    vector<int> amt;

    vector<int> visit;
    vector<int> trail;

    int n;

    int dfs(int a,int sink)
    {
	if(visit[a]) return 0;
	trail.push_back(a);
	visit[a]=1;

	if(a==sink)
	{
	    int flow=INFINITE;
	    for(int i=0;i<trail.size()-1;i++)
	    {
		if(flow > graph[trail[i]][trail[i+1]])
		    flow = graph[trail[i]][trail[i+1]];
	    }
	    for(int i=0;i<trail.size()-1;i++)
	    {
		graph[trail[i]][trail[i+1]] -= flow;
		graph[trail[i+1]][trail[i]] += flow;
	    }	
	    return flow;
	}

	for(int i=0;i<n*2;i++)
	{
	    if(graph[a][i]>0)
	    {
		int tmp = dfs(i,sink);
		if(tmp) return tmp;
	    }
	}

	trail.pop_back();
	return 0;
    }

    int do_flow(int src,int sink)
    {
	int ret=0;
	while(true)
	{
	    visit.clear();
	    visit.resize(n*2,0);
	    trail.clear();
	    int tmp = dfs(src,sink);
	    if(tmp == 0) break;
	    ret += tmp;
	}
	return ret;
    }

    vector <string> produceData(vector <string> names, vector <string> process, vector <int> cost, vector <int> amount, string company1, string company2) 
    {
	n = names.size();
	for(int i=0;i<names.size();i++)
	{
	    M[names[i]]=i;
	}

	V.resize(n);
	for(int i=0;i<names.size();i++)
	{
	    istringstream sin(process[i]);
	    string n2;
	    while(sin >> n2)
	    {
		int node = M[n2];
		V[i].push_back(node);
	    }
	}

	int c1 = M[company1];
	int c2 = M[company2];

	int maxflow = 0,mincost=0;
	vector<string> ret;

	for(int a=0;a<(1<<n);a++)
	{	
	    int totcost;
	    totcost=0;
	    memset(graph,0,sizeof(graph));
	    for(int i=0;i<n;i++)
	    {		
		if(a & (1<<i))
		{
		    graph[i*2][i*2+1]=amount[i];
		    totcost += cost[i];
		}
		for(int j=0;j<V[i].size();j++)
		{
		    graph[i*2+1][V[i][j]*2] = INFINITE;
		}
	    }
	    int tmp = do_flow(c1*2,c2*2+1);
	    if(tmp >= maxflow)
	    {
		vector<string> tmp2;
		for(int i=0;i<n;i++)
		{
		    if(a & (1<<i))
		    {
			tmp2.push_back(names[i]);
		    }
		}
		sort(tmp2.begin(),tmp2.end());
		if(tmp > maxflow || (mincost > totcost) || (mincost == totcost && tmp2 < ret))
		{
		    maxflow = tmp;
		    mincost = totcost;
		    ret = tmp2;
		}
	    }
	}	

	return ret;
    }
};


// Powered by FileEdit


// Powered by FileEdit
