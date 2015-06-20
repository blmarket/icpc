#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

long long x[50];
int c[50];

long long mod(long long a) {
    return a % (1LL << 32);
}

int it = 43;
long long next() {
    x[it] = x[(it-22+50)%50] - x[(it-43+50)%50] - c[(it-1+50)%50];
    c[it] = x[it] < 0 ? 1 : 0;
    x[it] += c[it] * (1LL << 32);

    long long ret = x[it];
    it = (it+1) % 50;
    return ret;
}

int n;
vector<long long> board;

void process(void) {
    scanf("%d", &n);
    board.resize(n);
    for(int i=0;i<n;i++) {
        scanf("%lld", &board[i]);
    }

    int m;
    char moves[5005];
    scanf("%d", &m);
    scanf(" %s", moves);
    for(int i=0;i<m;i++) {
        if(moves[i] == 'r') {
        } else if(moves[i] == 'l') {
        } else {
            throw 1;
        }
    }
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) process();



    for(int i=0;i<=42;i++) {
        x[i] = mod(mod(mod(i*i)*i)*999999999LL);
    }
    int it = 43;


    for(int i=0;i<10;i++) {
        cout << next() << endl;
    }

}
