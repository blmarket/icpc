#include <iostream>
#include <map>
#include <vector>
#include <set>

#define pb push_back
#define mp make_pair

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
        it++;
    }

    return x[idx];
}

int n;

long long move(vector<long long> &board, bool right, int &rp) {
    long long ret = 0;
    vector<long long> pboard = board;
    if(right)
        reverse(board.begin(), board.end());

    vector<long long> tmp; tmp.clear();
    for(int j=0;j<size(board);j++) if(board[j] != 0) {
        if(tmp.size() && tmp.back() == board[j]) {
            ret += tmp.back() * 2;
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
        rp += 2;
    }

    board.swap(tmp);
    return ret;
}

map<pair<int, vector<long long> >, long long> memo;

long long calc(int pos, vector<LL> board) {
    vector<LL> pboard = board;

    pair<int, vector<LL> > key = mp(pos, board);
    if(memo.count(key)) {
        return memo[key];
    }
    memo[key] = 0;

    vector<LL> tmp = board;
    int tp = pos;

    long long ret = move(tmp, false, tp);
    ret += calc(tp, tmp);

    tp = pos;
    long long tmp2 = move(board, true, tp);
    tmp2 += calc(tp, board);

    cout << pos << " : ";
    for(auto it : pboard) cout << it << " ";
    cout << "= " << max(ret, tmp2) << endl;

    return memo[key] = max(ret, tmp2);
}

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

    cout << calc(43, board) << endl;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) process();
}
