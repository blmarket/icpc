#include <iostream>
#include <algorithm>
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
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int main(void)
{
    int score = 0;
    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        string word;
        cin >> word;
        for(int j=0;j<size(word);j++) {
            int x,y;
            cin >> x >> y;
        }
        score += size(word) * size(word);
    }
    cout << score << endl;
}
