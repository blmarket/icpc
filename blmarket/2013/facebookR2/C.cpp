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
typedef bitset<55> bits;

template<typename T> int size(const T &a) { return a.size(); } 

int N;
PII rela[1005];
int combi[1005][1005];

void precalc(void) {
    for(int i=0;i<=1000;i++) {
        combi[i][0] = combi[i][i] = 1;
        for(int j=1;j<i;j++) {
            combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
            combi[i][j] %= 1000000007;
        }
    }
}

void take2(int pos, bits &ret) {
    ret.set(pos);
    for(int i=0;i<N-1;i++) {
        if(rela[i].first == pos && !ret.test(rela[i].second)) {
            take2(rela[i].second, ret);
        }
        if(rela[i].second == pos && !ret.test(rela[i].first)) {
            take2(rela[i].first, ret);
        }
    }
}

void take(int pos, int no, bits &ret) {
    ret.set(pos);
    for(int i=0;i<N-1;i++) {
        if(rela[i].first == pos && rela[i].second != no) {
            take2(rela[i].second, ret);
        }
        if(rela[i].second == pos && rela[i].first != no) {
            take2(rela[i].first, ret);
        }
    }
    ret.reset(pos);
}

struct ci_less : binary_function<bits, bits, bool>
{
    bool operator() (const bits & s1, const bits & s2) const
    {
        for(int i=0;i<N;i++)
        {
            if(s1[i] != s2[i])
                return s1[i] < s2[i];
        }
        return false;
    }
};

map<bits, int, ci_less> memo;

int go(bits &st) {
    if(memo.count(st)) {
        return memo[st];
    }
    bits candi = st;

    int cnt = candi.count();
    if(cnt == 0) return 1;

    for(int i=0;i<N-1;i++) {
        int p1 = rela[i].first;
        int p2 = rela[i].second;
        if(!st.test(p1) || !st.test(p2)) continue;
        candi.reset(p2);
    }

    long long rett = 0;
    for(int i=0;i<N;i++) {
        if(candi.test(i)) {
            long long ret = 1;
            int cnt2 = cnt-1;
            for(int j=0;j<N-1;j++) {
                if(rela[j].first == i) {
                    bits tmp;
                    take(rela[j].second, i, tmp);
                    tmp.set(rela[j].second);
                    for(int k=0;k<N;k++) {
                        if(tmp.test(k) && !st.test(k))
                            tmp.reset(k);
                    }

                    int tmp2 = tmp.count();

                    ret *= combi[cnt2][tmp2];
                    cnt2 -= tmp2;
                    ret %= 1000000007;

                    ret *= go(tmp);
                    ret %= 1000000007;
                }
            }
            rett += ret;
            rett %= 1000000007;
        }
    }
    memo[st] = rett;
}

void process() 
{
    memo.clear();
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
    cout << ret << endl;
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
