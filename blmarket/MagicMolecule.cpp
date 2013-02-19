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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

int N, M;
vector<int> pow;
vector<string> bond;

struct state {
    state(int pos, LL dis, int pc) : pos(pos), dis(dis), pick_cnt(pc) {};

    int pos;
    LL dis;
    int pick_cnt;

    bool operator<(const state &rhs) const {
        if(pos != rhs.pos) return pos < rhs.pos;
        if(pick_cnt != rhs.pick_cnt) return pick_cnt < rhs.pick_cnt;
        return dis < rhs.dis;
    }
};

map<state, int> memo;

int go(int a, LL dis, int pc) {
    if(N-a + pc < M) return -1;
    if(a == N) {
        return 0;
    }
    if(dis & 1) {
        return go(a+1, dis >> 1, pc);
    }

    state key(a, dis, pc);
    if(memo.count(key)) return memo[key];

    int tmp1 = go(a+1, dis >> 1, pc);
    dis >>= 1;
    for(int i=a+1;i<N;i++) if(bond[a][i] == 'N') {
        int pp = i - a - 1;
        dis |= (1LL << pp);
    }
    int tmp2 = go(a+1, dis, pc + 1);
    if(tmp2 != -1) tmp2 += pow[a];

    return memo[key] = max(tmp1, tmp2);
}

class MagicMolecule 
{
public:
    int maxMagicPower(vector <int> magicPower, vector <string> magicBond) 
    {		
        pow = magicPower;
        bond = magicBond;
        memo.clear();
        N = size(pow);
        M = (N * 2 + 2) / 3;

        /*
        cout << M << endl;
        for(int i=0;i<N;i++) {
            cout << i << " : ";
            for(int j=0;j<N;j++) if(i != j) {
                if(bond[i][j] == 'N') {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
        */

        return go(0, 0, 0);
    }

    

};

int main(void) {

    int data[50] = {5802, 47, 1319, 5269, 5879, 1487, 3836, 6727, 2882, 696, 982, 9794, 778, 8187, 9723, 6292, 799, 1623, 7684, 3889, 7914, 2420, 3125, 3443, 2427, 8655, 3546, 6415, 2290, 7368, 9027, 1337, 1186, 7753, 2914, 1947, 4386};
    string bond[50] = {"NYYNYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYY", "YNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYNNYYYNYYYNYYYYYYYYYYYYYYYYYYYYYYYYY", "NYNNYYYNYYYYYYYYYYYYYYYNYYYYYYYYYYYYY", "YYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYNNYYYYYYYYYYYYYYYYYYNYYYYYNYYYY", "YYNNYYNNYYYYYYNYYYYYYYYYYYYYYYNYYNYYY", "YYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYNYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYNYYYYYYNYYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYNYYYYYYNYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYNYYYYNYYYYYYYYNYYY", "YYYYYYYYYYYYYYYYYYYYNYYYNYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYY", "YYYNYYYYYYYYYYYYNYYYYYYNYNYYYYYNYYYNY", "YYYYYYYYYYYYYYYYYYYNNYYYNYYYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYY", "YYYYYYNYYYYYYYYYYYYYYYYYYYNYYYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYYYYNY", "YYYYYYYNYYYYYYYYYYYYYYYYYYYYYYNYYYYYY", "YYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYNYYYYY", "YYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYNYYYY", "YYYYYYYNYYYYYYYYYYYNYYYYYYYYYYYYYNYYY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYY", "YYYYYYYYYYYYYYYYYYYYYYYNYYYYYNYYYYYNY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYN"};

    vector<int> p(data, data+50);
    vector<string> b(bond, bond+50);

    MagicMolecule tt;
    cout << tt.maxMagicPower(p, b) << endl;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
