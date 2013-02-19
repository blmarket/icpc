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

const int maxn = 52;

int N;
int A[maxn][maxn];
long long adj[maxn];
int cost[maxn];
int answer;
int p[maxn];
int was[maxn];

void bct(int ind, int cnt, LL mask) {
    if(ind == N) {
        if(3 * cnt < 2 * N) return;
        int cur = 0;
        for(int i=0;i<N;i++) {
            if(was[i]) cur += cost[i];
        }
        answer = max(answer, cur);
        return;
    }
    int cur = 0;
    int q = cnt;
    for(int i=0; i<ind; i++) 
        if(was[p[i]]) cur += cost[p[i]];
    for(int i=ind;i<N;i++) {
        if((1LL << p[i]) & mask) {
            cur += cost[p[i]];
            q++;
        }
    }
    if(3 * q < 2 * N) return;
    if(cur < answer) return;
    if(mask & (1LL << p[ind])) {
        was[p[ind]] = 1;
        bct(ind+1, cnt+1, mask & adj[p[ind]]);
    }
    was[p[ind]] = 0;
    bct(ind+1, cnt, mask);
}

class MagicMolecule 
{
public:
    int maxMagicPower(vector <int> magicPower, vector <string> magicBond) 
    {		
        N = size(magicPower);
        for(int i=0;i<N;i++) {
            p[i] = i;
            cost[i] = magicPower[i];
            for(int j=0;j<N;j++) {
                if(i == j) A[i][j] = 1;
                else A[i][j] = (magicBond[i][j] == 'Y');
                adj[i] |= (A[i][j] * 1LL) << j;
            }
        }

        srand(time(NULL));
        random_shuffle(p, p + N);
        answer = -1;
        bct(0, 0, (1LL << N) - 1);
        return answer;
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
