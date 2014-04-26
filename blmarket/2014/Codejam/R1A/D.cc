#include <iostream>
#include <vector>

using namespace std;

int arr[1024];

int main(void) {
    int T;
    cin >> T;
    int bc = 0;
    for(int i=0;i<T;i++) {
        int N;
        cin >> N;
        for(int j=0;j<N;j++) {
            cin >> arr[j];
        }
        printf("Case #%d: ", i+1);

        vector<int> sums;

        bool bad = false;
        for(int j=0;j<5;j++) {
            long long sum = 0;
            for(int k=j*200;k<(j+1)*200;k++)
                sum += arr[k];
            cout << sum << " ";
            sums.push_back(sum);
        }
        if(bad) {
            cout << "BAD" << endl;
            bc++;
        } else {
            cout << "GOOD" << endl;
        }
    }
    cout << bc << endl;
}
