#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <message.h>

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

#include "highest_mountain.h"

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes();

    LL ret = 1;
    LL N = NumberOfPeaks();
    LL rmost = N - 1;
    LL lmost = 0;

    LL left = N * my / nn;
    LL right = N * (my+1) / nn;

    // 1 -> t1 is over t2
    // -1 -> t2 is over t1
    // 0 -> same
    auto rot = [&](LL t1, LL t2) {
        LL v1x = rmost - t1;
        LL v2x = rmost - t2;
        LL v1y = GetHeight(rmost) - GetHeight(t1);
        LL v2y = GetHeight(rmost) - GetHeight(t2);

        // cerr << v1x << " " << v1y << " " << v2x << " " << v2y << endl;

        if(v1x * v2y == v2x * v1y) return 0;
        if(v1x * v2y > v2x * v1y) return 1;
        return -1;
    };

    auto get_stack = [&]() {
        vector<LL> stack;
        for(LL j=right-1; j>=left;j--) {
            if(rot(lmost, j) > 0) continue;
            while(!stack.empty()) {
                LL t1 = stack.back();
                if(rot(t1, j) > 0) break;
                stack.pop_back();
            }
            stack.pb(j);
        }
        return stack;
    };

    for(int i=0;i<nn;i++) {
        cerr << i << endl;
        vector<LL> stack = move(get_stack());

        LL rrmost = rmost;
        if(!stack.empty()) rrmost = stack.back();
        LL llmost = lmost;
        if(!stack.empty()) llmost = stack[0];

        if(i) {
            PutLL(i-1, rrmost);
            Send(i-1);
        }
        if(i+1 < nn) {
            PutLL(i+1, llmost);
            Send(i+1);
        }

        if(i) {
            Receive(i-1);
            lmost = GetLL(i-1);
        }
        if(i+1 < nn) {
            Receive(i+1);
            rmost = GetLL(i+1);
        }
    }

    vector<LL> stack = get_stack();
    PutLL(0, stack.size());
    Send(0);

    if(my == 0) {
        LL cnt = 0;
        for(int i=0;i<nn;i++) {
            Receive(i);
            cnt += GetLL(i);
        }
        cout << cnt << endl;
    }
    return 0;
}
