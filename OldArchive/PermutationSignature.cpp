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

template<typename T> int size(const T &a) { return a.size(); } 

class PermutationSignature 
{
public:
    vector <int> reconstruct(string signature) 
    {
        cout << signature << endl;
        VI ret;

        for(int i=0;i<size(signature);i++)
        {
            if(signature[i] == 'I')
            {
                for(int j=0;j<=i;j++)
                {
                    ret.pb(i+1-j);
                }

                VI tmp = reconstruct(signature.substr(i+1));

                for(int j=0;j<size(tmp);j++)
                    ret.pb(tmp[j] + i + 1);

                return ret;
            }
        }

        ret.pb(size(signature)+1);
        for(int i=0;i<size(signature);i++)
        {
            ret.pb(size(signature)-i);
        }
        return ret;
    }
};
