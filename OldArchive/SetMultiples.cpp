#include <iostream>
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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

class SetMultiples 
{
public:
    long long smallestSubset(long long A, long long B, long long C, long long D) 
    {
        if(C <= D/2) return D-D/2;

        LL ret = D-C+1;

        A = max(A,B/2+1);

        LL prevleft = D+1;
        LL prevright = D+1;

        cout << ret << endl;

        for(LL i=2;;i++)
        {
            LL left = (C+i-1)/i;
            LL right = D/i;

            if(left > right) goto nn;

            if(B > right)
            {
                cout << B - max(A-1, right) << endl;
                ret += B - max(A-1 , right);
            }
            B = min(B, left-1);

            if(B < A) return ret;

            if(right+1 >= prevleft)
            {
                cout << "skip from " << right << " " << prevleft << endl;
                return ret;
            }
nn:

            prevleft = left;
            prevright = right;
        }

        return ret;
    }
};


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
