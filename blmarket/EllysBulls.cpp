#include <iostream>
#include <ctime>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

int N;
vector<string> guess;
map<pair<int, VI>, int> memo;
string result;

int go(int pos, const VI &bull) {
    pair<int, VI> key = mp(pos, bull);
    if(memo.count(key)) return memo[key];

    if(pos == N) {
        return 0;
    }

    int ret = 0;
    
    for(int i='0';i<='9';i++) {
        bool fail = false;
        vector<int> tmp = bull;
        for(int j=0;j<size(guess);j++) {
            if(guess[j][pos] == i) {
                if(tmp[j] == 0) { fail = true; break; }
                tmp[j]--;
            }
        }
        if(fail) continue;
        int tmp2 = go(pos+1, tmp);
        if(tmp2 < 1) continue;
        result[pos] = i;
        ret += tmp2;
        if(ret > 1) break;
    }
    return memo[key] = ret;
}

class EllysBulls 
{
public:
    string getNumber(vector <string> guesses, vector <int> bulls) 
    {
        memo.clear();
        guess = guesses;
        N = size(guesses[0]);
        memo[mp(N, VI(size(bulls), 0))] = 1;
        result = string(N, '?');
        int ret = go(0, bulls);
        if(ret == 1) return result;
        if(ret == 0) return "Liar";
        return "Ambiguity";
    }
};

string gen(void) {
    string tmp = "";
    for(int i=0;i<9;i++) {
        tmp = tmp + (char)('0' + (rand() % 10));
    }
    return tmp;
}

int main()
{
    srand(time(NULL));
    string orig = gen();

    vector<int> bull;
    vector<string> arr;
    for(int i=0;i<10;i++) {
        arr.pb(gen());
        int cnt = 0;
        for(int j=0;j<9;j++) {
            if(arr.back()[j] == orig[j]) cnt++;
        }
        bull.pb(cnt);
    }

    cout << orig << endl;
    EllysBulls __tmp;
    cout << __tmp.getNumber(arr, bull) << endl;
} 
