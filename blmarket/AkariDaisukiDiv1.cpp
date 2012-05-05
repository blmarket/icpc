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

string a,b,c,S,F;
const int mod = 1000000007;

string getleft_(int k, int len)
{
    if(len <= 0) return "";
    if(k == 0) return S;
    string tmp = a + getleft_(k-1, len-size(a));
    if(size(tmp) >= len) return tmp;
    tmp += b;
    if(size(tmp) >= len) return tmp;
    tmp += getleft_(k-1, len - size(tmp));
    if(size(tmp) >= len) return tmp;
    tmp += c;
    return tmp;
}

bool flag1 = false;
string getleft(int k, int len)
{
    static string tmp;
    if(flag1) return tmp;
    string ret = getleft_(k, len);
    if(ret == tmp)
    {
        flag1 = true;
    }
    tmp = ret;
    return ret;
}

string getright_(int k, int len)
{
    if(len <= 0) return "";
    if(k == 0) return S;
    string tmp = getright_(k-1, len - size(c)) + c;
    if(size(tmp) >= len) return tmp;
    tmp = b + tmp;
    if(size(tmp) >= len) return tmp;
    tmp = getleft(k-1, len - size(tmp)) + tmp;
    if(size(tmp) >= len) return tmp;
    tmp = a + tmp;
    return tmp;
}

bool flag2 = false;
string getright(int k, int len)
{
    static string tmp;
    if(flag2) return tmp;
    string ret = getright_(k, len);
    if(ret == tmp)
    {
        flag2 = true;
    }
    tmp = ret;
    return ret;
}

int fuck(const string &base, const string &t, int s, int e)
{
    int ret = 0;
    for(int i=s;i<e;i++)
    {
        if(i + size(t) > size(base)) break;
        if(base.substr(i, size(t)) == t) ret++;
    }
    return ret;
}

int prevmore = -1;
int count(int k, int prevcount)
{
    //cout << k << " " << F << endl;
    if(k == 0)
    {
        int ret = 0;
        int len = size(S) - size(F) + 1;
        for(int i=0;i<len;i++)
        {
            if(S.substr(i, size(F)) == F) ret++;
        }
        return ret;
    }

    int ret = prevcount;
    ret *= 2;
    ret %= mod;

    int more = 0;

    if(flag1 && flag2)
    {
        more = prevmore;
    }
    else
    {
        string left = getleft(k-1, 50);
        string right = getright(k-1, 50);

        string s1 = a + left + b + left + c;
        more += fuck(s1, F, max(0, size(a)-size(F)+1), size(a));
        string s2 = right + b + left + c;
        more += fuck(s2, F, max(0, size(right) - size(F) + 1), size(right) + size(b));
        string s3 = right + c;
        more += fuck(s3, F, max(0, size(right) - size(F) + 1), size(right));
    }
    ret += more;
    prevmore = more;
    ret %= mod;

    return ret;
}

class AkariDaisukiDiv1 
{
public:
	int countF(string Waai, string Akari, string Daisuki, string S_, string F_, int k) 
	{
            S = S_;
            a = Waai;
            b = Akari;
            c = Daisuki;
            F = F_;

            int ret = -1, prev = -1;
            for(int i=0;i<=k;i++)
            {
                ret = count(i, prev);
                prev = ret;
            }
            return ret;
	}
	

};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
