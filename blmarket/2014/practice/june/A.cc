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

map<pair<string, string>, string> rules;
map<string, double> prs[505][505];

void process(void) {
    for(int i=0;i<505;i++) for(int j=0;j<505;j++) prs[i][j].clear();
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    cout << tmp << endl;

    for(int i=0;i<n;i++) {
        getline(cin, tmp);
        cout << tmp << endl;
        istringstream sin(tmp);
        while(true) {
            string tmp2;
            sin >> tmp2;
            if(tmp2 == "END") continue;
            double tmp3;
            sin >> tmp3;
            prs[i][i+1][tmp2] += tmp3;
        }
    }

    for(int i=0;i<n;i++) {
        auto tmp = prs[i][i+1];
        for(auto it : tmp) {
            cout << it.first << " " << it.second << endl;
        }
    }
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
