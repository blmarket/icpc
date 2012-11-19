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
#define ARRAYSIZE(a) ( sizeof(a) / sizeof((a)[0]) )

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

bool findexact(const string &in, int life) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            visit.clear();
            if(go(in, i, j, 0, life)) {
                return true;
            }
        }
    }
}

/*int try_order[][2] = {
    {22,0},{21,0},{20,0},{19,0},{18,0},{17,0},{16,0},{22,1},{15,0},{21,1},{14,0},{19,1},{13,0},{18,1},{12,0},{17,1},{11,0},{16,1},{10,0},{15,1},{14,1},{9,0},{13,1},{8,0},{12,1},{11,1},{7,0},{10,1},{6,0},{9,1},{5,0},{8,1},{7,1},{4,0},{3,0},{3,1}
};*/
int must_do[][2] = {
    {22,0},{21,0},{20,0},{19,0},{18,0},{17,0},{16,0},{15,0},{14,0},{13,0},{12,0},{11,0},{10,0},{9,0},{8,0},{7,0},{6,0}
};

int shuffle_trials[][2] = {
    {5,0},{4,0},{3,0},{5,1},{4,1},{5,2},{3,1},{4,2}
};

int stupid_trials(int try_order[][2], int sz, vector<pair<string, vector<PII> > > &result) {
    int ret = 0;
    for(int i=0;i<sz;i++) {
        int idx = try_order[i][0];
        vector<string> &v = words[idx];

        vector<int> order(size(v));
        for(int j=0;j<size(v);j++) order[j] = j;
        random_shuffle(order.begin(), order.end());

        for(int j=0;j<size(v);j++) {
            int jj = order[j];
            if(used_words[idx][jj]) continue;
            if(findexact(v[jj], try_order[i][1])) {
                int myscore = sqr(try_order[i][0] - try_order[i][1]) / (1 + try_order[i][1]);
                ret += myscore;
                result.pb(mp(v[jj], visit));
                used_words[idx][jj] = true;
            }
        }
    }
    return ret;
}

void output(vector<pair<string, vector<PII> > > &result) {
    for(int i=0;i<size(result);i++) {
        cout << result[i].first << " ";
        const vector<PII> &tmp = result[i].second;
        for(int j=0;j<size(tmp);j++) {
            cout << tmp[j].second << " " << tmp[j].first << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    input();

    vector<pair<string, vector<PII> > > result;
    cerr << stupid_trials(must_do, ARRAYSIZE(must_do), result) << endl;

    vector<pair<string, vector<PII> > > result2, result3;
    while(getTime() < 4.5) {
        cerr << stupid_trials(shuffle_trials, ARRAYSIZE(shuffle_trials), result3) << endl;
        result2 = result3;
    }

    cout << size(result) + size(result2) << endl;
    output(result);
    output(result2);

    /*
    for(int i=0;i<size(data);i++) {
        for(int j=0;j<size(data[i]);j++) {
            if(get_used(i,j)) cerr << ' '; else cerr << data[i][j];
        }
        cerr << endl;
    }
    */
    cerr << getTime() << endl;
    return 0;
}
