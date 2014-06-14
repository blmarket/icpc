#include <algorithm>
#include <iostream>
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
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N;

double calc(string &a) {
    for(int i=0;i<size(a);i++) {
        if(a[i] >= 'a' && a[i] <= 'z') continue;
        if(a[i] >= 'A' && a[i] <= 'Z') continue;
        if(a[i] == '*') {
            a.replace(i, i+1, " * ");
            i++;
        }
        a[i] = ' ';
    }

    istringstream sin(a);
    int cnt = 0;
    double score = 0;
    string word;
    while(sin >> word) {
        bool upper = true;
        for(int i=0;i<size(word);i++) if(word[i] >= 'a' && word[i] <= 'z') upper = false;
        cnt++;
        score++;
        if(upper) score += 1;
    }
    return score / cnt;
}

void process(int dataId)
{
    cin >> N;
    string str;
    getline(cin, str);
    for(int i=0;i<N;i++) {
        getline(cin, str);
        calc(str);
    }
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
