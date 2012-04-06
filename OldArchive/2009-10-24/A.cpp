#include <cstdio>
#include <algorithm>
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

vector<pair<double,int> > V;
const double g = 9.81;
const double PI = M_PI;

double simulate(int deg)
{
	double rad = deg * PI / 180;
	double x,y;
	x=0,y=1.0;
	double vx = 25.0 * cos((double)rad);
	double vy = 25.0 * sin((double)rad);

	double t = (vy + sqrt(sqr(vy) + 2*y*g)) / g;
	x += vx*t;

	while(true)
	{
		double nx = x + (vx/5);
		vector<pair<double,int> >::iterator iter = lower_bound(V.begin(),V.end(),mp(x,0));
		if(iter != V.end() && nx > iter->first)
		{
			if(iter->second == 1) return -100;
			vx = vx - (iter->first - x) * 5 + 4;
			x = iter->first + 2;
		}
		else
		{
			return nx;
		}
	}
}

void process(void)
{
	int n;
	V.clear();
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char tmp2[100];
		double tmp;
		int tmp3;

		scanf("%lf %s",&tmp,tmp2);
		if(tmp2[0] == 's') tmp3=1; else tmp3=2;
		V.pb(mp(tmp,tmp3));
	}

	sort(V.begin(),V.end());

	int maxscore = -9999;
	int maxdeg;
	for(int i=-90;i<=90;i++)
	{
		double tmp = simulate(i);
		int score = (int)(tmp*100+0.5);
		if(score > maxscore)
		{
			maxscore = score;
			maxdeg = i;
		}
	}

	printf("%d %d\n",maxscore, maxdeg);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++) process();
}
