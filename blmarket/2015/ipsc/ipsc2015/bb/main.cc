#include <iostream>
#include <vector>
#include <map>

#define mp make_pair
#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

vector<pair<string, int> > W[3];
map<int, vector<string> > memo;

void read_input(int a) {
    auto &ww = W[a];

    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        char a[32];
        int b;
        scanf(" %s %d", a, &b);
        ww.pb(mp(a,b));
    }
}

int find(const vector<pair<string, int> > &V, const string &a) {
    for(int i=0;i<size(V);i++) {
        if(V[i].first == a) return V[i].second;
    }
    return -1;
}



int main(void) {
    for(int i=0;i<3;i++) read_input(i);

    for(auto &it : W[0]) {
        for(auto &jt : W[1]) { 
            memo[it.second + jt.second].pb(it.first + " " + jt.first);
        }
    }

    vector<int> scores;

    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        char a[32];
        char b[32];
        char c[32];

        scanf(" %s %s %s", a,b,c);
        int score = find(W[0], a)+ find(W[1], b)+ find(W[2], c);
        scores.pb(score);
    }
}
