#include <iostream>
#include <algorithm>
#include <functional>
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

int n;
vector<PII> V;

void print_second(vector<PII> &v) {
    for(int i=0;i<n;i++) cout << V[i].second+1 << " ";
    cout << endl;
}

int main(void) {
    scanf("%d" ,&n);
    for(int i=0;i<n;i++) {
        int tmp;
        scanf(" %d", &tmp);
        V.pb(mp(tmp, i));
    }
    sort(V.begin(), V.end());

    int pi = -1;
    for(int i=0;i+1<n;i++) {
        if(V[i].first == V[i+1].first) {
            if(pi == -1) {
                pi = i; continue;
            }
            cout << "YES" << endl;
            print_second(V);
            swap(V[i], V[i+1]);
            print_second(V);
            swap(V[pi], V[pi+1]);
            print_second(V);
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
