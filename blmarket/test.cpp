#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int worst[256];

string bits(int a)
{
    string ret;
    for(int i=0;i<8;i++)
    {
        ret += '0' + (a & 1);
        a>>=1;
    }
    return ret;
}

int main(void)
{
    memset(worst, -1, sizeof(worst));
    worst[255] = 0;

    bool flag = false;
    while(1)
    {
        flag = false;
        for(int i=0;i<256;i++)
        {
            if(worst[i] != -1) continue;
            flag=true;
            for(int j=0;j<256;j++)
            {
                int maxx = -1;
                for(int k=0;k<8;k++)
                {
                    int tmp = ((j & ((1<<k)-1)) << (8-k)) | (j >> k);
                    int tmp2 = i ^ tmp;

                    if(worst[tmp2] == -1) 
                    {
                        maxx = 9999;
                        break;
                    }

                    maxx = max(maxx, worst[tmp2]);
                }
                if(maxx == 9999) continue;
                worst[i] = maxx+1;
                cout << bits(i) << " => apply : " << bits(j) << " : " << maxx+1 << endl;
                break;
            }
        }
        if(flag == false) break;
    } 

    return 0;
}
