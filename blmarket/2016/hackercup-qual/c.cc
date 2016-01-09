#include <iostream>
#include <sys/wait.h>
#include <cstdlib>
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

int N;
long long P;
long long data[100005];

void process(void) {
    cin >> N >> P;
    for(int i=0;i<N;i++) cin >> data[i];

    long long ret = 0;

    int j = 0;
    long long ssum = 0;
    for(int i=0;i<N;i++) {
        if(j < i) {
            j = i;
            ssum = 0;
        }
        while(j < N && ssum + data[j] <= P) {
            ssum += data[j];
            j++;
        }

        cerr << j-i << " ";

        ret += (long long)(j-i) * (j-i+1) / 2;
        
        ssum -= data[i];
    }
    cout << ret << endl;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
