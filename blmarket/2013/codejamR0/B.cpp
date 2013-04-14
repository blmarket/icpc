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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

template<typename T> string toString(const T &a) { ostringstream ost; ost << a; return ost.str(); } 
bool chkpalin(const string &a) { 
    for(int i=0;i*2<size(a);i++) {
        if(a[i] != a[size(a)-1-i]) return false;
    }
    return true;
}

bool comp(const string &a, const string &b) {
    int sz1 = size(a), sz2 = size(b);
    if(sz1 != sz2) return sz1 < sz2;
    for(int i=0;i<sz1;i++) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

int ret;
string A,B;
vector<string> bigV;
void candidate(string candi) {
    string tmp(size(candi)*2-1, '0');
    for(int i=0;i<size(candi);i++) candi[i] -= '0';
    for(int i=0;i<size(candi);i++) {
        for(int j=0;j<size(candi);j++) {
            tmp[i+j] += candi[i] * candi[j];
        }
    }
    cout << tmp << endl;
    bigV.pb(tmp);
}

bool chkgood(const string &a) {
    bool ret = false;
    int sum = 0, mid = 0;
    for(int i=0;i<size(a);i++) {
        sum += sqr(a[i]-'0') * 2;
    }
    mid = sqr(a[size(a)-1] - '0');

    string tmp = a;
    reverse(tmp.begin(), tmp.end());
    if(sum < 10) {
        ret = true;
        candidate(a + tmp);
    }
    sum -= mid;
    if(sum < 10) {
        ret = true;
        candidate(a + tmp.substr(1));
    }
    return ret;
}

void go(string &tmp) {
    if(size(tmp) > 5) return;
    cout << tmp << endl;
    for(int i=0;i<2;i++) {
        tmp += (char)(i + '0');
        if(chkgood(tmp)) {
            go(tmp);
        }
        tmp.resize(size(tmp) - 1);
    }
}

void process(void) {
    char a[200], b[200];
    scanf(" %s %s", a, b);
    A = a; B = b; 
    
    int ret = upper_bound(bigV.begin(), bigV.end(), B, comp) - lower_bound(bigV.begin(), bigV.end(), A, comp);

    printf("%d\n", ret);
}

void precalc() {
    chkgood("1"); chkgood("2"); chkgood("3");
    string tmp = "1";
    go(tmp); 
    tmp = "2";
    go(tmp);
    sort(bigV.begin(), bigV.end(), comp);
    bigV.resize(20);
    for(auto item : bigV) cout << item << endl;
}

void precalc2() {
    for(LL i=1;i<100000;i++) {
        string s1 = toString(i);
        if(chkpalin(s1) == false) continue;
        string s2 = toString(i*i);
        if(chkpalin(s2) == false) continue;
        cout << s1 << " " << s2 << endl;
    }
}

int main(void)
{
    precalc();
    precalc2();
    return 0;
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}
