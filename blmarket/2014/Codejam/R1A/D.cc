#include <iostream>

using namespace std;

int arr[1024];

int main(void) {
    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        int N;
        cin >> N;
        int same = 0;
        for(int j=0;j<N;j++) {
            cin >> arr[j];
            if(j == arr[j]) same++;
        }
        printf("Case #%d: ", i+1);
        if(same > 50) {
            printf("BAD\n");
        } else {
            printf("GOOD\n");
        }
    }
}
