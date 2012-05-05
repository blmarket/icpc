#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

vector<int> data;
vector<int> ms;
map<pair<int,long long>,bool> memo;

int go(int mpos, long long k)
{
    if(k < 0) return 0;
    pair<int, long long> key = make_pair(mpos, k);

    if(mpos == 0)
    {
        if(ms[0] == 0)
        {
            if(k == 0) return 1;
            return 0;
        }
        if(k >= size(data)) return 0;
        return data[k];		
    }

    if(ms[mpos] == 0) return go(mpos-1, k);

    cout << mpos << " " << k << " " << (1LL<<(mpos+1)) * size(data) << endl;

    if(k >= (1LL<<(mpos+1)) * size(data) ) return 0; // rough cut

    if(memo.count(key) == 1) return memo[key];

    int ret = 0;
    for(int i=0;i<size(data);i++)
    {
        if(data[i] == 0) continue;
        long long tmp = (1LL<<mpos) * i;
        ret ^= go(mpos-1, k-tmp);
    }

    memo[key] = ret;
    return ret;
}

class BinaryPolynomialDivOne
{
public:
	int findCoefficient(vector<int> aa, long long m, long long k)
	{
		data = aa;
		while(m)
		{
			ms.pb((m % 2));
			m>>=1;
		}
		for(int i=0;i<size(ms);i++)
			cout << ms[i] << " ";
		cout << endl;
		if(size(ms) == 0) ms.pb(0);
		return go(size(ms)-1, k);		
	}
};
