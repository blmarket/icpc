#include <iostream>
#include <cstdlib>
#include <sys/time.h>
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

double initGetTime()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec * 0.000001;
}

double time_limit = 4.94;
double time_start = initGetTime();

double getTime()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return (tv.tv_sec + tv.tv_usec * 0.000001 - time_start);
}

int n,m;
vector<string> data;
vector<long long> used;
vector<string> words[25];
vector<bool> used_words[25];

bool check(int x, int y) { return (x>=0 && y>=0 && x<n && y<m); }
bool get_used(int x, int y) { return used[x] & (1LL << y); }
bool set_used(int x, int y) { used[x] |= (1LL << y); }
bool reset_used(int x, int y) { used[x] &= ~(1LL << y); }

void input() 
{
    scanf(" %d %d", &n, &m);
    used.resize(n);
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
        int len = strlen(buffer);
        words[len].pb(buffer);
    }
    
    for(int i=0;i<25;i++) used_words[i] = vector<bool>(words[i].size(), false);
}

vector<PII> visit;
bool go(const string &in, int x, int y, int pos, int life) {
    if(!check(x,y)) return false;
    if(get_used(x,y)) return false;
    if(data[x][y] != in[pos]) {
        if(!life) return false;
        life--;
    }
    set_used(x,y);
    visit.pb(mp(x,y));

    if(pos+1 == size(in)) return true;

    for(int i=0;i<4;i++) {
        if(go(in, x + dx[i], y + dy[i], pos + 1, life)) return true;
    }
    visit.pop_back();
    reset_used(x,y);
    return false;
}

vector<pair<string, vector<PII> > > result;
bool findexact(const string &in) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            visit.clear();
            if(go(in, i, j, 0, 0)) {
                return true;
            }
        }
    }
}

int main(void)
{
    input();

    for(int i=24;i>=1;i--) {
        vector<string> &v = words[i];
        if(size(v) == 0) continue;
        vector<int> idx(size(v));
        for(int j=0;j<size(v);j++) {
            idx[j] = j;
        }

        vector<pair<int, vector<PII> > > best, cur;
        best.clear();
        for(int j=0;j<10;j++) {
            random_shuffle(idx.begin(), idx.end());
            for(int j=0;j<size(v);j++) {
                if(findexact(v[idx[j]])) {
                    cur.pb(mp(idx[j], visit));
                }
            }

            if(size(best) < size(cur)) {
                best = cur;
            }
            if(size(cur) == 0) break;
        }

        for(int j=0;j<size(best);j++) {
            int index = best[j].first;
            vector<PII> &path = best[j].second;
            result.pb(mp(v[index], path));
            used_words[i][index] = true;
        }
    }

    cout << size(result) << endl;
    for(int i=0;i<size(result);i++) {
        cout << result[i].first << " ";
        const vector<PII> &tmp = result[i].second;
        for(int j=0;j<size(tmp);j++) {
            cout << tmp[j].second << " " << tmp[j].first << " ";
        }
        cout << endl;
    }

    for(int i=0;i<size(data);i++) {
        for(int j=0;j<size(data[i]);j++) {
            if(get_used(i,j)) cerr << ' '; else cerr << data[i][j];
        }
        cerr << endl;
    }
    return 0;
}
