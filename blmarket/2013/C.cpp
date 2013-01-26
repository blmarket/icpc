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

template<typename T> int size(const T &a) { return a.size(); } 

int N,K;
int arr[200005];
int occ[100005];

void process(void) {
    memset(occ, 0, sizeof(occ));
    scanf("%d %d", &N, &K);
    int a,b,c,r;
    scanf("%d %d %d %d",&a,&b,&c,&r);
    arr[0] = a; occ[a]++;
    for(int i=1;i<K;i++) {
        long long tmp = arr[i-1];
        tmp *= b;
        tmp += c;
        tmp %= r;
        arr[i] = tmp; occ[tmp]++;
    }

    int j = 0;
    for(int i=K;i<N;i++) {
        for(;occ[j];j++);
        arr[i] = j; occ[j]++;
        cout << arr[i] << " ";

        if(i == K*2) cout << endl;

        if(--occ[arr[i-K]] == 0) {
            if(j > arr[i-K]) j = arr[i-K];
        }
    }
    cout << endl;

    cout << arr[N-1] << endl;
    N -= K + 1;
    N %= K;
    cout << arr[N + K - 1] << endl;

    return;

    if(N <= K*2) {
        cout << arr[N-1] << endl;
        return;
    }

    N -= K*2;
    cout << arr[(N % K) + K] << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}
