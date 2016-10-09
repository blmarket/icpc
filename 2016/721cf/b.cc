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

int N, K;
vector<string> words;

int main(void) {
    scanf(" %d %d", &N, &K);
    char str[105];
    for(int i=0;i<N;i++) {
        scanf(" %s", str);
        words.pb(str);
    }
    scanf(" %s", str);
    int l = strlen(str);
    int ns = 0, ne = 0;
    for(int i=0;i<N;i++) {
        if(words[i].size() < l) ns++;
        if(words[i].size() == l) ne++;
    }
    cout << ns << " " << ne << endl;
    return 0;
}
