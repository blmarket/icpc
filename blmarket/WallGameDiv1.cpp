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

int N,M;
vector<string> cost;
vector<int> cur, nex;

int memo[55][55][2];
int sum[55];

int cc(int s, int e) {
    if(s<=e) return sum[e+1] - sum[s+1];
    return sum[s] - sum[e];
}

int go(int s, int e, bool left) {
    if(s == 0 && e == M) return -1;
    if(memo[s][e][left] != -1) return memo[s][e][left];

    int pos = left ? s : e - 1;

    int np1 = s-1;
    int np2 = e;
    int ret = -1;
    if(np1 >= 0) {
        int tmp = cc(pos, np1);
        int tmp2 = cur[np1];
        int tmp3 = go(np1, e, true);

        ret = max(tmp2, tmp3) + tmp;
    }

    if(np2 < M) {
        int tmp = cc(pos, np2);
        int tmp2 = cur[np2];
        int tmp3 = go(s, np2 + 1, false);

        int tmp4 = max(tmp2, tmp3) + tmp;
        if(ret == -1 || ret > tmp4) ret = tmp4;
    }

    return memo[s][e][left] = ret;
}

void calc(const string &c) {
    nex = cur;
    memset(memo, -1, sizeof(memo));
    memset(sum, 0, sizeof(sum));

    sum[0] = 0;
    for(int i=0;i<M;i++) {
        sum[i+1] = sum[i] + c[i];
    }

    for(int i=0;i<M;i++) {
        nex[i] += c[i];
        int tmp = go(i, i+1, true);
        if(tmp > nex[i]) nex[i] = tmp;
    }
}

class WallGameDiv1 
{
public:
    int play(vector <string> costs) 
    {	
        cost = costs;
        N = size(cost);
        M = size(cost[0]);
        for(int i=0;i<size(cost);i++) {
            for(int j=0;j<size(cost[i]);j++) cost[i][j] -= '0';
        }
        cur.resize(M);
        for(int i=0;i<M;i++) {
            cur[i] = cost.back()[i];
        }

        for(int i=N-2;i>=0;i--) {
            calc(cost[i]);
            cur.swap(nex);
            for(int i=0;i<M;i++) {
                cout << cur[i] << " ";
            }
            cout << endl;
        }

        int ret = cur[0];
        for(int i=1;i<M;i++) {
            ret = min(ret, cur[i]);
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12"
,"34"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, play(Arg0)); }
	void test_case_1() { string Arr0[] = {"99999"
,"99999"
,"99999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; verify_case(1, Arg1, play(Arg0)); }
	void test_case_2() { string Arr0[] = {"11111"
,"90005"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, play(Arg0)); }
	void test_case_3() { string Arr0[] = {"4417231387449337370319219832088987579792"
,"3117295688208899006196193430472892512797"
,"0835796222361526836944954410684516919758"
,"1988200069973565052900745230547016216225"
,"8080511471118865780390486996601082102418"
,"4229084185957675819725844582167613108400"
,"9068653877952162764545674979144308771754"
,"8551565425951612499712254182109991511690"
,"7090525592007482152807163656647658543093"
,"9198968742256995592729889137556032960142"
,"2071864379877766468141740053503050313101"
,"1055375249261868472993219156394129253481"
,"2461178270502857106406495509025426298874"
,"8216781259733537757203421037984512664825"
,"4693452554407216935375049784445568498482"
,"2709693439640250842244170297203200674391"
,"5122217695676372684217182241705137947908"
,"6668814191410691246849638388008228444294"
,"4952122070212780440963814752538149378639"
,"9827737761436134120332969866554332504400"
,"3412406588339828249986707470540386748886"
,"7521506848088506994554600408372456405830"
,"1916926179183007872881163173153907665999"
,"6636166791472761992310264951474925339024"
,"6679667717747231380196787943691121008076"
,"3218993234115685151069259138068533004433"
,"4920152552986426962081492913852060211795"
,"0365186235986445521382132973036266396894"
,"3205351414936828189305188614651974318855"
,"3144278971529524658788277656125598825426"
,"5525287537572356662391582052968411726245"
,"2130137226726919525622574701068062252930"
,"2369996694245544770519574837226971226841"
,"6806769058165410189286521891570936341547"
,"0448109211631660241710734664066810078242"
,"4622919135804954122810530631429501069659"
,"0235247446548732490429856705369583140671"
,"2193399741215975228987754171460722199304"
,"1203037020703833716225328076959743850915"
,"5419885193880826109484912489603262199432"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7366; verify_case(3, Arg1, play(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WallGameDiv1 ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
