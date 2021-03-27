#include <bits/stdc++.h>

#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int X, Y;
char str[1005];

void process() { 
  scanf(" %d %d %s", &X, &Y, str);
  int L = strlen(str);

  int cC = 0, cJ = 0;
  for(int i=0;i<L;i++) {
    switch(str[i]) {
      case '?':
        cC = min(cC, cJ + Y);
        cJ = min(cJ, cC + X);
        break;
      case 'C':
        cC = min(cC, cJ + Y);
        cJ = 1000000;
        break;
      case 'J':
        cJ = min(cJ, cC + X);
        cC = 1000000;
        break;
    }
  }

  cout << min(cC, cJ) << endl;
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
