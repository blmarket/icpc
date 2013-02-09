#include <iostream>
#include <bitset>
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
typedef bitset<10> bits;

template<typename T> int size(const T &a) { return a.size(); } 

int N;
PII rela[1005];

int go(const bits &st) {
    bits candi(st);
    for(int i=0;i<N;i++) {
        int p1 = rela[i].first;
        int p2 = rela[i].second;
        if(!st.test(p1) || !st.test(p2)) continue;
        candi.reset(p2);
    }

    cout << candi << endl;
    for(int i=0;i<N;i++) {
        if(candi.test(i)) cout << i << " ";
    }
    cout << endl;
    return 0;
}

void process() 
{
    scanf("%d", &N);
    for(int i=0;i+1<N;i++) {
        char flag;
        scanf("%d %c %d", &rela[i].first, &flag, &rela[i].second);
        if(flag == '>') {
            swap(rela[i].first, rela[i].second);
        }
    }

    bits state;
    for(int i=0;i<N;i++) {
        state.set(i);
    }
    cout << state << endl;

    cout << go(state) << endl;
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
