#include <iostream>
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

char mood[50005];
vector<char> stack;

void process() {
    scanf(" %s", mood);
    int N = strlen(mood);

    int score = 0;
    stack.clear();
    for(int i=0;i<N;i++) {
        int remain = N - i;
        if(stack.size() == 0) {
            stack.pb(mood[i]);
            continue;
        }
        if(stack.back() == mood[i]) {
            stack.pop_back();
            score += 10;
            continue;
        }
        if(stack.size() >= remain) {
            stack.pop_back();
            score += 5;
            continue;
        }
        stack.pb(mood[i]);
    }
    cout << score << endl;
    return;
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
