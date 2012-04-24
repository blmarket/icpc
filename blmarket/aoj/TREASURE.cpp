#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int x1,y1,x2,y2;
int n;
int data[105][2];

int px,py,x,y;

double getr(int x, int px, int tx)
{
    int a = x - px;
    int b = tx - px;
    return (double)b / a;
}

double rr(int x, int px, double r)
{
    return r*x + (1.-r)*px;
}

void process()
{
    scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n);
    double ret = 0;

    y2 -= y1;

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&data[i][0], &data[i][1]);
        data[i][1] -= y1;
    }
    data[n][0] = data[0][0];
    data[n][1] = data[0][1];

    px = data[0][0];
    py = data[0][1];
    for(int i=1;i<=n;i++,px=x,py=y)
    {
        x = data[i][0];
        y = data[i][1];
        if(px == x) continue;
        double t1 = getr(x,px,x1), t2 = getr(x,px,x2);
        if(t1 > t2) swap(t1,t2);
        if(t1 >= 1) continue;
        if(t2 <= 0) continue;

        if(t1 < 0) t1 = 0;
        if(t2 > 1) t2 = 1;
        if(t1 > t2) continue;

        double xx1 = rr(x,px,t1);
        double yy1 = rr(y,py,t1);
        double xx2 = rr(x,px,t2);
        double yy2 = rr(y,py,t2);
        double dxx = xx2 - xx1;

        cout << xx1 << " " << yy1 + y1 << " " << xx2 << " " << yy2 + y1 << endl;

        if(py != y)
        {
            double tt1 = getr(yy2,yy1,0), tt2 = getr(yy2,yy1,y2);
            cout << tt1 << " " << tt2 << endl;
            if(tt1 > tt2) swap(tt1, tt2);
            if(tt1 >= 1) continue;
            if(tt2 <= 0) continue;

            if(tt1 < 0) tt1 = 0;
            if(tt2 > 1) tt2 = 1;
            if(tt1 > tt2) continue;

            double ty1 = rr(yy2, yy1, tt1);
            cout << "::" << rr(xx2,xx1,tt1) << "," << ty1+y1 << endl;
            if(yy1 >= y1)
            {
                ret += (double)(ty1 + min(yy1, (double)y2)) * dxx * tt1;
                cout << ret << " a" << endl;
            }

            double ty2 = rr(yy2,yy1, tt2);
            cout << ":::" << rr(xx2,xx1,tt1) << "," << ty1+y1 << " - " << rr(xx2,xx1,tt2) << "," << ty2+y1 << endl;
            ret += (double)(min(ty1, (double)y2) + min(ty2, (double)y2)) * dxx * (tt2 - tt1);
            cout << ret << " b" << endl;

            if(yy1 >= y2)
            {
                ret += (double)(ty2 + min(yy2, (double)y2)) * dxx * (1 - tt2);
                cout << ret << " c" << endl;
            }
        }
        else
        {
            if(py <= y1) continue;
            ret += (double)((min(y2, py) - y1) * 2) * (x - px) * (t2 - t1);
            continue;
        }
    }
    if(ret < 0) ret = -ret;
    printf("%.12lf\n", ret/2);
}

int main(void)
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        process();
}
