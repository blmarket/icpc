#include <iostream>
#include <tr1/unordered_set>
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
using namespace std::tr1;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 
template<typename T> string toString(const T &a) { ostringstream ost; ost << a; return ost.str(); }

class bigint {
public:
		bigint() { }
		bigint(const bigint &rhs) { V = rhs.V; }
		bigint(string str);

		bigint operator*(const bigint &rhs);
		bigint& operator*=(int rhs);
		bigint operator*(int rhs) { bigint ret(*this); ret *= rhs; return ret; }
    bool operator==(const bigint &rhs);
    bool operator<(const bigint &rhs);

		// offset 위치부터 rhs에 있는 값들을 더한다.
		void shiftadd(int offset, const bigint &rhs);
    int hash() const;

		vector<int> V;
};

bool bigint::operator<(const bigint &rhs) {
    if(size(V) != size(rhs.V)) return size(V) < size(rhs.V);
    for(int i=size(V)-1;i>=0;i--) {
        if(V[i] != rhs.V[i]) return V[i] < rhs.V[i];
    }
    return false; // it's same!
}

bool bigint::operator==(const bigint &rhs) {
    if(size(V) != size(rhs.V)) return false;
    for(int i=0;i<size(V);i++) {
        if(V[i] != rhs.V[i]) return false;
    }
    return true;
}

void bigint::shiftadd(int offset, const bigint &rhs) {
		for(int i=0;i<size(rhs.V);i++) {
				int pos = offset + i;
				if(size(V) <= pos) {
						V.resize(pos + 1);
				}
				V[pos] += rhs.V[i];
		}
		for(int i=0;i+1<size(V);i++) {
				if(V[i] > 10000) {
						V[i+1]++;
						V[i] -= 10000;
				}
		}
		if(V.back() > 10000) {
				V.back() -= 10000;
				V.pb(1);
		}
}

bigint bigint::operator*(const bigint &rhs) {
		bigint ret;
		bigint tmp;
		for(int i=0;i<size(V);i++) {
				tmp = rhs;
				tmp *= V[i];
				ret.shiftadd(i, tmp);
		}
		return ret;
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

int n,a,b,c;
unordered_set<string> sqrs;

void check(const string &in) {
    cout << in << endl;
    for(int i=1;i<=size(in);i++) {
        for(int j=0;j+i <= size(in); j++) {
            string tmp = in.substr(j, i);
            if(tmp[0] == '0') continue;
            if(sqrs.count(tmp)) {
                cout << tmp << " ";
            }
        }
    }
    cout << endl;
}

int main(void)
{
    srand(time(NULL));
    for(int i=1;i<100;i++) {
        sqrs.insert(toString(i * i));
    }
    foreach(it, sqrs) {
        cout << *it << " ";
    }
    cout << endl;

		scanf("%d %d %d %d", &n, &a, &b, &c);

    for(int trial=0;trial<1;trial++) {
        string tmp(1, '1' + (rand() % 9));
        for(int i=1;i<n;i++) {
            tmp += '0' + (rand() % 10);
        }
        check(tmp);
    }
}
