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
        for(int j=0;j<10;j++) {
            long long sum = 0;
            for(int k=(j-1)*100;k<j*100;k++)
                sum += arr[k];
            cout << sum << " ";
        }
        cout << endl;
    }
}
