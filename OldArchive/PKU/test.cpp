#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
    srand(time(NULL));
    while(true)
    {
        int n = rand() % 100000;
        cout << n << endl;
        ofstream fout("input");
        int m = 100;
        fout << n << " " << m << endl;
        for(int i=0;i<n;i++)
        {
            fout << rand()%100000 << " " << rand()%100000 << " " << rand()%100000 << endl;
        }
        for(int i=0;i<m;i++)
        {
            fout << rand()%100000 << " " << rand()%100000 << endl;
        }
        fout.close();

        system("3689 < input > result1");
        cout << "done a" << endl;
        system("LPsolve < input > result2");
        cout << "done b" << endl;

        ifstream fin1("result1");
        ifstream fin2("result2");
        string str1,str2;
        for(int i=0;i<m;i++)
        {
            fin1 >> str1;
            fin2 >> str2;
            if(str1 != str2)
            {
                return 0;
            }
        }
        fin1.close();
        fin2.close();
    }
}
