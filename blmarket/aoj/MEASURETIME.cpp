#include <iostream>
#include <memory>
#include <list>
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

template<typename T> int size(const T &a) { return a.size(); } 

struct tree
{
    int n;
    int key;
    tree *left, *right;

    tree(int key) 
    { 
        n = 1;
        this->key = key;
        left = right = NULL;
    }
};

int n;

int go(tree *t, int a)
{
    cout << "::" << t->n << " " << t->key << " " << a << endl;
    t->n += 1;
    if(t->key <= a)
    {
        cout << "going right" << endl;
        if(t->right) 
        {
            return go(t->right, a);
        }
        cout << "making right " << a << endl;
        t->right = new tree(a);
        return 0;
    }
    int ret = 0;
    if(t->right) ret = t->right->n;
    ret++;
    if(t->left) 
    {   
        ret += go(t->left, a);
    }
    else
    {
        t->left = new tree(a);
    }
    return ret;
}

void process(int dataId)
{
    scanf("%d",&n);
    tree *root = NULL;
    long long ret = 0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(root == NULL)
        {
            root = new tree(tmp);
            continue;
        }
        tmp = go(root, tmp);
        cout << tmp << endl;
        ret += tmp;
    }
    cout << ret << endl;
    cout << endl;
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
