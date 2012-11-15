#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
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

class bigint {
public:
		bigint(const bigint &rhs) { V = rhs.V; }
		bigint(string str);

		bigint operator*(const bigint &rhs);
		bigint& operator*=(int rhs);
		bigint operator*(int rhs) { bigint ret(*this); ret *= rhs; return ret; }

		vector<int> V;
};

bigint bigint::operator*(const bigint &rhs) {
		return bigint("0");
}

bigint& bigint::operator*=(int rhs) {
		long long tmp = 0;
		for(int i=0;i<size(V);i++) {
				tmp = tmp + (long long)V[i] * rhs;
				V[i] = tmp % 10000;
				tmp /= 10000;
		}
		while(tmp) {
				V.pb(tmp % 10000);
				tmp /= 10000;
		}
		return *this;
}

bigint::bigint(string str) {
		V.clear();
		while(str.size() > 0) {
				if(size(str) >= 4) {
						V.pb(atoi(str.substr(size(str) - 4).c_str()));
						str = str.substr(0, size(str) - 4);
				} else {
						V.pb(atoi(str.c_str()));
						break;
				}
		}
}

ostream &operator<<(ostream &ost, const bigint &bi) {
		if(size(bi.V) == 0) return ost;
		ost << bi.V.back();
		for(int i=size(bi.V) - 2;i>=0; i--) {
				ost << setfill('0') << setw(4) << bi.V[i];
		}
		return ost;
}

int main(void)
{
		cout << bigint("10000000000000001") << endl;
		cout << bigint("123") * 456 << endl;
}
