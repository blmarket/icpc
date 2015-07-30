#include <iostream>

using namespace std;

struct Grader {
    int N;
    int dist[50][50];
    int cnt = 0;

    Grader() {
        scanf("%d", &N);
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++)
                scanf(" %d", &dist[i][j]);
        }
    }

    int getDist(int a, int b) {
        cnt++;
        return dist[a][b];
    }
};

Grader g;

int main(void) {
}
