#include <cstdio>
#include "TwistedGame.cpp"

using namespace std;

int main(void)
{
    TwistedGame inst;
    int N;
    int tile[8];
    scanf("%d", &N);
    for(int i=0;i<8;i++) scanf("%d", &tile[i]);

    inst.init(N, tile);

    for(int j=0;j<N;j++)
    {
        cerr << "turn " << j << " " << N << endl;
        for(int i=0;i<8;i++)
            if(scanf("%d", &tile[i]) == 0) return 0;
        cerr << "turn " << j << " " << N << endl;
        string ret = inst.placeTile(tile);
        printf("%s\n",ret.c_str());
        fflush(stdout);
    }
}
