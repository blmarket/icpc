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

map<int, VI> DD;

void subtract(VI &a, const VI &b, int mul)
{
	for(int i=0;i<11;i++)
		a[i] = (a[i] + 11 * mul - b[i] * mul) % 11;
}

void canonize(VI &a,int idx)
{
	for(int i=1;i<11;i++)
	{
		if( ((a[idx] * i) % 11) == 1)
		{
			for(int j=0;j<11;j++)
				a[j] = (a[j] * i) % 11;
			return;
		}
	}
}

void process(void)
{
	int n;
	cin >> n;
	VI s,e;
	vector<pair<int,VI> > data(n);
	s=e=VI(11);
	for(int i=0;i<11;i++)
		cin >> s[i];
	for(int i=0;i<11;i++)
	{
		cin >> e[i];
		e[i] = (e[i]-s[i]+11)%11;
	}

	for(int i=0;i<n;i++)
	{
		data[i].second.resize(11);
		for(int j=0;j<11;j++)
			cin >> data[i].second[j];
		cin >> data[i].first;
	}

	DD.clear();

	sort(data.begin(),data.end());
	for(int i=0;i<n;i++)
	{
		VI vec = data[i].second;
		for(int j=0;j<11;j++)
		{
			if(vec[j])
			{
				if(DD.count(j))
				{
					subtract(vec, DD[j], vec[j]);
				}
			}
		}

		for(int j=0;j<11;j++)
		{
			if(vec[j])
			{
				canonize(vec,j);
				DD[j] = vec;
				subtract(e,vec,e[j]);
				break;
			}
		}
		
		if(e == VI(11,0))
		{
			cout << data[i].first << endl;
			return;
		}
	}
	cout << "unreachable" << endl;
}

int main(void)
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
		process();
}
