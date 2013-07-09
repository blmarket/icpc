#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
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

VI own;
vector<pair<int, long long> > E;

bool check(long long fati) {
    int it = 0;
    long long ff = fati;
    for(int i=0;i<size(E);i++) {
        while(it < size(own) && (ff == 0 || E[i].first > own[it])) {
            it++;
            ff = fati;
        }
        if(it >= size(own)) return false;

        long long tocut = E[i].second;

        while(tocut) {
            long long cc = min(ff, tocut);
            ff -= cc; tocut -= cc;
            if(tocut == 0) break;
            if(ff == 0) {
                it++;
                ff = fati;
            }
            if(it >= size(own)) return false;
        }

        // cout << fati << " : " << it << " " << ff << endl;
    }
    return true;
}

class SpaceWarDiv1 
{
public:
    long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) 
    {		
        own = magicalGirlStrength;
        E.clear();
        for(int i=0;i<size(enemyStrength);i++) {
            E.pb(mp(enemyStrength[i], enemyCount[i]));
        }

        sort(own.begin(), own.end());
        sort(E.begin(), E.end());

        if(own.back() < E.back().first) return -1;

        long long sum = 0;
        for(int i=0;i<size(enemyCount);i++) {
            sum += enemyCount[i];
        }
        long long s=0, e=sum;
        while(s<e) {
            long long m = (s+e)/2;
            if(check(m)) {
                e = m;
            } else {
                s = m+1;
            }
        }
        return e;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
