#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> mapp(50, string(50, 'Y'));

int main(void) {
    for(int i=0;i<50;i++) {
        cout << (rand() % 90000) + 10000;
        if(i+1 < 50) cout << ",";
    }
    cout << endl;

    for(int i=0;i<50;i++) mapp[i][i] = 'N';

    for(int i=0;i<25;i++) {
        int x = rand() % 50;
        int y = rand() % 50;
        mapp[x][y] = mapp[y][x] = 'N';
    }

    for(int i=0;i<50;i++) {
        cout << mapp[i];
        if(i+1 < 50) cout << ",";
    }
    cout << endl;
}
