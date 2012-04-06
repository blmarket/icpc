#include <iostream>
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
    tree()
    {
        parent = NULL;
        good = false;
    }

    vector<tree *> V;
    tree *parent;
    int tagname;
    string id;
    int desired;
    bool good;
    int memo[8][8][8];
};

string avail[8] = { "black", "blue", "gray", "green", "red", "white", "yellow", "" };

int go(tree *node, int a,int b,int c)
{
    int &ret = node->memo[a][b][c];
    if(ret != -1) return ret;

    ret = 99999;

    for(int i=0;i<8;i++) { for(int k=0;k<8;k++) { for(int l=0;l<8;l++)
    {
        int tmp = 0;

        if(a != i) tmp++;
        if(b != k) tmp++;
        if(c != l) tmp++;

        for(int j=0;j<size(node->V);j++)
        {
            tmp += go(node->V[j], i,k,l);
        }

        switch(node->tagname)
        {
            case 0:
                if(node->desired != a) tmp++;
                break;
            case 1:
                if(node->desired != b) tmp++;
                break;
            case 2:
                if(node->desired != c) tmp++;
                break;
        }
        ret = min(ret, tmp);
    }}}

//    cout << node->id << " " << color[0] << " " << color[1] << " " << color[2] << " = " << ret << endl;

    return ret;
}

class CssRules 
{
public:
    int getMinimalCssRuleCount(vector <string> xhtml) 
    {
        tree root;
        root.parent = NULL;
        tree *cur = &root;

        string str;
        for(int i=0;i<size(xhtml);i++) str += xhtml[i];
        for(int i=0;i<size(str);i++)
        {
            if(str[i] == '<')
            {
                int j;
                for(j=i+1;str[j] != '>';j++);
                string tmp = str.substr(i+1,j-i-1);
                i=j;
                if(tmp[0] == '/') 
                {
                    cur = cur->parent;
                    continue;
                }

                vector<int> idx;
                for(j=0;j<size(tmp);j++) if(tmp[j] == '\'' || tmp[j] == ':') idx.pb(j);

                tree *node = new tree();
                node->parent = cur;
                switch(tmp[0])
                {
                    case 'b':
                        node->tagname = 0;
                        break;
                    case 'i':
                        node->tagname = 1;
                        break;
                    case 'u':
                        node->tagname = 2;
                        break;
                }
                node->id =tmp.substr(idx[0]+1, idx[1]-idx[0]-1) ;
                memset(node->memo, -1, sizeof(node->memo));
                string tmp2 = tmp.substr(idx[3]+1, idx[4] - idx[3] -1) ;
                for(int j=0;j<8;j++)
                    if(avail[j] == tmp2) { node->desired = j; break; }
                node->good = false;

                cur->V.pb(node);
                cur = node;
            }
        }

        int ret = 0;
        for(int i=0;i<size(root.V);i++)
        {
            ret += go(root.V[i], 7,7,7);
        }
        return ret;
    }
};


// Powered by FileEdit
