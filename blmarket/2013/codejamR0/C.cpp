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

vector<vector<int> > V;

bool go(void) {
    int small = 101;
    for(int i=0;i<size(V);i++) {
        for(int j=0;j<size(V[i]);j++) {
            cout << V[i][j] << " ";
            if(small > V[i][j]) small = V[i][j];
        }
        cout << endl;
    }

    cout << small << endl;

    for(int i=0;i<size(V);i++) {
        bool good = true;
        for(int j=0;j<size(V[i]);j++) {
            if(V[i][j] != small) { good = false; break; }
        }
        if(good) {
            for(int k=i;k+1<size(V);k++) {
                V[k] = V[k+1];
            }
            return go();
        }
    }

    for(int i=0;i<size(V[0]);i++) {
        bool good = true;
        for(int j=0;j<size(V);j++) {
            if(V[j][i] != small) { good = false; break; }
        }
        if(good) {
            for(int k=0;k<size(V);k++) {
                V[k].erase(V[k].begin() + i, V[k].begin() + i + 1);
            }
            return go();
        }
    }

    return false;
}

void process(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    V.resize(n);
    for(int i=0;i<n;i++) {
        V[i].resize(m);
        for(int j=0;j<m;j++) {
            scanf("%d", &V[i][j]);
        }
    }

    if(go()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
