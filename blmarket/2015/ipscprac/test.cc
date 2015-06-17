#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    int ps = 0;
    unordered_set<long long> S;

    for(int i=0;i<100000;i++) {
        S.insert(i);
        if(S.bucket_count() != ps) {
            cout << S.bucket_count() << endl;
        }
        // cout << i << " = " << S.bucket(i) << endl;
        ps = S.bucket_count();
    }
}
