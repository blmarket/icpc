#include <iostream>
#include <list>
#include <cstdlib>
#include <cstring>
#include <cstdio>
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

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int n,m;
vector<int> D;

string move[10005];

string mincut;

bool comp(const string &a, const string &b)
{
    if(size(a) != size(b)) return size(a) < size(b);
    return a<b;
}

string go(string cur, int mod)
{
    //cout << "go " << cur << " " << mod << endl;
    if(mod == 0)
    {
        if(cur >= mincut) return cur;
    }
    string &asdf = move[mod];
    if(asdf == "") return "";
    string tmp = cur + asdf;
    if(comp(tmp, mincut) == false) return tmp;

    string ret = "";
    for(int i=0;i<size(D);i++)
    {
        string tt = go(cur + (char)('0'+D[i]), (mod*10 + D[i]) % n);
        if(tt == "") continue;
        if(ret == "" || comp(tt, ret)) ret = tt;
    }
    return ret;
}

void process(int dataId)
{
    string str;
    cin >> str >> n >> m;
    D.clear();
    for(int i=0;i<size(str);i++) D.pb(str[i]-'0');
    for(int i=0;i<10005;i++) move[i].clear();

    queue<int> Q;
    Q.push(m);
    while(!Q.empty())
    {
        int pos = Q.front();
        Q.pop();

        for(int i=0;i<size(D);i++)
        {
            int tmp = pos - D[i];
            if(tmp < 0) tmp += n;

            for(int j=0;j<20;j++,tmp+=n)
            {
                if((tmp % 10) != 0) continue;
                int tmp3 = (tmp/10)%n;
                string tmp2(1,'0'+D[i]);
                tmp2 += move[pos];
                if(move[tmp3] == "" || comp(tmp2, move[tmp3]))
                {
                    move[tmp3] = tmp2;
                    Q.push(tmp3);
                    //cout << tmp3 << " = " << tmp2 << endl;
                }
            }
        }
    }
    
    int sum = m + n;
    ostringstream ost;
    ost << sum;
    mincut = ost.str();

    string ret = "";
    for(int i=0;i<size(D);i++) if(D[i])
    {
        string tmp = go(string(1, '0'+D[i]),D[i] % n);
        if(tmp == "") continue;
        if(ret == "" || comp(tmp, ret)) ret = tmp;
    }

    if(ret == "") ret = "IMPOSSIBLE";
    cout << ret << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
