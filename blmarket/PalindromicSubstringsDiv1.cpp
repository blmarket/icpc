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

string S;

double palins[5005][5005];

class PalindromicSubstringsDiv1 
{
public:
    double expectedPalindromes(vector <string> S1, vector <string> S2) 
    {		
        memset(palins, 0, sizeof(palins));
        S.clear();
        for(int i=0;i<size(S1);i++) S += S1[i];
        for(int i=0;i<size(S2);i++) S += S2[i];

        double ret = 0;

        for(int i=0;i<size(S);i++) {
            palins[i][i+1] = 1.0;
            ret += 1.0;
        }

        for(int i=0;i+1<size(S);i++) {
            if(S[i] == '?' || S[i+1] == '?') {
                palins[i][i+2] = 1.0 / 26;
            } else {
                if(S[i] == S[i+1]) {
                    palins[i][i+2] = 1.0;
                } else {
                    palins[i][i+2] = 0.0;
                }
            }
            ret += palins[i][i+2];
        }

        for(int i=3;i<=size(S);i++) {
            for(int j=0;j+i<=size(S);j++) {
                int k = j + i;
                double &tgt = palins[j][k];
                const double &pp = palins[j+1][k-1];
                if(S[j] == '?' || S[k-1] == '?') {
                    tgt += pp / 26;
                } else {
                    if(S[j] == S[k-1]) {
                        tgt = pp;
                    } else {
                        tgt = 0;
                    }
                }
                ret += tgt;
            }
        }

        return ret;
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
