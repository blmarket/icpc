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

template<typename T> int size(const T &a) { return a.size(); } 

void process(void) {
    string str;
    map<char, int> M;
    getline(cin, str);
    for(int i=0;i<size(str);i++) {
        str[i] = tolower(str[i]);
        if(str[i] >= 'a' && str[i] <= 'z') {
            M[str[i]]++;
        }
    }
    vector<int> V;
    foreach(it, M) V.pb(it->second);
    sort(V.rbegin(), V.rend());
    int ret = 0;
    for(int i=0;i<size(V);i++) {
        ret += (26 - i) * V[i];
    }
    cout << ret << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    string str;
    getline(cin, str);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}
