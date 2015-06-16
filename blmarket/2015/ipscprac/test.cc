#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    unordered_set<long long> S;
    for(int i=0;i<100000;i++) {
        S.insert(i);
        cout << S.bucket_count() << endl;
    }
}
