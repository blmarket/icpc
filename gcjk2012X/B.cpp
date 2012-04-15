#include <iostream>
#include <cmath>
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

int n,r,h;
vector<int> xs,ys;

bool calc(int xpos, double ypos)
{
    double minn = M_PI;
    double maxx = 0;
    for(int i=0;i<n;i++)
    {
        if(xs[i] == xpos) continue;
        int xd = xs[i] - xpos;
        double yd = ys[i] - ypos;

        double A = yd;
        double B = -yd*xpos + ypos * xd;
        //cerr << A << " " << B << "done?" << endl;

        if(xd < 0)
        {
            double rx = (-A*B - sqrt(A*A*B*B + ((double)r*xd*xd - B*B) * (A*A+xd*xd))) / (A*A+xd*xd);
            double ry = (rx * A + B) / xd;
            //cerr << "res L: " << rx << " " << ry << " " << rx*rx+ry*ry << endl;
            if(ry < 0) continue;
            double angle = atan2(ry,rx);
            //cerr << "minn angle = " << angle << endl;
            minn = min(minn, angle);
        }
        else
        {
            double rx = (-A*B + sqrt(A*A*B*B + ((double)r*xd*xd - B*B) * (A*A+xd*xd))) / (A*A+xd*xd);
            double ry = (rx * A + B) / xd;
            //cerr << "res L: " << rx << " " << ry << " " << rx*rx+ry*ry << endl;
            if(ry < 0) continue;
            double angle = atan2(ry,rx);
            //cerr << "minn angle = " << angle << endl;
            maxx = max(maxx, angle);
        }
    }
    double adiff = minn - maxx;
    double tdiff = (adiff / M_PI) * 12;
    //cerr << minn << " " << maxx << " " << adiff << " " << tdiff << endl;
    return tdiff >= h;
}

void process(void)
{
    cin >> n >> r >> h;
    r=r*r;
    xs.resize(n); ys.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> xs[i] >> ys[i];
    }
    // do i need to use R?

    double ret = 0;
    double sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += ys[i];
        double yss = 0, ye = ys[i];
        for(int j=0;j<400;j++)
        {
            double mid = (yss + ye) / 2;
            if(calc(xs[i], mid))
            {
                ye = mid;
            }
            else
            {
                yss = mid;
            }
        }
        ret += (ys[i] - ye);
    }
    printf("%.12lf\n", ret/sum);
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
