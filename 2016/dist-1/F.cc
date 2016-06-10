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
    LL N;
    if (my == 0) {
        N = NumberOfPeaks();
    }

    while(N > 0) {
        for(int i=0;i<nn;i++) {
            PutLL(i, N);
            Send(i);
        }
        Receive(0);
        N = GetLL(0) - 1;
        LL left = N * my / nn;
        LL right = N * (my + 1) / nn;

        LL msp, mep;
        LL cnt = 0;

        msp = mep = left;
        cnt = 1;

        auto rot = [&](LL t1, LL t2) {
            LL v1x = N - t1;
            LL v2x = N - t2;
            LL v1y = GetHeight(t1) - GetHeight(N);
            LL v2y = GetHeight(t2) - GetHeight(N);

            if(v1x * v2y == v2x * v1y) return 0;
            if(v1x * v2y > v2x * v1y) return 1;
            return -1;
        };

        for(LL i=left + 1; i<right;i++) {
            int tmp = rot(i, mep);
            if(tmp == 0) {
                mep = i;
                cnt++;
            } else if(tmp > 0) {
                msp = mep = i;
                cnt = 1;
            }
        }

        PutLL(0, msp);
        PutLL(0, cnt);
        Send(0);

        if(my == 0) {
            LL t1 = 0;
            LL cnt = 1;
            for(int i=0;i<nn;i++) {
                Receive(i);
                LL t2 = GetLL(i);
                LL c2 = GetLL(i);

                int tmp = rot(t1, t2);
                if(tmp >= 0) {
                    t1 = t2;
                    cnt = c2;
                }
            }
            ret += cnt;
            N = t1;
        }
    }

    return 0;
}
