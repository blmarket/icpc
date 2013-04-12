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

char board[10][10];

char acc(char a, char b) {
    if(a == 0) return b;
    if(b == 'T') return a;
    if(a != b) return '.';
}

char process(void) {
    for(int i=0;i<4;i++) {
        scanf(" %s", board[i]);
        cout << board[i] << endl;
    }


    bool hasdot = false;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(board[i][j] == '.') hasdot = true;
    for(int i=0;i<4;i++) {
        char t1 = board[i][0];
        char t2 = board[0][i];
        cout << "T1 : " << t1 << endl;
        for(int j=1;j<4;j++) {
            t1 = acc(t1, board[i][j]);
            t2 = acc(t2, board[j][i]);
        }
        cout << endl;
        cout << i << " : " << t1 << " " << t2 << endl;
        if(t1 != '.') return t1;
        if(t2 != '.') return t2;
    }
    char t1 = board[0][0];
    char t2 = board[3][0];
    for(int i=1;i<4;i++) {
        t1 = acc(t1, board[i][i]);
        t2 = acc(t2, board[4-i][i]);
    }
    if(t1 != '.') return t1;
    if(t2 != '.') return t2;

    if(hasdot) return -1;
    return 0;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        char tt = process();
        if(tt == -1) {
            printf("Draw\n");
            continue;
        }
        if(tt == 0) {
            printf("Game has not completed\n");
            continue;
        }
        if(tt != 0) {
            printf("%c won\n", tt);
        }
    }
}
