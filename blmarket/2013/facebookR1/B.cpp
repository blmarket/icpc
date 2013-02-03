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

int m,l;
string k1, k2;
string block1[105], block2[105];

void assign(const string &a, string target[]) {
    for(int i=0;i<m;i++) {
        target[i] = a.substr(i*l, l);
        cout << target[i] << " ";
    }
    cout << endl;
}

void process(void) {
    char buff[1024];
    scanf(" %s",buff);
    k1 = buff;
    l = size(k1) / m;
    scanf(" %s", buff);
    k2 = buff;
    assign(k1, block1);
    assign(k2, block2);
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
