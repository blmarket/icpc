#include <iostream>
#include <vector>

using namespace std;

double prob[2][1024][1024];

int main(void) {
    for(int i=0;i<1000;i++) {
        prob[0][i][i] = 1.0;
    }

    for(int i=0;i<1000;i++) {
        int cur = (i%2);
        int nex = (1-cur);

        memset(prob[nex], 0, sizeof(prob[0]));

        for(int j=0;j<1000;j++) prob[nex][i][j] = prob[cur][i][j];

        for(int j=0;j<1000;j++) if(j != i) {
            for(int k=0;k<1000;k++) {
                prob[nex][j][k] += prob[cur][j][k] * 0.999 + prob[cur][i][k] * 0.001;
                prob[nex][i][k] += prob[cur][j][k] * 0.001 - prob[cur][i][k] * 0.001;
            }
        }

        // for(int j=0;j<1000;j++) for(int k=0;k<1000;k++) prob[nex][j][k] = prob[cur][j][k] * 0.999;

        // for(int j=0;j<1000;j++) {

        //     for(int a=0;a<1000;a++) for(int b=0;b<1000;b++) {
        //         int na = a;
        //         if(a == i || a == j) {
        //             na = (i+j-a);
        //         }
        //         prob[nex][na][b] += 0.001 * prob[cur][a][b];
        //     }
        // }
    }

    int T;
    scanf("%d", &T);
    int bc = 0;
    for(int i=0;i<T;i++) {
        int n;
        scanf("%d", &n);
        double pp = 1;
        for(int j=0;j<n;j++) {
            int tmp;
            scanf("%d", &tmp);
            pp *= prob[0][j][tmp] * 1000;
        }
        printf("Case #%d: ", i+1);
        if(pp > 5.0) {
            printf("BAD\n");
            bc++;
        } else {
            printf("GOOD\n");
        }
    }
    cerr << bc << endl;
}
