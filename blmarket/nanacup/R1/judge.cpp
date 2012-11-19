#include <iostream>
#include <fstream>
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

int n,m;
vector<string> data;

int main(int argc, const char *argv[])
{
    ifstream fin(argv[argc-1]);
    fin >> n >> m;
    data.resize(n);
    for(int i=0;i<n;i++)
        fin >> data[i];
    fin.close();
    
    int score = 0;
    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        string word;
        cin >> word;
        int wrong = 0;
        for(int j=0;j<size(word);j++) {
            int x,y;
            cin >> x >> y;
            if(data[y][x] != word[j]) wrong++;
        }
        int tmp = sqr(size(word) - wrong) / (wrong + 1);
        cerr << size(word) << " " << wrong << " = " << tmp << endl;
        score += tmp;
    }
    cout << score << endl;
}
