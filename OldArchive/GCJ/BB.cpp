#include <iostream>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define MOD 10009

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

vector<map<char,int> > words;
string equation;
vector<int> perm;
map<VI,int> memo;

int transform(VI &io)
{
    int cnt=0;
    map<int,int> M;
    for(int i=0;i<io.size();i++)
    {
        if(M.count(io[i]) == 0)
            M[io[i]]=cnt++;
        io[i] = M[io[i]];
    }
    return cnt;
}

int calc(const VI& in)
{
    VVI vals;

    // memo
    for(int i=0;;i++)
    {
        vals.pb(VI(words.size(),1));
        bool found = false;
        for(int j=0;j<in.size();j++) if(in[j] == i)
        {
            found = true;
            for(int k=0;k<words.size();k++)
            {
                vals.back()[k] *= words[k][equation[j]];
                vals.back()[k] %= MOD;
            }
        }
        if(found == false) 
        {
            vals.pop_back();
            break;
        }
    }

    int mul = 1;
    for(int i=0;i<vals.size();i++)
    {
        int sum = 0;
        for(int j=0;j<vals[i].size();j++)
            sum += vals[i][j];
        sum %= MOD;

        mul = (mul * sum) % MOD;
    }

    return mul;
}

int permute(int a,int b)
{
    if(b == equation.size())
    {
        VI tmp = perm;
        int cnt = transform(tmp);
        int tmp2 = calc(tmp);
        for(;cnt<a;cnt++)
            tmp2 = (tmp2 * words.size()) % MOD;
        return tmp2;
    }

    int ret = 0;
    perm.push_back(0);
    for(int i=0;i<a;i++)
    {
        perm.back() = i;
        ret = (ret + permute(a,b+1)) % MOD;
    }
    perm.pop_back();
    return ret;
}

void process(void)
{
    int K;
    string str;
    cin >> str >> K;
    int N;
    cin >> N;
    words.clear();
    words.resize(N);
    for(int i=0;i<N;i++)
    {
        string tmp;
        cin >> tmp;
        for(int j=0;j<tmp.size();j++) words[i][tmp[j]]++;
    }

    VI result(K+1,0);
    int pos;
    while(str.size())
    {
        int pos = str.find('+');
        if(pos == -1) 
        {
            equation = str;
            str = "";
        }
        else
        {
            equation = str.substr(0,pos);
            str = str.substr(pos+1);
        }

        memo.clear();
        for(int i=1;i<=K;i++)
        {
            result[i] = (result[i] + permute(i,0)) % MOD;
        }
    }

    for(int i=1;i<=K;i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
