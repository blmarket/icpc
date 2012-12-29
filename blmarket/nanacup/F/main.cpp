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

int n;
int x[1000], y[1000];
int order[1000];

bool have_intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    if (x1 == x2 && y1 == y2) return false; // indeed, not possible.
    if (x3 == x4 && y3 == y4) return false; // indeed, not possible.
    if ((x2-x1)*(y4-y3) == (x4-x3)*(y2-y1)) {
        // singular
        if ((x1-x3)*(y2-y1) != (y1-y3)*(x2-x1)) return false;
        if (x1 != x2) {
            if ((x3-x1)*(x3-x2) <= 0) return true;
            if ((x4-x1)*(x4-x2) <= 0) return true;
            if ((x1-x3)*(x1-x4) <= 0) return true;
            if ((x2-x3)*(x2-x4) <= 0) return true;
        } else {
            if ((y3-y1)*(y3-y2) <= 0) return true;
            if ((y4-y1)*(y4-y2) <= 0) return true;
            if ((y1-y3)*(y1-y4) <= 0) return true;
            if ((y2-y3)*(y2-y4) <= 0) return true;
        }
        return false;
    }
    // have a unique solution.
    int b_up = (y1-y3)*(x2-x1) - (x1-x3)*(y2-y1);
    int b_down = (y4-y3)*(x2-x1) - (x4-x3)*(y2-y1);
    int a_down = (x2-x1)*(y4-y3) - (y2-y1)*(x4-x3);
    int a_up = (y1-y3)*(x4-x3) - (x1-x3)*(y4-y3);
    if ((long long)(b_up-b_down)*b_up <= 0 && (long long)(a_up-a_down)*a_up <= 0) return true;

    return false;
}

bool check(int a, int b, int c,int d) {
    return have_intersection(x[a], y[a], x[b], y[b], x[c], y[c], x[d], y[d]);
}


int main(void)
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i=0;i<n;i++) {
        order[i] = i;
    }

    for(int i=0;i<n-2;i++) {
        for(int j=i+2;j<n;j++) {
            if(i == 0 && j == n-1) break;
            if(check(order[i], order[i+1], order[j], order[j+1])) {
                reverse(order + i + 1, order + j + 1);
            }
        }
    }

    for(int i=0;i<n;i++)
        cout << order[i] << endl;
    cout << endl;
    return 0;
}
