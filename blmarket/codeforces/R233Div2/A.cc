#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define mp make_pair
#define pb push_back

using namespace std;

template<typename T> int size(const T &a) { return a.size(); }

typedef pair<int, int> PII;

int main(void) {
    int n,p,k;
    scanf("%d %d %d",&n,&p,&k);
    ostringstream ost;
    for(int i=p-k;i<=p+k;i++) {
        if(i < 1 || i >n) continue;
        ost << i << " ";
    }
    if(p-k > 1) cout << "<< ";
    cout << ost.str();
    if(p+k < n) cout << ">>";
    cout << endl;

    return 0;
}
