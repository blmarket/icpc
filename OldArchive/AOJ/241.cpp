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

long long cost[105][105];
long long npath[105][105];

long long gcd(long long a,long long b)
{
	if(a<b) swap(a,b);
	while(b != 0)
	{
		a%=b;
		if(a==0) return b;
		b%=a;
	}
	return a;
}

void process(void)
{
	int n,m,kk;
	scanf("%d %d %d",&n,&m,&kk);
	for(int i=0;i<105;i++) for(int j=0;j<105;j++) npath[i][j]=0;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		cost[a][b]=cost[b][a]=c;
		npath[a][b]++;npath[b][a]++;
	}

	for(int i=0;i<n;i++)
	{
		cost[i][i]=0;
		npath[i][i]=1;
	}

	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++) if(i!=k) if(npath[i][k])
		{
			for(int j=0;j<n;j++) if(j!=k && i!=j) if(npath[k][j])
			{
				if(npath[i][j] == 0 || cost[i][j] > cost[i][k] + cost[k][j])
				{
					npath[i][j] = 0;
					cost[i][j] = cost[i][k] + cost[k][j];
				}
				if(cost[i][j] == cost[i][k] + cost[k][j])
				{
					npath[i][j] += npath[i][k] * npath[k][j];
				}
			}
		}
	}

/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << npath[i][j] << " ";
		cout << endl;
	}
*/	
	cout << npath[0][n-1] << endl;

	for(int i=0;i<kk;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		tmp--;

		long long tmp2 = 0;
		if(cost[0][tmp] + cost[tmp][n-1] == cost[0][n-1])
		{
			tmp2 = npath[0][tmp] * npath[tmp][n-1];
		}
		long long tmp3 = npath[0][n-1];

		if(tmp2 == 0 && tmp3 == 0)
		{
			cout << "0/1" << endl;
			continue;
		}

		if(tmp2 == 0 || tmp3 == 0)
		{
			tmp2 /= (tmp2+tmp3);
			tmp3 /= (tmp2+tmp3);
		}
		else
		{
			long long tt = gcd(tmp2,tmp3);
			tmp2/=tt;
			tmp3/=tt;
		}

		cout << tmp2 << "/" << tmp3 << endl;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++) process();
}
