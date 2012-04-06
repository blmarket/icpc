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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int table[55][55] = {0}; // 1 : left(row) is lower then top, -1 : vice versa
LL length[55][55] = {0};
string real[55][55];
string row, col;

string go(int x,int y, LL pos)
{
    cout << x << " " << y << " " << pos << endl;

    if(length[x][y] <= pos) return "";
    if(x == 0) 
        return string(1, col[y-1]);
    if(y == 0) return string(1, row[x-1]);

    int cx,cy, nx,ny;
    cx = x-1, cy = y;
    nx = x, ny = y-1;
    if(table[x][y] == 1)
    {
        swap(cx,nx);
        swap(cy,ny);
    }

    if(length[cx][cy] <= pos)
        return go(nx,ny,pos-length[cx][cy]);
    if(length[cx][cy] <= pos + 50)
    {
        string t1 = go(cx,cy, pos);
        string t2 = go(nx,ny, 0);
        return t1 + t2.substr(0, pos+50-length[cx][cy]);
    }
    return go(cx,cy,pos);
}

class STable 
{
public:
    string getString(string s, string t, long long pos) 
    {
        row = s; col = t;
        string ss = row+col;
        sort(ss.begin(), ss.end());
        for(int i=0;i<size(ss);i++)
        {
            for(int j=0;j<size(row);j++) if(row[j] == ss[i])
            {
                for(int k=1;k<=size(col);k++)
                    if(table[j+1][k] == 0) table[j+1][k] = 1;
                for(int k=j+1;k<=size(row);k++)
                    if(table[k][1] == 0) table[k][1] = -1;
            }
            for(int j=0;j<size(col);j++) if(col[j] == ss[i])
            {
                for(int k=1;k<=size(row);k++)
                    if(table[k][j+1] == 0) table[k][j+1] = -1;
                for(int k=j+1;k<=size(col);k++)
                    if(table[1][k] == 0) table[1][k] = 1;
            }
        }

        for(int i=1;i<=size(row);i++)
        {
            length[i][0] = 1;
            real[i][0] = string(1, row[i-1]);
        }
        for(int i=1;i<=size(col);i++)
        {
            length[0][i] = 1;
            real[0][i] = string(1, col[i-1]);
        }

        for(int i=1;i<=size(row);i++)
            for(int j=1;j<=size(col);j++)
            {
                length[i][j] = length[i-1][j] + length[i][j-1];
                if(real[i-1][j] < real[i][j-1])
                {
                    real[i][j] = real[i-1][j] + real[i][j-1];
                    if(table[i][j] != -1)
                        cout << "ERROR " << i << " " << j << " " << real[i][j] << endl;
                }
                else
                {
                    real[i][j] = real[i][j-1] + real[i-1][j];
                    if(table[i][j] != 1)
                        cout << "ERROR " << i << " " << j << " " << real[i][j] << endl;
                }
            }

        cout << length[size(row)][size(col)] << endl;

        for(int i=1;i<=size(row);i++)
        {
            for(int j=1;j<=size(col);j++)
                cout << table[i][j] << "(" << length[i][j] << ") ";
            cout << endl;
        }

        return go(size(row), size(col), pos);
    }
};
