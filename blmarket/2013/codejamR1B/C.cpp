#include <fstream>
#include <iostream>
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

set<string> dict;
vector<string> wlist;

template<typename T> int size(const T &a) { return a.size(); } 

map<PII, int> memo;
string str;

int go(int a, int dist) {
}

void process(void) {
    memo.clear();
    cin >> str;
    cout << go(0, 0) << endl;
}

int main(void)
{
    ifstream fin("garbled_email_dictionary.txt");
    string str;
    while(fin >> str) {
        wlist.pb(str);
    }
    dict = set<string>(wlist.begin(), wlist.end());

    cout << wlist.size() << " " << dict.size() << endl;
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
