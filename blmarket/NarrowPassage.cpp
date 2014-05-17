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

template<typename T> int size(const T &a) { return a.size(); }

int idx(vector<int> &V, int t) { return lower_bound(V.begin(), V.end(), t) - V.begin(); }

vector<int> a,b,as,bs;
int L;
vector<PII> V;

int trial(int s, int e, bool left) {
    int ee = 0;
    if(!left) ee = L;

    int ret = 0;
    for(int i=s;i<e;i++) {
        ret += abs(ee - V[i].first) + abs(ee - V[i].second);
    }
    return ret;
}

class NarrowPassage 
{
public:
    int minDist(int L_, vector <int> a_, vector <int> b_) 
    {
        L = L_;
        a=a_;b=b_;
        V.clear();
        for(int i=0;i<size(a);i++) V.pb(mp(a[i], b[i]));
        sort(V.begin(), V.end());

        as = a, bs = b;
        sort(as.begin(), as.end());
        sort(bs.begin(), bs.end());

        vector<int> is;

        for(int i=0;i<size(V);i++) {
            int bi = idx(bs, V[i].second);
            is.pb(bi);
            cout << bi << " ";
        }
        cout << endl;

        int ret = -1;

        int pi = 999;
        int sum = 0;
        for(int i=0;i<size(V);i++) {
            if(i == is[i]) {
                bool fail = false;
                for(int j=0;j<i;j++) {
                    if(is[j] > i) {
                        fail = true;
                        break;
                    }
                }
                if(!fail) {
                    cout << "HERE " << pi << endl;
                    sum += abs(V[i].first - V[i].second);
                    int tmp = trial(0, min(pi, i), true) + trial(i+1, a.size(), false) + sum;
                    if(ret == -1 || ret > tmp) ret = tmp;
                    pi = i;
                    continue;
                }
            } 
            pi = 999;
            sum = 0;
        }

        for(int i=0;i<=size(V);i++) {
            int tmp = 0;
            int j, k;
            for(j=0;j<size(V)&&is[j]<i;j++) {
                tmp += V[j].first;
            }
            for(k=size(V)-1;k>=0&&is[k]>=i;k--) {
                tmp += (L - V[k].first);
            }

            if(j < k) {
                int tmp2 = 0, tmp3 = 0;
                for(int l=j;l<=k;l++) {
                    tmp2 += V[l].first;
                    if(is[l] >= i) tmp2 += L;
                    tmp3 += (L - V[l].first);
                    if(is[l] < i) tmp3 += L;
                }

                tmp += min(tmp2, tmp3);
            }

            for(int l=0;l<i;l++) tmp += V[l].second;
            for(int l=i;l<size(V);l++) tmp += (L - V[l].second);

            if(ret == -1 || ret > tmp) ret = tmp;
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, minDist(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {3, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 14; verify_case(1, Arg3, minDist(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 265467; int Arr1[] = {133548, 103861, 29821, 199848, 92684, 219824, 215859, 62821, 172409, 109235,
38563, 148854, 24742, 174068, 205005, 75922, 87316, 5542, 57484, 40792,
25229, 152216, 21547, 22203, 84712, 231522, 235703, 184895, 100787, 174440,
156904, 84898, 185568, 108732, 260098, 89488, 221604, 104555, 165775, 90444,
81952, 149671, 209674, 22185, 45420, 41928, 16098, 65324, 90870, 35243}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {150289, 135139, 69841, 227226, 177427, 230314, 199175, 81572, 220468, 151049,
40009, 145963, 115246, 252932, 263651, 38434, 120096, 69576, 29789, 115046,
33310, 260771, 5723, 80733, 107864, 142447, 235490, 242149, 124564, 134602,
245962, 7078, 215816, 219864, 190499, 210237, 212894, 142760, 126472, 201935,
119308, 120211, 235235, 19446, 87314, 17286, 61990, 102050, 261812, 257}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7148670; verify_case(2, Arg3, minDist(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000; int Arr1[] = {706292, 756214, 490048, 228791, 567805, 353900, 640393, 562496, 217533, 934149,
938644, 127480, 777134, 999144, 41485, 544051, 417987, 767415, 971662, 959022,
670563, 34065, 518183, 750574, 546576, 207758, 159932, 429345, 670513, 271901,
476062, 392721, 774733, 502586, 915436, 120280, 951729, 699859, 581770, 268966,
79392, 888601, 378829, 350198, 939459, 644983, 605862, 721305, 269232, 137587}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {322468, 673534, 83223, 551733, 341310, 485064, 885415, 927526, 159402, 28144,
441619, 305530, 883149, 413745, 932694, 214862, 677401, 104356, 836580, 300580,
409942, 748444, 744205, 119051, 999286, 462508, 984346, 887773, 856655, 245559,
418763, 840266, 999775, 962927, 779570, 488394, 760591, 326325, 206948, 13999,
285467, 401562, 786209, 169847, 171326, 2901, 296531, 572035, 364920, 939046}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 45670501; verify_case(3, Arg3, minDist(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    NarrowPassage ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
