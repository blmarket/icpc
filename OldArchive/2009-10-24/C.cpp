#include <iostream>
#include <cmath>
#include <complex>
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

int N;
vector<pair<int,int> > V;

int ccw(int a,int b,int c,int d,int e,int f)
{
	int xx1 = c-a, xx2 = e-a;
	int yy1 = d-b, yy2 = f-b;
	return xx1 * yy2 - xx2 * yy1;
}

int ccw(PII a,PII b,PII c)
{
	return ccw(a.first,a.second,b.first,b.second,c.first,c.second);
}

bool comp(const PII &a, const PII &b)
{
	return atan2(a.second,a.first) < atan2(b.second,b.first);
}

double dist(const PII &a, const PII &b)
{
	return sqrt(sqr(a.first-b.first) + sqr(a.second - b.second));
}

bool check(double D)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(ccw(V[i],V[j],mp(0,0)) >= 0 && dist(V[i],V[j]) < D)
			{
				return true;
			}
		}
	}
	return false;
}

void process(void)
{
	cin >> N;
	V.resize(N);
	for(int i=0;i<N;i++)
		cin >> V[i].first >> V[i].second;

	sort(V.begin(),V.end(),comp);

/*
	for(int i=0;i<N;i++)
	{
		cout << V[i].first << " " << V[i].second << " ";
		if(i < N-1)
		{
			cout << ccw(V[i],V[i+1],mp(0,0));
		}
		else
		{
			cout << ccw(V[i],V[0], mp(0,0));
		}
		cout << endl;
	}
	cout << endl;
*/

	double s=0, e=1000000;
	while(e-s > 1e-5)
	{
		double m = (s+e)/2;
		double dist = 4.0+m;

		if(check(dist)) e=m; else s=m;
	}
}

int main(void)
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
		process();
}
