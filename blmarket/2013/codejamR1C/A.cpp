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

string str;
int N;

vector<int> spos;

void process(void) {
    cin >> str >> N;
    spos.clear();

    int cnt = 0;
    for(int i=0;i<size(str);i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u') {
            cnt = 0;
        } else {
            cnt++;
            if(cnt >= N) {
                spos.pb(i);
            }
        }
    }

    long long ret = 0;
    for(int i=0;i<size(str);i++) {
        int pos = lower_bound(spos.begin(), spos.end(), i + N - 1) - spos.begin();
        if(pos == size(spos)) break;
        int rc = size(str) - spos[pos];
        ret += rc;
    }
    cout << ret << endl;
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
