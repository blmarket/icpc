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

int v[6];

int main(void) {
    for(int i=0;i<6;i++) scanf(" %d", &v[i]);
    sort(v, v+6);
    if(v[0] == v[3]) {
        cout << ((v[4] == v[5]) ? "Bear" : "Elephant") << endl;
        return 0;
    }
    if(v[1] == v[4]) {
        cout << "Bear" << endl;
        return 0;
    }
    cout << ((v[0] == v[1]) ? "Bear" : "Elephant") << endl;
    return 0;
}
