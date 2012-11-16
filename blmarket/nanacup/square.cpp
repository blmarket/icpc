#include <iostream>
#include <sys/time.h>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
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
#define ARRAYSIZE(a) ( sizeof(a) / sizeof((a)[0]) )

using namespace std;
using namespace std::tr1;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 
template<typename T> string toString(const T &a) { ostringstream ost; ost << a; return ost.str(); }

double initGetTime()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec * 0.000001;
}

double time_limit = 4.9;
double time_start = initGetTime();

double getTime()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return (tv.tv_sec + tv.tv_usec * 0.000001 - time_start);
}

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
vector<string> all_sqrs;

int choices[2] = { 100, 1 };
int totalchoices = accumulate(choices, choices + ARRAYSIZE(choices), 0);

struct seed_context {
    seed_context(const string &str, const unordered_map<string,int> &contains, int cnt) :
        str(str),
        contains(contains),
        cnt(cnt) 
    { }

    string str;
    unordered_map<string, int> contains;
    int cnt;
    int score;
    int ascore, bscore, cscore;

    int evaluate() {
        bscore = 0;
        foreach(it, contains) {
            bscore += b * it->second * size(it->first);
        }
        ascore = a*cnt, cscore = c * size(contains);
        //fprintf(stderr, "a : %d * %d = %d\n", a, cnt, ascore);
        //fprintf(stderr, "b : %d\n", bscore);
        //fprintf(stderr, "c : %d * %d = %d\n", c, size(contains), cscore);
        score = min(ascore, min(bscore, cscore));
    }

    string stratA() { // add one square
        str += '1';
        recalc();
        return go();
    }

    string stratB() { // add some specific square number
        int maxidx = size(all_sqrs);
        string tmp;
        while(true) {
            int idx = rand() % maxidx;
            tmp = all_sqrs[idx];
            if(size(str) + size(tmp) <= n) break;
            maxidx = idx;
        }
        for(int i=0;i<size(tmp);i++) {
            str += tmp[i];
            recalc();
        }
        return go();
    }

    string stratC() {
    }

    void recalc() {
        for(int i=1;i<min(8, size(str));i++) {
            string sub = str.substr(size(str) - i);
            if(sqrs.count(sub)) {
                contains[sub] += 1;
                cnt++;
            }
        }
    }

    string go() {
        evaluate();
        if(size(str) == n) return str;

        int ch = rand() % totalchoices;
        ch -= choices[0];
        if(ch < 0) {
            return stratA();
        }
        ch -= choices[1];
        if(ch < 0) {
            return stratB();
        }

        return stratB();
    }
};

int main(void)
{
    srand(time(NULL));
    for(int i=1;i<10000;i++) {
        string tmp = toString(i * i);
        sqrs.insert(toString(i * i));
        all_sqrs.pb(tmp);
    }

		scanf("%d %d %d %d", &n, &a, &b, &c);

    unordered_map<string, int> init;
    init["1"] = 1;
    init["9"] = 1;
    init["16"] = 1;

    string maxresult;
    int maxscore = -1;
    int i;
    for(i=0;getTime() < 4.9;i++) {
        seed_context seed("2916", init, 3);
        string tmp = seed.go();
        if(seed.score > maxscore) {
            maxscore = seed.score;
            maxresult = tmp;
            fprintf(stderr, "%s %d(%d,%d,%d) with %d trials\n", maxresult.c_str(), maxscore, seed.ascore, seed.bscore, seed.cscore, i);
        }
    } 
    cout << maxresult << endl;
    cerr << maxresult << " " << maxscore << " with " << i << " trials" << endl;
}
