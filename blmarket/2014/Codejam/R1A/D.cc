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

        int nswap = 0;
        for(int j=0;j<N;j++) {
            while(arr[j] != j) {
                nswap++;
                swap(arr[j], arr[arr[j]]);
            }
        }
        cout << nswap << endl;
        if(nswap < 990) {
            cout << "BAD" << endl;
            bc++;
        } else {
            cout << "GOOD" << endl;
        }
    }
    cout << bc << endl;
}
