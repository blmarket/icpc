#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>
#include <vector>
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
typedef complex<double> Point;

template<typename T> int size(const T &a) { return a.size(); } 

Point a,b,c;

double cross(const Point &a, const Point &b) { return imag(conj(a) * b); }

Point intersect(const Point &a, const Point &b, const Point &p, const Point &q)
{
    double d1 = cross(p-a, b-a);
    double d2 = cross(q-a, b-a);

    return (d1 * q - d2 * p) / (d1 - d2);
}

double atanxx(const Point &pp)
{
    return atan2(pp.imag(), pp.real());
}

int main(void)
{
    double aa,bb;
    cin >> aa >> bb;
    a = Point(aa,bb);
    cin >> aa >> bb;
    b = Point(aa,bb);
    cin >> aa >> bb;
    c = Point(aa,bb);

    Point v1,v2,vec1,vec2;
    v1 = (a+b); v1 /= 2; vec1 = b-a; vec1 = Point(vec1.imag(), vec1.real());
    v2 = (a+c); v2 /= 2; vec2 = c-a; vec2 = Point(vec2.imag(), vec2.real());

    Point center = intersect(v1, v1 + vec1, v2, v2 + vec2);

    double d1,d2,d3;
    d1 = atanxx(a - center);
    d2 = atanxx(b - center);
    d3 = atanxx(c - center);

    Point rr = a - center;
    double radii = sqrt(sqr(rr.imag()) + sqr(rr.real()));

    for(int i=3;i<=100;i++)
    {
        double minangle = 2.0 * M_PI / i;

        double m1,m2,m3, tmp;
        m1 = modf((d2-d1)/minangle, &tmp);
        m2 = modf((d3-d2)/minangle, &tmp);
        m3 = modf((d3-d1)/minangle, &tmp);
        if(m1 > 1e-6 && m1 < 1-1e-6) continue;
        if(m2 > 1e-6 && m2 < 1-1e-6) continue;
        if(m3 > 1e-6 && m3 < 1-1e-6) continue;
        double res = radii * radii * sin(minangle) / 2 * i;
        printf("%.8lf\n",res);
        return 0;
    }
    printf("%.8lf\n", radii * M_PI * 2);
    return 0;
}
