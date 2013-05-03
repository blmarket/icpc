#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

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

int N;
vector<int> a,b;
int parent[55];
int match[55][55];
bool group1[55];

void findpar(int pos, int par) {
    cout << pos << " par " << par << endl;
    parent[pos] = par;
    for(int i=0;i<size(a);i++) {
        if(a[i] == pos || b[i] == pos) {
            if(a[i] == par || b[i] == par) continue;
            findpar(a[i]+b[i]-pos, pos);
        }
    }
}

int try_flow(const VVI &matt, VI &move, VI &used) {
    VI mc1(size(move), -1);
    VI mc2(size(used), -1), back(size(used), -1);

    for(int i=0;i<size(move);i++) if(move[i] == -1) mc1[i] = 0;
    while(true) {
        bool update = false;
        for(int i=0;i<size(mc1);i++) if(mc1[i] != -1) {
            for(int j=0;j<size(mc2);j++) {
                int tmp = mc1[i] + matt[i][j];
                if(mc2[j] == -1 || mc2[j] > tmp) {
                    back[j] = i;
                    mc2[j] = tmp;
                    update = true;
                }
            }
        }
        for(int i=0;i<size(mc2);i++) if(used[i] != -1) {
            int j = used[i];
            int tmp = mc2[i] - matt[j][i];
            if(mc1[j] == -1 || mc1[j] > tmp) {
                mc1[j] = tmp, update = true;
            }
        }
        if(!update) break;
    }

    int mincost = -1, md;
    for(int i=0;i<size(used);i++) if(mc2[i] != -1 && used[i] == -1) {
        if(mincost == -1 || mincost > mc2[i]) {
            mincost = mc2[i]; md = i;
        }
    }

    while(md != -1) {
        used[md] = back[md];
        int tmp = move[back[md]];
        move[back[md]] = md;
        md = tmp;
    }

    return mincost;
}

void mcmf(const VVI &matt, int &flow, int &cost) {
    cost = 0; flow = 0;
    if(size(matt) == 0) {
        return;
    }

    VI move(size(matt), -1);
    VI used(size(matt[0]), -1);
    flow = min(size(matt), size(matt[0]));
    cost = 0;
    for(int i=0;i<flow;i++) {
        cost += try_flow(matt, move, used);
    }
}

int calc(int p1, int p2) {
    if(match[p1][p2] != -1) return match[p1][p2];

    vector<int> c1, c2;
    for(int i=0;i<N;i++) if(parent[i] == p1) c1.pb(i);
    for(int i=0;i<N;i++) if(parent[i] == p2) c2.pb(i);

    if(size(c1) == 0 || size(c2) == 0) {
        return match[p1][p2] = match[p2][p1] = 1;
    }

    VVI matt(c1.size());
    for(int i=0;i<size(c1);i++) {
        matt[i].resize(size(c2));
        for(int j=0;j<size(c2);j++) {
            matt[i][j] = 100 - calc(c1[i], c2[j]);
        }
    }

    int flow, cost;
    /*
    for(int i=0;i<size(matt);i++) {
        for(int j=0;j<size(matt[i]);j++) cout << matt[i][j] << " ";
        cout << endl;
    }
    cout << " = " << flow << " " << cost << endl;
    */
    mcmf(matt, flow, cost);
    match[p1][p2] = match[p2][p1] = 1 + flow * 100 - cost;
    return match[p1][p2];
}

void dfs(int pos) {
    if(group1[pos]) return;
    group1[pos] = true;
    for(int i=0;i<N;i++) if(parent[i] == pos) dfs(i);
}

int go(int pos) {
    findpar(a[pos], b[pos]);
    findpar(b[pos], a[pos]);

    parent[a[pos]] = parent[b[pos]] = -1;

    cout << endl;
    memset(group1, 0, sizeof(group1));
    memset(match, -1, sizeof(match));
    dfs(a[pos]);

    int ret = 0;
    for(int i=0;i<N;i++) if(group1[i]) {
        for(int j=0;j<N;j++) if(!group1[j]) {
            int tmp = calc(i,j);
            if(ret < tmp) {
                cout << i << " " << j << " " << tmp << endl;
                ret = tmp;
            }
        }
    }

    return ret;
}

class DeerInZooDivOne 
{
public:
    int getmax(vector <int> a_, vector <int> b_) 
    {
        a=a_;b=b_; N = size(a) + 1;
        int ret = 0;
        for(int i=0;i<size(a);i++) {
            // cout << i << " " << ret << endl;
            int tmp = go(i);
            cout << i << " " << tmp << endl;
            if(ret < tmp) ret = tmp;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 8, 1, 7, 4, 2, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 3, 6, 8, 2, 6, 8, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 11, 10, 10, 19, 17, 6, 17, 19, 10, 10, 11, 9, 9, 14, 2, 13, 11, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 5, 2, 12, 8, 9, 16, 8, 4, 18, 8, 13, 15, 13, 17, 16, 3, 1, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {14, 13, 28, 15, 20, 4, 9, 6, 1, 23, 19, 25, 25, 8, 14, 16, 2, 8, 15, 25, 22, 22, 28, 10, 10, 14, 24, 27, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {21, 5, 12, 13, 27, 1, 24, 17, 27, 17, 23, 14, 18, 26, 7, 26, 11, 0, 25, 23, 3, 29, 22, 11, 22, 29, 15, 28, 29}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(4, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DeerInZooDivOne ___test; 
    ___test.run_test(3); 
} 
// END CUT HERE
