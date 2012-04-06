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

long long facto[25];

long long getc(const map<char,int> &M)
{
	int tot=0;
	long long divi = 1;
	foreach(it,M)
	{
		tot += it->second;
		divi *= facto[it->second];
	}
	return facto[tot] / divi;
}

long long go(string str, map<char,int> mm)
{
	if(str == "") return 0; long long ret = 0;
	for(char i='A';i<str[0];i++)
	{
		if(mm[i])
		{
			mm[i]--;
			ret += getc(mm);
			mm[i]++;
		}
	}
	mm[str[0]]--;
	return ret + go(str.substr(1),mm);
}

void process(void)
{
	string str;
	map<char,int> mm;
	cin >> str;

	for(int i=0;i<str.size();i++)
		mm[str[i]]++;
		
	cout << go(str,mm) << endl;
}

int main(void)
{
	facto[0] = facto[1]=1;
	for(int i=2;i<=20;i++)
		facto[i] = facto[i-1] * i;

	int T;
	cin >> T;
	for(int i=0;i<T;i++)
		process();
}
