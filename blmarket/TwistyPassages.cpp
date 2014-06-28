#include <iostream>
#include <cstring>
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

int n;
vector<int> rr[55];
char diff[55][55][55][55];

void add_diff(int s1, int e1, int s2, int e2) {
    if(rr[s1].size() != rr[s2].size()) return;

    int p1 = find(rr[s1].begin(), rr[s1].end(), e1) - rr[s1].begin();
    int p2 = find(rr[s2].begin(), rr[s2].end(), e2) - rr[s2].begin();

    int sz = size(rr[s1]);
    vector<tuple<int, int, int, int> > VT;
    for(int i=1;i<sz;i++) {
        int pp1 = rr[s1][(p1 + i) % sz];
        int pp2 = rr[s2][(p2 + i) % sz];
        if(diff[pp1][s1][pp2][s2] == 0) {
            VT.pb(make_tuple(pp1, s1, pp2, s2));
            diff[pp1][s1][pp2][s2] = 1;
        }
    }
    for(int i=0;i<size(VT);i++) {
        int a,b,c,d;
        tie(a,b,c,d) = VT[i];
        add_diff(a,b,c,d);
    }
}

bool check_diff(int a, int b) {
    int sz = size(rr[a]);
    if(sz == 0) return true;
    for(int i=0;i<sz;i++) {
        bool same = true;
        for(int j=0;j<sz;j++) {
            int n1 = rr[a][j];
            int n2 = rr[b][(i+j)%sz];
            if(diff[a][n1][b][n2]) { same = false; break; }
        }
        if(same) return true;
    }
    return false;
}

class TwistyPassages 
{
public:
    vector <int> similarRooms(vector <string> maze) 
    {		
        memset(diff, 0, sizeof(diff));
        n = size(maze);
        for(int i=0;i<n;i++) {
            rr[i].clear();
            istringstream sin(maze[i]);
            int tmp;
            while(sin >> tmp) {
                rr[i].pb(tmp);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(rr[i].size() == rr[j].size()) continue;
                for(auto a: rr[i]) {
                    for(auto b: rr[j]) {
                        if(!diff[a][i][b][j]) {
                            diff[a][i][b][j] = 1;
                            add_diff(a, i, b, j);
                        }
                        if(!diff[b][j][a][i]) {
                            diff[b][j][a][i] = 1;
                            add_diff(b, j, a, i);
                        }
                    }
                }
            }
        }

        bool chk[105];
        memset(chk, 0, sizeof(chk));

        vector<int> ret(n, 0);

        for(int i=0;i<n;i++) if(!chk[i]) {
            chk[i] = true;
            vector<int> V;
            V.pb(i);
            for(int j=i+1;j<n;j++) if(!chk[j]) {
                if(rr[i].size() != rr[j].size()) continue;
                if(check_diff(i, j)) {
                    V.pb(j);
                    chk[j] = true;
                    continue;
                }
            }
            for(int j=0;j<size(V);j++) {
                ret[V[j]] = size(V) - 1;
            }
        }
        return ret;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
