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
    for(int i=0;i<n;i++,px=x,py=y)
    {
        scanf("%d %d",&x, &y);
        data[i][0] = x, data[i][1] = y;
        if(i)
        {
            if(px == x) continue;
            double t1 = getr(x,px,x1), t2 = getr(x,px,x2);
            if(t1 > t2) swap(t1,t2);
            if(t1 >= 1) continue;
            if(t2 <= 0) continue;
            if(py != y)
            {
                double tt1 = getr(y,py,y1), tt2 = getr(y,py,y2);
                if(tt1 > tt2) swap(tt1, tt2);
                if(t1 < tt1) t1 = tt1;
                if(t2 > tt2) t2 = tt2;
            }
            else
            {
                if(py <= y1) continue;
                if(py >= y2) continue;
            }

            if(t1 < 0) t1 = 0;
            if(t2 > 1) t2 = 1;
            if(t1 > t2) continue;

            cout << rr(x,px,t1) << " " << rr(y,py,t1) << " - " << rr(x,px,t2) << " " << rr(y,py,t2) << endl;

            double area = (rr(y, py, t1) + rr(y, py, t2)) * (x-px) * (t2-t1);
            ret += area;
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
