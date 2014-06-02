#include <iostream>
#include <sys/wait.h>
#include <cstdlib>
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

typedef map<string, double> MAP;

map<pair<string, string>, string> rules;
MAP prs[505][505];

MAP mix(const MAP &a, const MAP &b) {
    MAP ret;
    for(auto &it: a) {
        for(auto &jt: b) {
            pair<string, string> tok = mp(it.first, jt.first);
            if(rules.count(tok)) {
                ret[rules[tok]] += it.second * jt.second;
            }
        }
    }
    return ret;
}

void process(void) {
    for(int i=0;i<505;i++) for(int j=0;j<505;j++) prs[i][j].clear();
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);

    for(int i=0;i<n;i++) {
        getline(cin, tmp);
        istringstream sin(tmp);
        while(true) {
            string tmp2;
            sin >> tmp2;
            if(tmp2 == "END") break;
            double tmp3;
            sin >> tmp3;
            prs[i][i+1][tmp2] += tmp3;
        }
    }

    for(int L=2;L<=n;L++) {
        for(int i=0;i+L<=n;i++) {
            for(int j=i+1;j<i+L;j++) {
                auto tmp = mix(prs[i][j], prs[j][i+L]);
                for(auto &it: tmp) {
                    prs[i][i+L][it.first] += it.second;
                }
            }
        }
    }

    if(prs[0][n].size() == 0) {
        cout << "GAMEOVER" << endl;
        return;
    }

    double max = 0;
    string ret;
    for(auto &it : prs[0][n]) {
        if(max < it.second) {
            max = it.second;
            ret = it.first;
        }
    }
    cout << ret << endl;
}

int main(void) {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        string a,b,c;
        cin >> a >> b >> c;
        rules[mp(a,b)] = c;
        rules[mp(b,a)] = c;
    }

    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        process();
    }
    return 0;
}
