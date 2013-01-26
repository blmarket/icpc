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
int arr[100005];

void process(void) {
    scanf("%d %d", &N, &K);
    int a,b,c,r;
    scanf("%d %d %d %d",&a,&b,&c,&r);
    arr[0] = a;
    for(int i=1;i<K;i++) {
        long long tmp = arr[i-1];
        tmp *= b;
        tmp += c;
        tmp %= r;
        arr[i] = tmp;
    }
    sort(arr, arr+K);
    for(int i=0;i<K;i++) {
        cout << arr[i] << " ";
    }
    cout << 0 << endl;
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
