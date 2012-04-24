#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int x1,y1,x2,y2;
int n;
int data[105][2];

int px,py,x,y;

double getr(double x, double px, double tx)
{
    double a = x - px;
    double b = tx - px;
    return (double)b / a;
}

double rr(double x, double px, double r)
{
    return r*x + (1.-r)*px;
}

void process()
{
    scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n);
    double ret = 0;

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&data[i][0], &data[i][1]);
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

        cout << xx1 << " " << yy1 << " - " << xx2 << " " << yy2 << endl;

        if(py != y)
        {
            double tt1 = getr(yy2,yy1,y1), tt2 = getr(yy2,yy1,y2);

            if(tt1 > tt2) swap(tt1, tt2);
            if(tt1 < 0) tt1 = 0;
            if(tt1 > 1) tt1 = 1;
            if(tt2 < 0) tt2 = 0;
            if(tt2 > 1) tt2 = 1;

            double ty1 = rr(yy2, yy1, tt1);
            cout << "::" << xx1 << " " << yy1 << " - " << rr(xx2,xx1,tt1) << "," << ty1 << endl;
            if(yy1 >= y1)
            {
                ret += (double)(ty1 + min(yy1, (double)y2)) * dxx * tt1;
            }

            double ty2 = rr(yy2,yy1, tt2);
            cout << ":::" << rr(xx2,xx1,tt1) << "," << ty1 << " - " << rr(xx2,xx1,tt2) << "," << ty2 << endl;
            ret += (double)(min(ty1, (double)y2) + min(ty2, (double)y2)) * dxx * (tt2 - tt1);

            cout << "::::" << xx2 << " " << yy2 << endl;
            if(yy2 >= y1)
            {
                ret += (double)(ty2 + min(yy2, (double)y2)) * dxx * (1 - tt2);
            }
        }
        else
        {
            if(py <= y1) continue;
            ret += (double)((min(y2, py) - y1) * 2) * (x - px) * (t2 - t1);
        }

        printf("%.12lf\n",ret);
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
