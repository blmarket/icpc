#include <iostream>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define MOD 10009

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

map<VI,int> memo,next;

template<typename T> int size(const T &a) { return a.size(); } 

string eq;
int K;
int N;
VVI words;

VVI sum;

void add(VI &v, const VI &c)
{
    for(int i=0;i<v.size();i++) v[i] += c[i];
}

int pow(int a,int b)
{
    if(a==0) return 0;
    if(b==0) return 1;
    return (a * pow(a,b-1)) % MOD;
}

VI result;
VI tgt;

int calc(const VI &inp,int dd)
{
    tgt.clear();
    for(int i=0;i<inp.size();i++)
        if(inp[i]) tgt.pb(i);
    int nn = tgt.size();

    memo.clear();
    memo[VI(nn,0)] = 1;

    for(int i=0;i<dd;i++)
    {
        next.clear();
        for(int j=0;j<words.size();j++)
        {
            VI tmp;
            for(int k=0;k<tgt.size();k++)
                tmp.pb(words[j][tgt[k]]);

            foreach(it,memo)
            {
                VI tmp2 = tmp;
                add(tmp2,it->first);
                next[tmp2] = (next[tmp2] + it->second) % MOD;
            }
        }
        memo.swap(next);
        foreach(it,memo)
        {
            int tmp = it->second;
            for(int j=0;j<tgt.size();j++)
            {
                if(it->first[j] == 0) { tmp = 0; break; }
                tmp = ((long long)tmp * pow((it->first[j]%MOD),inp[tgt[j]])) % MOD;
                if(pow(it->first[j],inp[tgt[j]]) < 0)
                {
                    cout << it->first[j] << " " << inp[tgt[j]] << "error" << endl;
                }
            }
            result[i] = (result[i] + tmp) % MOD;
        }
    }
    return 0;
}

void process(void)
{
    cin >> eq >> K;
    words.clear();
    sum.clear();

    VI cur(26,0);
    for(int i=0;i<eq.size();i++)
    {
        if(eq[i] == '+')
        {
            sum.pb(cur);
            cur = VI(26,0);
        }
        else
        {
            cur[eq[i]-'a']++;
        }
    }
    sum.pb(cur);

    cin >> N;
    words.resize(N,VI(26,0));

    for(int i=0;i<N;i++)
    {
        string str;
        cin >> str;
        for(int j=0;j<str.size();j++)
        {
            words[i][str[j]-'a']++;
        }
    }

    result.resize(K,0);
    for(int i=0;i<sum.size();i++)
    {
        cerr << i << " ";
        calc(sum[i],K);
    }
    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";
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
