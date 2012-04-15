#include <iostream>
#include <cmath>
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

int h,w,d;
vector<string> data;
int x,y;
int ret;

set<PII> vectors;

int gcd(int a,int b)
{
    if(a<0) return gcd(-a,b);
    if(b<0) return gcd(a,-b);
    if(a<b) return gcd(b,a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int move(int &xx, int &yy, int &dx, int &dy)
{
    //cout << xx << " " << yy << " " << dx << " " << dy << " " << endl;
    int gg = gcd(dx,dy);
    if(gg != 1)
    {
        int ddx = dx/gg;
        int ddy = dy/gg;
        for(int i=0;i<gg;i++)
        {
            int tt = move(xx,yy,ddx,ddy);
            if(tt == -2) return -2;
            if(tt) return true;
        }
        return false;
    }

    int ax = abs(dx);
    int ay = abs(dy);

    vector<bool> moves;

    if(ax == 0)
    {
        for(int i=0;i<ay;i++) moves.pb(false);
    }
    else
    {
        if(ay == 0)
        {
            for(int i=0;i<ax;i++) moves.pb(true);
        }
        else
        {
            int ty = 0;
            for(int i=0;i<ax;i++)
            {
                ty += ay;
                while(ty >= ax)
                {
                    moves.pb(false);
                    ty -= ax;
                }
                moves.pb(true);
            }
        }
    }
    dx /= ax;
    dy /= ay;
    for(int i=0;i<size(moves);i++)
    {
        //cout << "m" << xx << " " << yy << " " << dx << " " << dy << " " << moves[i] << endl;
        if(moves[i])
        {
            if((xx % 2 == 0) && data[(xx + dx) /2][(yy + (dy-1)/2) / 2] == '#')
            {
                dx = -dx;
            }
            xx += dx;
        }
        else
        {
            if((yy % 2 == 0) && data[(xx + (dx-1)/2) / 2][(yy + dy) /2] == '#')
            {
                dy = -dy;
            }
            yy += dy;
        }
    }

    if((xx%2)==0 && (yy%2)==0)
    {
        xx += dx;
        yy += dy;
        if(data[xx/2][yy/2] == '#')
        {
            xx -= 2*dx;
            if(data[xx/2][yy/2] != '#')
            {
                xx += 2*dx;
                yy -= 2*dy;
                if(data[xx/2][yy/2] != '#')
                {
                    return -2;
                }
                yy += dy;
                xx -= dx;
            }
            else
            {
                xx += dx;
                yy -= dy;
            }
        }
        else
        {
            xx-=dx;
            yy-=dy;
        }
    }
    dx *= ax;
    dy *= ay;

    return (xx == x && yy == y);
}

int tmove(int &xx, int &yy, int &dx, int &dy)
{
    if(move(xx,yy,dx,dy) == 1) return 1;
    return 0;
}

void process(void)
{
    cin >> h >> w >> d;
    data.resize(h);
    for(int i=0;i<h;i++)
    {
        cin >> data[i];
        for(int j=0;j<size(data[i]);j++)
        {
            if(data[i][j] == 'X')
            {
                x=i,y=j;
                break;
            }
        }
    }

    ret = 0;
    vectors.clear();

    if((x-1)*2+1 <= d) ret++;
    if((y-1)*2+1 <= d) ret++;
    if((h-2-x)*2+1 <= d) ret++;
    if((w-2-y)*2+1 <= d) ret++;

    cout << ret << endl;
    
    x=x*2+1;
    y=y*2+1;

    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
        {
            if(i*i+j*j > d*d) break;

            int dx = i / gcd(i,j);
            int dy = j / gcd(i,j);
            int pow = dx*dx+dy*dy;

            if(vectors.count(mp(dx,dy))) continue;
            vectors.insert(mp(dx,dy));

            int k;
            for(k=1;;k++)
            {
                if(pow*k*k > d*d) break;
            }
            k--;
            dx *= k * 2;
            dy *= k * 2;

            int tret = ret;

            int xx = x, yy = y;
            int ddx = dx, ddy = -dy;
            ret += tmove(xx,yy,ddx,ddy);
            xx=x,yy=y;
            ddx = dx, ddy = dy;
            ret += tmove(xx,yy,ddx,ddy);
            xx=x,yy=y;
            ddx = -dx, ddy = dy;
            ret += tmove(xx,yy,ddx,ddy);
            xx=x,yy=y;
            ddx = -dx, ddy = -dy;
            ret += tmove(xx,yy,ddx,ddy);
        }
    }
    cout << ret << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
