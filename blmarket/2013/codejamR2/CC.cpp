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

int N;
int A[2004], B[2004];
int flow[2004][2004];
int ret[2004];

void process(void) {
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];

    memset(flow, 0, sizeof(flow));
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        if(A[i] >= A[j]) {
            flow[j][i] = 1;
        } 
        if(B[j] >= B[i]) {
            flow[i][j] = 1;
        } 
    }

    for(int i=N-1;i>=0;i--) for(int j=i-1;j>=0;j--) {
        if(A[i] == A[j] + 1) {
            flow[j][i] = 1;
            break;
        }
    }

    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        if(B[i] == B[j] + 1) {
            flow[j][i] = 1;
            break;
        }
    }

    bool used[2004] = {0};
    memset(ret, 0, sizeof(ret));
    for(int pp=1;pp<=N;pp++) {
        /*
        int candi = 0;
        for(int i=0;i<N;i++) if(used[i] == false) {
            bool fail = false;
            for(int j=0;j<N;j++) if(used[j] == false && flow[j][i]) {
                fail = true; break;
            }
            if(!fail) {
                cout << i << " ";
            }
        }
        cout << endl;
        */

        for(int i=0;i<N;i++) if(used[i] == false) {
            bool fail = false;
            for(int j=0;j<N;j++) if(used[j] == false && flow[j][i]) {
                fail = true; break;
            }
            if(!fail) {
                used[i] = true;
                ret[i] = pp;
                break;
            }
        }
    }

    for(int i=0;i<N;i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
