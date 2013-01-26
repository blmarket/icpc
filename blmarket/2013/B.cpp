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

bool flag[105][105];

bool type1(char a) {
    if(a >= 'a' && a<= 'z') return true;
    if(a == ' ' || a == ':') return true;
    return false;
}

void process(void) {
    memset(flag, 0, sizeof(flag));
    string str;
    getline(cin, str);

    for(int j=0;j<size(str);j++) {
        flag[j][j] = true;
        flag[j][j+1] = type1(str[j]);
    }

    for(int i=2;i<=size(str);i++) {
        for(int j=0;j+i<=size(str);j++) {
            int right = j+i-1;
            if(str[j] == '(' && str[right] == ')') {
                flag[j][j+i] = flag[j+1][j+i-1];
            }
            for(int k=j+1;k<=right;k++) {
                if(flag[j][j+i]) break;
                if(flag[j][k] && flag[k][j+i]) {
                    flag[j][j+i] = true;
                    break;
                }
            }
        }
    }

    cout << (flag[0][size(str)] ? "YES" : "NO") << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    string str;
    getline(cin, str);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}
