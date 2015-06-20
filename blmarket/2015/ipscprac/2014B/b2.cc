#include <iostream>
#include <vector>
#include <set>

#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

typedef long long LL;

long long x[5000];
int c;

long long mod(long long a) {
    return a % (1LL << 32);
}

int it;
long long next(int idx) {
    while(it <= idx) {
        x[it] = x[(it-22+50)%50] - x[(it-43+50)%50] - c;
        c = x[it] < 0 ? 1 : 0;
        x[it] += c * (1LL << 32);
    }

    return x[idx];
}

int n;

void move(vector<long long> &board, bool right, int rp) {
    vector<long long> pboard = board;
    if(right)
        reverse(board.begin(), board.end());

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
    if(right) reverse(tmp.begin(), tmp.end());

    if(tmp != pboard && nempty > 0) {
        int pos = next(rp) % nempty;
        int value = (next(rp + 1) % 10) == 0 ? 4 : 2;
        if(!right) pos += (n - nempty);
        tmp[pos] = value;
    }

    board.swap(tmp);
}

set<vector<long long> > memo;

void process(void) {
    scanf("%d", &n);
    vector<long long> board;
    board.resize(n);
    for(int i=0;i<n;i++) {
        long long tmp;
        scanf("%lld", &tmp);
        board[i] = tmp;
    }
    for(int i=0;i<43;i++) {
        scanf("%lld", &x[i]);
    }
    c = 0; it = 43;

    memo.insert(board);
    vector<vector<LL> > b[2];
    b[1].pb(board);
    int ii;
    for(ii=0;;ii++) {
        int i = (ii % 2);
        cerr << ii << " " << i << endl;
        if(b[i].size() == 0) {
            ii--;
            break;
        }
        b[!i].clear();
        cout << "----" << endl;
        for(const auto &jt : b[i]) {
            for(auto kt: jt) {
                cout << kt << " ";
            }
            cout << endl;
            vector<LL> tmp = jt;
            move(tmp, false, 43+2*ii);
            if(memo.count(tmp) == 0) {
                memo.insert(tmp);
                b[!i].pb(tmp);
            }
            tmp = jt;
            move(tmp, true, 43+2*ii);
            if(memo.count(tmp) == 0) {
                memo.insert(tmp);
                b[!i].pb(tmp);
            }
        }
    }

    LL sum = 0;
    vector<LL> tmp = b[ii][0];
    for(auto it:tmp) {
        cout << it << " ";
        sum += it;
    }
    cout << endl;
    cout << sum << endl;

}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) process();
}
