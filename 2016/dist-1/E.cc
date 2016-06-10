#include <iostream>
#include <algorithm>
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

    const uint8_t *tail = (const uint8_t *) (key + nblocks * 4);
    uint32_t k1 = 0;

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
    vector<LL> v;
    for(int i=0;i<N;i++) {
      LL tmp = GetSubmission(i);
      int hash = murmur(&tmp, 8);
      if((hash % nn) == my) {
        v.pb(tmp);
      }
    }

    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++) {
      if(i == 0 || v[i] != v[i-1]) {
        if(i+1 >= N || v[i+1] != v[i]) {
          PutLL(0, v[i]);
          Send(0);
          goto end;
        }
      }
    }
    PutLL(0, 0);
    Send(0);
end:
    if(my == 0) {
      LL ret = 0;
      for(int i=0;i<nn;i++) {
        Receive(i);
        LL tmp = GetLL(i);
        if(tmp == 0) continue;
        if(ret == 0 || ret > tmp) ret = tmp;
      }
      cout << ret << endl;
    }

    return 0;
}
