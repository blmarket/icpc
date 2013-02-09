#include <iostream>
#include <algorithm>
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
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

long long N,K,P;

void process() 
{
    cin >> N >> K >> P;
    if(K >= N) {
        cout << 1 << endl;
        return;
    }

    LL tmp = ((N-1) % K) + 1;
    LL round = (N + K - 1) / K;
    // in here, they always vote so they will not vote for tmp + K turn.
    LL votes = 0;
    LL winround = round;

    if(P == 100) {
        cout << winround << endl;
        return;
    }

    // for(--round;round>0;round--) {
    while(true) {
        LL go = P * tmp - 100 * votes;
        LL go2 = (100 - P) * K;

        go /= go2;
        round -= go;
        tmp += go * K;
        votes += go * K;
        if(round < 1) break;
        // cerr << round << ":" << tmp << ":" << votes << " ";
        if(votes * 100 >= tmp * P) { // will win
            winround = round;
            votes = 0;
            continue;
        } 

        round--;
        tmp += K;
        votes += K;
        if(round < 1) break;
        // cerr << round << ":" << tmp << ":" << votes << " ";
        if(votes * 100 >= tmp * P) { // will win
            winround = round;
            votes = 0;
        } 
    }
    cout << winround << endl;
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        process();
    }
}
