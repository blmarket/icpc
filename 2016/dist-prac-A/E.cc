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

        for(int i=0;i<10;i++) {
            LL pos = rand() % N;
            LL candi = GetVote(pos);
            if (count(candi) > N / 2) {
                cout << candi << endl;
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

    while(true) {
        Receive(nn);
        LL tmp = GetLL(nn);
        if(tmp == -1) break;

        LL ret = 0;
        for(LL i=ls;i<rs;i++) if (GetVote(i) == tmp) ret++;

        PutLL(nn, ret);
        Send(nn);
    }
    return 0;
}
