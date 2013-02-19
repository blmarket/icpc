#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {
    cout << "{";
    for(int i=0;i<50;i++) {
        cout << (rand() % 90000) + 10000 << ",";
    }
}
