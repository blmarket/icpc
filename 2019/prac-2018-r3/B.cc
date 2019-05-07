#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <random>

#define mp make_pair
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

typedef array<array<LL, 55>, 55> Mat;

int N = 50;
mt19937 rnd(time(0));

Mat matmul(const Mat &a, const Mat &b) {
  Mat res{};
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      for(int k=0;k<N;k++) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}

void debug(const Mat &mat) {
  for(int i=0;i<N;i++) {
    int cnt = 0;
    for(int j=0;j<N;j++) {
      cerr << mat[i][j] << " ";
      cnt += mat[i][j];
    }
    cerr << " = " << cnt << endl;
  }
}

void debug2(const Mat &mat) {
  for(int i=0;i<N;i++) {
    auto row = mat[i];
    sort(row.begin(), row.begin() + N);
    for(int j=0;j<N;j++) {
      cout << row[j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void markdiff(const Mat &mat2, Mat &diff) {
  for(int i=0;i<N;i++) {
    auto r1 = mat2[i];
    sort(r1.begin(), r1.begin() + N);
    for(int j=i+1;j<N;j++) {
      if(diff[i][j]) continue;
      auto r2 = mat2[j];
      sort(r2.begin(), r2.begin() + N);
      if(r1 != r2) {
        diff[i][j] = 1;
        diff[j][i] = 1;
      }
    }
  }
}

Mat genmat() {
  Mat mat = Mat();
  for(int i=0;i<N;i++) {
    mat[i][(i+1)%N] = 2;
    mat[(i+1)%N][i] = 2;
  }
  for(int i=0;i<N;i++) {
    for(int j=i+1;j<N;j++) {
      while(mat[i][j] > 1) {
        int a = rnd() % N;
        if(a == i || a == j || mat[i][a]) continue;
        while(true) {
          int b = rnd() % N;
          if(b == i || b == j || a == b || mat[a][b] == 0 || mat[j][b]) continue;
          mat[a][b]--; mat[b][a]--;
          mat[i][j]--; mat[j][i]--;
          mat[i][a]++; mat[a][i]++;
          mat[j][b]++; mat[b][j]++;
          break;
        }
      }
    }
  }
  return mat;
}

bool checkmat(const Mat &diff) {
  for(int i=0;i<N;i++) {
    for(int j=i+1;j<N;j++) if(diff[i][j] == 0) return false;
  }
  return true;
}

void process() {
  int a, b;
  scanf(" %d %d", &a, &b);
  N = a;
  Mat mat;
  while(true) {
    mat = move(genmat());
    Mat diff = Mat{};
    Mat cur = mat;
    for(int i=1;i<10;i++) {
      Mat nex = move(matmul(cur, mat));
      markdiff(nex, diff);
      cur = move(nex);
    }
    for(int i=0;i<N;i++) {
      int cnt = 0;
      for(int j=i+1;j<N;j++) if(!diff[i][j]) {
      }
    }
    // debug(diff);
    if(checkmat(diff)) break;
  }
  printf("%d\n", N);
  for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) if(mat[i][j]) {
    printf("%d %d\n", i+1, j+1);
  }
  fflush(stdout);
  Mat m2{};
  scanf("%d\n", N);
  for(int i=0;i<N*2;i++) {
    scanf(" %d %d", &a, &b);
    m2[a-1][b-1] = m2[b-1][a-1] = 1;
  }
  Mat diff = Mat{};
  Mat c1 = mat, c2 = m2;
  for(int i=1;i<10;i++) {
    Mat n1 = move(matmul(c1, mat));
    Mat n2 = move(matmul(c2, m2));

    for(int j=0;j<N;j++) {
      auto r1 = n1[j];
      sort(r1.begin(), r1.begin() + N);
      for(int k=0;k<N;k++) if(diff[j][k] == 0) {
        auto r2 = n2[k];
        sort(r2.begin(), r2.begin() + N);
        if(r1 != r2) diff[j][k] = 1;
      }
    }

    c1 = move(n1);
    c2 = move(n2);
  }

  debug(diff);
  for(int i=0;i<N;i++) printf("%d ", i+1);
  fflush(stderr);
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    process();
  }

  return 0;
}
