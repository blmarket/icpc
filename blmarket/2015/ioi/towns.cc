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


int main(void) {
    int ab = g.getDist(0, 1);
    int m1 = 0;
    int m2 = 1;

    for(int i=2;i<g.N;i++) {
        int ac = g.getDist(m1, i);
        int bc = g.getDist(m2, i);

        if(bc > ab && bc > ac) {
        }
    }

    return 0;
}
