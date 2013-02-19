#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> mapp(50, string(50, 'Y'));

int main(void) {
    cout << "{";
    for(int i=0;i<50;i++) {
        cout << (rand() % 90000) + 10000 << ",";
    }
    cout << endl;

    for(int i=0;i<10;i++) {
        int x = rand() % 50;
        int y = rand() % 50;
        mapp[x][y] = mapp[y][x] = 'N';
    }

    for(int i=0;i<50;i++) {
        cout << mapp[i] << ",";
    }
    cout << endl;
}
