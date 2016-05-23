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
    int nn = NumberOfNodes();

    LL N = GetN();
    LL ls = N * my / nn;
    LL rs = N * (my+1) / nn;

    LL candi = 0, vote = 0;
    for(LL i=ls;i<rs;i++) {
        LL tmp = GetVote(i);
        if(vote == 0) {
            candi = tmp;
            vote = 1;
            continue;
        }
        if(candi == tmp) {
            vote++;
            continue;
        }
        vote--;
    }

    PutLL(0, candi);
    PutLL(0, vote);
    Send(0);

    if(my == 0) {
        candi = vote = 0;
        for(int i=0;i<nn;i++) {
            Receive(i);
            LL t1 = GetLL(i);
            LL t2 = GetLL(i);

            if(candi == t1) {
                vote += t2;
                continue;
            }
            vote -= t2;
            if(t2 < 0) {
                candi = t1;
                vote = -t2;
            }
        }

        for(int i=0;i<nn;i++) {
            PutLL(i, candi);
            Send(i);
        }
    }

    Receive(0);
    candi = GetLL(0);
    LL cnt = 0;

    for(LL i=ls;i<rs;i++) {
        cnt += (GetVote(i) == candi);
    }

    cerr << cnt << endl;

    PutLL(0, cnt);
    Send(0);

    if(my == 0) {
        LL sum = 0;
        for(int i=0;i<nn;i++) {
            sum += GetLL(i);
        }
        if(sum*2 > N) {
            cout << candi << endl;
        } else {
            cout << "NO WINNER" << endl;
        }
    }
    return 0;
}
