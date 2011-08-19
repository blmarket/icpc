#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <complex>

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

int unused;
int used[10];
bool isy[10];
vector<bool> ans;
int ret=0;

void go(int a, int sz)
{
    if(size(ans) - a < unused) return;
    if(a == size(ans))
    {
        for(int i=0;i<sz;i++)
            if(used[i] == 0) return;
        ret++;
        return;
    }
    for(int i=0;i<sz;i++)
    {
        if(used[i] == 0)
        {
            unused--;
            isy[i] = ans[a];
        }
        else
        {
            if(isy[i] != ans[a]) 
            {
                continue;
            }
        }

        used[i]++;
        go(a+1, sz);
        used[i]--;
        if(used[i] == 0) unused++;
    }
}

class TheQuestionsAndAnswersDivOne 
{
public:
    int find(int questions, vector <string> answers) 
    {
        for(int i=0;i<size(answers);i++)
        {
            ans.pb(answers[i] == "Yes");
        }

        unused = questions;

        go(0, questions);

        return ret;
    }
};


// Powered by FileEdit


// Powered by FileEdit
