#include <iostream>
#include <cmath>
#include <sstream>
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

struct tree
{
	tree() { lr[0] = lr[1] = 0; }
	long long value;
	struct tree *lr[2];
};
map<long long,int> memo;

tree* parse(char *inp, int &pos,int depth)
{
	tree *ret = new tree();
	if(inp[pos] == '[')
	{		
		pos++;
		ret->lr[0] = parse(inp,pos,depth+1);
		pos++;
		ret->lr[1] = parse(inp,pos,depth+1);
		pos++;
		return ret;
	}
	else
	{
		int tmp = pos;
		for(;inp[pos]>='0' && inp[pos]<='9';pos++);
		inp[pos]=0;
		sscanf(inp+tmp,"%lld",&(ret->value));
		memo[ret->value<<depth]++;
		return ret;
	}
}

void traverse(tree *node)
{
	if(node->lr[0])
	{
		cout << "[";
		traverse(node->lr[0]);
		cout << ",";
		traverse(node->lr[1]);
		cout << "]";
	}
	else
	{
		cout << node->value;
	}
}

bool calc(tree *node, long long tgt, int &ret)
{
	if(node->lr[0])
	{
		if(tgt % 2) return false;
		int t1,t2;
		if(calc(node->lr[0],tgt/2,t1) == false) return false;
		if(calc(node->lr[1],tgt/2,t2) == false) return false;
		ret = t1+t2;
		return true;
	}
	else
	{
		ret = tgt != node->value;
		return true;
	}
}

void process(void)
{
	char str[2000000];
	memo.clear();
	fgets(str,2000000,stdin);
	int pos = 0;
	tree *root = parse(str,pos,0);

	int maxx = 0;
	int tott = 0;
	foreach(iter, memo)
	{
		tott += iter->second;
		if(iter->second > maxx) maxx = iter->second;
	}
	cout << tott - maxx << endl;
}

int main(void)
{
	char str[1024];
	fgets(str,1024,stdin);
	int T;
	sscanf(str,"%d",&T);
	for(int i=0;i<T;i++)
	{
		process();
	}
	
}
