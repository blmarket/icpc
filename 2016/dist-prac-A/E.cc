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

#include "majority.h"

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes() - 1;

    LL N = GetN();
    if(my == nn) {
        auto count = [&](LL v) {
            for(int i=0;i<nn;i++) {
                PutLL(i, v);
                Send(i);
            }
            LL ret = 0;
            for(int i=0;i<nn;i++) {
                Receive(i);
                ret += GetLL(i);
            }
            return ret;
        };

        unordered_set<LL> cs;
        for(int i=0;i<nn;i++) {
            Receive(i);
            cs.insert(GetLL(i));
        }

        each(it, cs) {
            if (count(it) > N / 2) {
                cout << it << endl;
                goto end;
            }
        }
        cout << "NO WINNER" << endl;
end:
        for(int i=0;i<nn;i++) {
            PutLL(i, -1);
            Send(i);
        }
        return 0;
    }

    LL ls = N * my / nn;
    LL rs = N * (my+1) / nn;

    unordered_map<LL, LL> cnts;
    for(LL i=ls;i<rs;i++) {
        cnts[GetVote(i)] += 1;
    }

    LL msize = 0, mp;
    each(it, cnts) {
        if(msize < it.second) {
            msize = it.second;
            mp = it.first;
        }
    }

    cerr << msize << " " << mp << endl;

    PutLL(nn, mp);
    Send(nn);

    while(true) {
        Receive(nn);
        LL tmp = GetLL(nn);
        if(tmp == -1) break;
        PutLL(nn, cnts[tmp]);
        Send(nn);
    }
    return 0;
}
