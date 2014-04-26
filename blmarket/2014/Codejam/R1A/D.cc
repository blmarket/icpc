#include <iostream>

using namespace std;

int arr[1024];

int main(void) {
    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        int N;
        cin >> N;
        for(int j=0;j<N;j++) {
            cin >> arr[j];
        }
        printf("Case #%d: ", i+1);
        bool bad = false;
        for(int j=0;j<5;j++) {
            long long sum = 0;
            for(int k=j*200;k<(j+1)*200;k++)
                sum += arr[k];
            cout << sum << " ";
            if(sum > 108000 || sum < 92000) {
                bad = true;
            }
        }
        if(bad) {
            cout << "BAD" << endl;
        } else {
            cout << "GOOD" << endl;
        }
    }
}
