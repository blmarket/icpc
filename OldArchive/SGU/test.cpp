#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
    srand(time(NULL));

    while(true)
    {
        cout << "case 1" << endl;
        ofstream fout("inp442");
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<50000;j++)
                fout << (rand()%10);
            fout << endl;
        }
        fout << 0 << endl;
        fout.close();

        system("442 < inp442 > r1");
        system("442c < inp442 > r3");

        ifstream fin1("r1");
        ifstream fin2("r3");

        for(int i=0;i<100;i++)
        {
            long long t1,t2;
            fin1 >> t1;
            fin2 >> t2;
            if(t1 != t2)
            {
                return 0;
            }
        }
        fin1.close();
        fin2.close();
    }
}
