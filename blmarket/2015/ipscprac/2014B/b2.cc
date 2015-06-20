#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

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
        long long tmp;
        scanf("%lld", &tmp);
        board[i] = tmp;
    }
    for(int i=0;i<43;i++) {
        scanf("%lld", &x[i]);
    }

    int m;
    char moves[5005];
    scanf("%d", &m);
    scanf(" %s", moves);
    for(int i=0;i<m;i++) {
        for(int j=0;j<size(board);j++) cout << board[j] << " ";
        cout << endl;
        if(moves[i] == 'r') {
            reverse(board.begin(), board.end());
        } else if(moves[i] == 'l') {
        } else {
            throw 1;
        }

        vector<long long> tmp; tmp.clear();
        for(int j=0;j<size(board);j++) if(board[j] != 0) {
            if(tmp.size() && tmp.back() == board[j]) {
                tmp.back() = -tmp.back() * 2;
            } else {
                tmp.push_back(board[j]);
            }
        }
        for(int j=0;j<size(tmp);j++) if(tmp[j] < 0) tmp[j] = -tmp[j];
        int nempty = board.size() - tmp.size();
        tmp.resize(board.size());
        if(moves[i] == 'r') reverse(tmp.begin(), tmp.end());

        if(tmp != board && nempty > 0) {
            cout << "ADD oNE" << endl;
            int pos = next() % nempty;
            int value = (next() % 10) == 0 ? 4 : 2;
            if(moves[i] == 'l') pos += (n - nempty);
            tmp[pos] = value;
        }

        board.swap(tmp);

    }

    for(int i=0;i<n;i++) {
        cout << board[i] << " ";
    }
    cout << endl;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<1;i++) process();
}
