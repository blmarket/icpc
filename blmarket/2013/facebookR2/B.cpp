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

    cerr << tmp << ":" << votes << " ";

    for(LL i=tmp+K;i<=N;i+=K) {
        round--;
        votes += K;

        cerr << round << ":" << i << ":" << votes << " ";
        if(votes * 100 >= i * P) { // will win
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
