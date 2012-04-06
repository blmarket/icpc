#include <iostream>
#include <cmath>
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

long long sz[16];

PII go(long long n, long long pos)
{
	if(n == 1)
	{
		switch(pos)
		{
			case 0:
				return mp(0,0);
			case 1:
				return mp(0,1);
			case 2:
				return mp(1,1);
			case 3:
				return mp(1,0);
		}
	}

	if(pos < sz[n-1])
	{
		PII tmp = go(n-1,pos);
		swap(tmp.first,tmp.second);
		return tmp;
	}
	pos -= sz[n-1];
	if(pos < sz[n-1])
	{
		PII tmp = go(n-1,pos);
		tmp.second += (1<<(n-1));
		return tmp;
	}
	pos -= sz[n-1];
	if(pos < sz[n-1])
	{
		PII tmp = go(n-1,pos);
		tmp.first += (1<<(n-1));
		tmp.second += (1<<(n-1));
		return tmp;
	}
	pos -= sz[n-1];
	PII tmp = go(n-1,pos);
	PII tmp2;
	long long sz = (1<<(n-1));
	tmp2.first = sz-1-tmp.second+sz;
	tmp2.second = sz-1-tmp.first;
	return tmp2;
}

void process(void)
{
	long long n;
	long long s,t;
	cin >> n >> s >> t;
	s--;t--;
	sz[1] = 4;
	for(int i=2;i<16;i++)
		sz[i] = sz[i-1]*4;

	PII p1 = go(n,s);
	PII p2 = go(n,t);

	double dist = sqrt(sqr(p1.first-p2.first) + sqr(p1.second - p2.second)) * 10.0;
	cout << (int)(dist + 0.5) << endl;
}

int main(void)
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++) process();
}
