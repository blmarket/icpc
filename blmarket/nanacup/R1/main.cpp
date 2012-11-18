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

vector<PII> visit;
bool go(const string &in, int x, int y, int pos, int life) {
    if(!check(x,y)) return false;
    if(data[x][y] != in[pos]) {
        if(!life) return false;
        life--;
    }
    PII key = mp(x,y);
    for(int i=0;i<size(visit);i++) if(visit[i] == key) return false;
    visit.pb(key);

    if(pos+1 == size(in)) return true;
    
    for(int i=0;i<4;i++) {
        if(go(in, x + dx[i], y + dy[i], pos + 1, life)) return true;
    }
    visit.pop_back();
    return false;
}

bool findexact(const string &in) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            visit.clear();
            if(go(in, i, j, 0, 0)) {
                cout << in << " ";
                for(int k=0;k<size(visit);k++) cout << visit[k].second << "," << visit[k].first << " ";
                cout << endl;
            }
        }
    }
}

int main(void)
{
    input();
    sort(words.rbegin(), words.rend(), bySize);

    for(int i=0;i<size(words);i++) {
        findexact(words[i]);
    }
    return 0;
}
