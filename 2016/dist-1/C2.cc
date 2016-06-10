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

#include "rps.h"

vector<pair<LL, int> > stack;

bool comp(LL a, LL b) {
    char m1 = GetFavoriteMove(a);
    char m2 = GetFavoriteMove(b);
    if(m1 == m2) return true;
    if(m1 == 'R') return m2 == 'S';
    if(m1 == 'P') return m2 == 'R';
    if(m1 == 'S') return m2 == 'P';
    return false;
}

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes();

    if (nn >= 100) {
        nn = 64;
    } else if(nn >= 10) {
        nn = 8;
    }

    LL N = 1LL << GetN();
    if(N < nn) nn = N;

    if(my >= nn) return 0;

    LL left = N * my / nn;
    LL right = N * (my+1) / nn;

    for(LL i=left;i<right;i++) {
        stack.pb(mp(i, 0));
        int ss = stack.size();
        while(ss > 1 && stack[ss-2].second == stack[ss-2].second) {
            auto t1 = stack.back(); stack.pop_back();
            auto t2 = stack.back(); stack.pop_back();

            if(comp(t1.first, t2.first)) {
                stack.pb(mp(t1.first, t1.second + 1));
            } else {
                stack.pb(mp(t2.first, t2.second + 1));
            }

            ss = stack.size();
        }
    }

    PutLL(0, stack[0].first);
    Send(0);

    if(my == 0) {
        stack.clear();
        for(int i=0;i<nn;i++) {
            Receive(i);
            stack.pb(mp(GetLL(i), 0));
            int ss = stack.size();
            while(ss > 1 && stack[ss-2].second == stack[ss-2].second) {
                auto t1 = stack.back(); stack.pop_back();
                auto t2 = stack.back(); stack.pop_back();

                if(comp(t1.first, t2.first)) {
                    stack.pb(mp(t1.first, t1.second + 1));
                } else {
                    stack.pb(mp(t2.first, t2.second + 1));
                }

                ss = stack.size();
            }
        }
        cout << stack[0].first << endl;
    }

    return 0;
}
