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
    nn = 1;
    if(my != 0) return 0;

    LL ret = 1;
    LL N = NumberOfPeaks();
    LL rmost = N - 1;
    LL lmost = 0;

    LL left = N * my / nn;
    LL right = N * (my+1) / nn;

    // 1 -> t1 is over t2
    // -1 -> t2 is over t1
    // 0 -> same
    auto rot = [&](LL rmost, LL t1, LL t2) {
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
        stack.pb(rmost);

        auto try_push = [&](LL j) {
            while(stack.size() >= 2) {
                int sz = stack.size();
                if(rot(stack[sz-2], stack[sz-1], j) >= 0) break;
                stack.pop_back();
            }
            stack.pb(j);
        };
        for(LL j=right-1; j>=left;j--) {
            try_push(j);
        }
        try_push(lmost);
        return stack;
    };

    for(int i=0;i<nn*5;i++) {
        vector<LL> stack = move(get_stack());

        LL sz = size(stack);
        LL rrmost = stack[sz-2];
        LL llmost = stack[1];

        if(my) {
            PutLL(my-1, rrmost);
            Send(my-1);
        }
        if(my+1 < nn) {
            PutLL(my+1, llmost);
            Send(my+1);
        }

        if(my) {
            Receive(my-1);
            lmost = GetLL(my-1);
        }
        if(my+1 < nn) {
            Receive(my+1);
            rmost = GetLL(my+1);
        }
    }

    vector<LL> stack = get_stack();
    PutLL(0, stack.size() - 2);
    Send(0);

    if(my == 0) {
        LL cnt = 2;
        for(int i=0;i<nn;i++) {
            Receive(i);
            cnt += GetLL(i);
        }
        cout << cnt << endl;
    }
    return 0;
}
