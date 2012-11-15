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
ostream &operator<<(ostream &ost, const PII &rhs) {
    return ost << rhs.first << "," << rhs.second;
}

vector<PII> V;

bool comp(const PII &lhs, const PII &rhs) {
    return lhs.second < rhs.second;
}

bool check(int right, int rightmost, int a) {
    cout << right << " " << rightmost << endl;
    for(int i=0;i<size(V);i++) {
        if(V[i].first <= a) continue;
        cout << V[i] << endl;
    }
}

void go(int xdiff) {
    int s = 0;
    int e = xdiff + 1;
    check(xdiff * 2, V.back().second, 6);
    return;
    while(e-s > 1) {
        int m = (s+e) / 2;
        if(check(xdiff*2, V.back().second, m)) {
            s = m;
        } else {
            e = m;
        }
    }
    cout << s << endl;
}

void process(void)
{
    int n;
    scanf("%d", &n);
    V.resize(n);
    int xmin = 1000005, xmax = -1000005, ymin = 1000005, ymax = -1000005;
    for(int i=0;i<n;i++) {
        scanf("%d %d",&V[i].first, &V[i].second);
        xmin = min(xmin, V[i].first);
        xmax = max(xmax, V[i].first);
        ymin = min(ymin, V[i].second);
        ymax = max(ymax, V[i].second);
    }

    for(int i=0;i<n;i++) {
        V[i].first -= xmin;
        V[i].first *= 2;
        V[i].second -= ymin;
        V[i].second *= 2;
    }

    int xdiff = xmax - xmin;
    int ydiff = ymax - ymin;

    if(xdiff < ydiff) {
        for(int i=0;i<n;i++) {
            swap(V[i].first, V[i].second);
        }
        xdiff = ydiff;
    }
    
    cout << xdiff << endl;
    for(int i=0;i<n;i++) {
        if(V[i].first > xdiff) V[i].first = (xdiff * 2) - V[i].first;
    }

    sort(V.begin(), V.end(), comp);

    go(xdiff);
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process();
        break;
    }
}
