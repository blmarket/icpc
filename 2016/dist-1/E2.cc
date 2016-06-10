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

#include "winning_move.h"

#define ROT32(x, y) ((x << y) | (x >> (32 - y))) // avoid effort
// len should be divible by 4
uint32_t murmur(void *key, uint32_t len, uint32_t seed = 1723621) {
    static const uint32_t c1 = 0xcc9e2d51;
    static const uint32_t c2 = 0x1b873593;
    static const uint32_t r1 = 15;
    static const uint32_t r2 = 13;
    static const uint32_t m = 5;
    static const uint32_t n = 0xe6546b64;

    uint32_t hash = seed;

    const int nblocks = len / 4;
    const uint32_t *blocks = (const uint32_t *) key;
    int i;
    uint32_t k;
    for (i = 0; i < nblocks; i++) {
	k = blocks[i];
	k *= c1;
	k = ROT32(k, r1);
	k *= c2;

	hash ^= k;
	hash = ROT32(hash, r2) * m + n;
    }

    hash ^= len;
    hash ^= (hash >> 16);
    hash *= 0x85ebca6b;
    hash ^= (hash >> 13);
    hash *= 0xc2b2ae35;
    hash ^= (hash >> 16);

    return hash;
}

int main(void) {
    int my = MyNodeId();
    int nn = NumberOfNodes();

    LL N = GetNumPlayers();
    LL left = N * my / nn;
    LL right = N * (my + 1) / nn;

    for(int i=0;i<nn;i++) {
        vector<LL> v;
        v.clear();
        for(LL j=left; j < right;j++) {
            LL tmp = GetSubmission(j);
            uint32_t hash = murmur(&tmp, 8);
            if((hash % nn) != i) continue;
            v.pb(tmp);
        }
        sort(v.begin(), v.end());
        vector<LL> msg;
        for(int j=0;j<size(v);j++) {
            if(j == 0 || v[j] != v[j-1]) {
                if(j+1 >= size(v) || v[j+1] != v[j]) {
                    msg.pb(v[j]);
                } else {
                    msg.pb(v[j]);
                    msg.pb(v[j]);
                }
            }
        }
        cerr << msg.size() << endl;
        PutLL(i, msg.size());
        each(jt, msg) PutLL(i, jt);
        Send(i);
    }

    vector<LL> v;
    for(int i=0;i<nn;i++) {
        Receive(i);
        LL sz = GetLL(i);
        for(int j=0;j<sz;j++) {
            v.pb(GetLL(i));
        }
    }
    sort(v.begin(), v.end());
    for(int j=0;j<size(v);j++) {
        if(j == 0 || v[j] != v[j-1]) {
            if(j+1 >= size(v) || v[j+1] != v[j]) {
                PutLL(0, v[j]);
                Send(0);
                goto end;
            }
        }
    }
    PutLL(0, -1);
    Send(0);
end:

    LL minn = -1;
    for(int i=0;i<nn;i++) {
        Receive(i);
        LL tmp = GetLL(i);
        if(tmp == -1) continue;
        if(minn == -1 || minn > tmp) minn = tmp;
    }

    cout << minn << endl;

    return 0;
}
