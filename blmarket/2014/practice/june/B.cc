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

int N, M;
int st[105], et[105], sn[105];
tuple<int, int, int> cls[105];
int matrix[105][105];

void process(void) {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> st[i] >> et[i] >> sn[i];
        cls[i] = make_tuple(st[i], et[i], sn[i]);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) cin >> matrix[i][j];
    }
}

int main(void) {
    int T;
    cin >> T;
    for(int i=0;i<T;i++) process();
    return 0;
}
