#include <iostream>
#include <map>

using namespace std;

int N = 3;
int arr[] = {1,2,3};
int sum = 6;

map<int, double> memo;
double old(int a) {
    if(memo.count(a)) return memo[a];
    int sc = 0;
    double exp = 0;
    for(int i=0;i<N;i++) if(a & 1<<i) {
        sc += arr[i];
    } else {
        exp += (double)arr[i] / sum * old(a | 1<<i);
    }

    double oth = (double)sc / sum;
    double ret = (1 + exp) / (1-oth);
    return memo[a] = ret;
}

int main(void) {
    cout << old(0) << endl;
}
