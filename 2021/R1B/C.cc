#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int T, N, B;

void process() {
  vector<int> pts(B + 1);
  pts[0] = N;
  for(int i=0;i<N*B;i++) {
    int tmp;
    scanf(" %d", &tmp);
    if(tmp >= 9) {
      for(int j=B-1;j>=0;j--) {
        if(pts[j]) {
          printf("%d\n", accumulate(pts.begin(), pts.begin() + j + 1, 0));
          fflush(stdout);
          pts[j+1]++;
          pts[j]--;
          break;
        }
      }
    } else {
      bool found = false;
      if (pts[B-2] && tmp < 7) {
        for(int j=B-3;j>=0;j--) {
          if(pts[j]) {
            printf("%d\n", accumulate(pts.begin(), pts.begin() + j + 1, 0));
            fflush(stdout);
            pts[j+1]++;
            pts[j]--;
            found = true;
            break;
          }
        }
        if(!found && pts[B-2]) {
          printf("%d\n", accumulate(pts.begin(), pts.begin() + B - 1, 0));
          fflush(stdout);
          pts[B-1]++;
          pts[B-2]--;
          found = true;
        }
      } else {
        for(int j=B-2;j>=0;j--) {
          if(pts[j]) {
            printf("%d\n", accumulate(pts.begin(), pts.begin() + j + 1, 0));
            fflush(stdout);
            pts[j+1]++;
            pts[j]--;
            found = true;
            break;
          }
        }
      }
      if(!found) {
        printf("%d\n", accumulate(pts.begin(), pts.begin() + B, 0));
        pts[B]++;
        pts[B-1]--;
        fflush(stdout);
      }
    }
  }
}

int main(void) {
  char tgt[20];
  scanf(" %d %d %d %s", &T, &N, &B, tgt);
  for(int i=0;i<T;i++) {
    process();
  }
}
