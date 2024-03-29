#include <iostream>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> PII;

const int mod = 1000000007;

int depth[300005];
vector<int> childs[300005];

int pos = 0;
PII ranges[300005];

int seg1[1024800];
int seg2[1024800];

PII go(int a) {
    int mypos = pos++;
    for(int i=0;i<childs[a].size();i++) {
        go(childs[a][i]);
    }
    return ranges[a] = mp(mypos, pos);
}

void addseg(int *arr, int val, int s, int e) {
    function<void(int, int, int)> func;

    func = [&](int pos, int a, int b) {
        if(a >= e || b <= s) return;
        if(a >= s && b <= e) {
            // cout << "adding " << pos << " " << val << endl;
            arr[pos] += val;
            if(arr[pos] > mod) arr[pos] -= mod;
            return;
        }
        func(pos*2, a, (a+b)/2);
        func(pos*2+1, (a+b)/2, b);
    };
    func(1, 0, 524288);
};

int main(void) {
    int n;
    scanf("%d", &n);
    depth[1] = 0;
    for(int i=2;i<=n;i++) {
        int tmp;
        scanf("%d", &tmp);
        depth[i] = depth[tmp] + 1;
        childs[tmp].pb(i);
    }

    go(1);

    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int a,b,c;
            scanf("%d %d %d", &a, &b, &c);
            addseg(seg1, ((long long)c * depth[a] + b) % mod, ranges[a].first, ranges[a].second);
            addseg(seg2, c, ranges[a].first, ranges[a].second);
        } else {
            int a;
            scanf("%d", &a);
            int pos = 524288 + ranges[a].first;
            long long sum = 0;

            do {
                // cout << pos << " " << seg1[pos] << " " << seg2[pos] << endl;
                sum += seg1[pos];
                sum -= (long long)seg2[pos] * depth[a];
                sum %= mod;
                pos /= 2;
            } while(pos > 1);
            if(sum < 0) sum += mod;
            cout << sum << endl;
        }
    }
    return 0;
}
