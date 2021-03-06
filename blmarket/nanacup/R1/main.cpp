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
    {22,0},{21,0},{20,0},{19,0},{18,0},{17,0},{16,0},
    {15,0},{14,0},{13,0},{12,0},{11,0},{10,0},{9,0},{8,0},
};

int first_step[][2] = {
    {7,0},{6,0}
};

int second_step[][2] = {
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
            if(getTime() > time_limit) return ret;
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
    srand(time(NULL));
    input();

    vector<pair<string, vector<PII> > > result;
    int base_score = stupid_trials(must_do, ARRAYSIZE(must_do), result);
    cerr << getTime() << endl;
    vector<long long> save_used = used;

    int maxtrials = 5;
    if(n*m > 1000) maxtrials = 5;
    int ntrials = 0;

    int maxscore = 0;
    vector<pair<string, vector<PII> > > max_result, current, max_result2, current2;
    while(getTime() < time_limit) {
        current.clear();
        int tmpscore1 = stupid_trials(first_step, ARRAYSIZE(first_step), current);

        vector<long long> save_used2 = used;
        int maxscore2 = 0;
        double curTime = getTime();

        for(int i=0;i<maxtrials;i++) {
            if(getTime() > time_limit) break;
            current2.clear();
            int tmpscore2 = stupid_trials(second_step, ARRAYSIZE(second_step), current2);
            cerr << i << " " << getTime() << " " << tmpscore2 << "/" << maxscore2 << " " << maxscore << endl;
            ntrials++;
            if(maxscore2 < tmpscore2) {
                max_result2 = current2;
                maxscore2 = tmpscore2;
            }
            used = save_used2;
            for(int i=3;i<=5;i++) {
                used_words[i] = vector<bool>(size(words[i]), false);
            }
        }

        int tmpscore = maxscore2 + tmpscore1;
        if(maxscore < tmpscore) {
            max_result = current;
            for(int i=0;i<size(max_result2);i++) {
                max_result.pb(max_result2[i]);
            }
            maxscore = tmpscore;
        }
        used = save_used;
        for(int i=6;i<=7;i++) {
            used_words[i] = vector<bool>(size(words[i]), false);
        }
    }

    cout << size(result) + size(max_result) << endl;
    output(result);
    output(max_result);

    cerr << base_score + maxscore << endl;
    cerr << getTime() << " " << ntrials << endl;
    return 0;
}
