#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int p,x,y;

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        scanf(" %d %d %d", &p, &x, &y);

        if(x == 50 && y == 50) {
          if(p == 100) {
            printf("black\n");
            continue;
          } else {
            printf("white\n");
            continue;
          }
        }

        x -= 50;
        y -= 50;

        cout << atan2(x,y) * 180 / M_PI << endl; 
    }
    return 0;
}
