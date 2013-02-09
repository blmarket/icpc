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
int combi[1005][1005];

void precalc(void) {
    for(int i=0;i<=1000;i++) {
        combi[i][0] = combi[i][i] = 1;
        for(int j=i+1;j<i;j++) {
            combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
            combi[i][j] %= 1000000007;
        }
    }
}

void take2(int pos, bits &ret) {
    ret.set(pos);
    for(int i=0;i<N-1;i++) {
        if(rela[i].first == pos) {
            take2(rela[i].second, ret);
        }
        if(rela[i].second == pos && !ret.test(rela[i].first)) {
            take2(rela[i].first, ret);
        }
    }
}

void take(int pos, bits &ret) {
    ret.set(pos);
    for(int i=0;i<N-1;i++) {
        if(rela[i].first == pos) {
            take2(rela[i].second, ret);
        }
    }
    ret.reset(pos);
}

int go(bits &st) {
    bits candi = st;

    cout << candi << endl;
    int cnt = candi.count();
    if(cnt == 0) return 1;

    for(int i=0;i<N-1;i++) {
        int p1 = rela[i].first;
        int p2 = rela[i].second;
        if(!st.test(p1) || !st.test(p2)) continue;
        candi.reset(p2);
    }

    cout << candi << endl;
    for(int i=0;i<N;i++) {
        if(candi.test(i)) {
            long long ret = 1;
            for(int j=0;j<N-1;j++) {
                if(rela[j].first == i) {
                    bits tmp;
                    take(rela[j].second, tmp);

                    ret *= go(tmp);
                    ret %= 1000000007;
                }
            }
            return ret;
        }
    }
    return 1;
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

    bits candi;
    for(int i=0;i<N;i++) candi.set(i);
    int ret = go(candi);
}

int main(void)
{
    precalc();
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        process();
    }
}
