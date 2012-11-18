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
bool bySize(const string &lhs, const string &rhs) { return lhs.size() < rhs.size(); }
const int dx[] = { -1, 0, 0, 1 }, dy[] = { 0, -1, 1, 0 };

int n,m;
vector<string> data;
vector<string> words;

bool check(int x, int y) { return (x>=0 && y>=0 && x<n && y<m); }

void input() 
{
    scanf(" %d %d", &n, &m);
    for(int i=0;i<n;i++) {
        char buffer[1024];
        scanf(" %s", buffer);
        data.pb(buffer);
    }
    int tmp;
    scanf("%d", &tmp);
    for(int i=0;i<tmp;i++) {
        char buffer[512];
        scanf(" %s", buffer);
        words.pb(buffer);
    }
}

bool go(const string &in, int x, int y, int pos) {
    if(!check(x,y)) return false;
    if(data[x][y] != in[pos]) return false;

    // cout << in << " " << x << " " << y << " " << pos << endl;
    
    for(int i=0;i<4;i++) {
        if(go(in, x + dx[i], y + dy[i], pos + 1)) return true;
    }
    return false;
}

bool findexact(const string &in) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(go(in, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    input();
    sort(words.rbegin(), words.rend(), bySize);
    for(int i=0;i<size(words);i++) {
        if(findexact(words[i])) {
            cout << words[i] << endl;
        }
    }
    return 0;
}
