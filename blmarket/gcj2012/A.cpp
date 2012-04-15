#include <iostream>
#include <algorithm>
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

map<char, char> mapper;

void process(void)
{
    string str, str2;
    getline(cin, str);
    getline(cin, str2);
    for(int i=0;i<size(str);i++)
    {
        mapper[str[i]] = str2[i];
    }
}

void go(void)
{
    string str;
    getline(cin,str);
    for(int i=0;i<size(str);i++)
    {
        str[i] = mapper[str[i]];
    }
    cout << str << endl;
}

int main(void)
{
    int N;
    string tmp;
    cin >> N;
    getline(cin, tmp);
    for(int i=1;i<=N;i++)
    {
        process();
        cerr << i << endl;
    }
    cin >> N;
    getline(cin, tmp);
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        go();
    }
}
