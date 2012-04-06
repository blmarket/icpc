#include <iostream>
#include <cmath>
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

double get_pos(double tt, double hh)
{
    if(tt < 0) return hh;
    double cycle = sqrt(2*hh / 10.0);
    int divi = (int)(tt / cycle);
    double elasp = tt - (cycle * divi);
    if(divi % 2 == 1)
        elasp = cycle-elasp;

    return hh-elasp*elasp*5.0;
}

void process(void)
{
    int n;
    double h,r,t;

    vector<double> V;
    cin >> n >> h >> r >> t;
    r /= 100; // centimeter
    for(int i=0;i<n;i++)
    {
        V.pb(get_pos(t-i,h));
    }
    sort(V.begin(), V.end());
    double addler = 0;
    for(int i=0;i<V.size();i++)
    {
        printf("%.02lf ",V[i]+addler);
        addler += r*2;
    }
    printf("\n");
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process();
    }
}
