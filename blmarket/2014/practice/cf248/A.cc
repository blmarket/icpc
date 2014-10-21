#include <iostream>
#include <algorithm>
#include <functional>
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
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int main(void) {
    int N;
    int sum = 0;
    scanf("%d", &N);
    bool alltwo = true;
    for(int i=0;i<N;i++) {
        int tmp;
        scanf(" %d", &tmp);
        if(tmp == 100) alltwo = false;
        sum += tmp;
    }
    sum /= 100;
    if(N == 1 || (sum%2) == 1 || ((N%2)==1 && alltwo == true)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
