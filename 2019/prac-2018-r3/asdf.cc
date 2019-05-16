#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

struct point {ll x,y,z;};

ll volume(point O, point P, point Q, point R){
	ll A = P.x - O.x, B = P.y - O.y, C = P.z - O.z;
	ll D = Q.x - O.x, E = Q.y - O.y, F = Q.z - O.z;
	ll G = R.x - O.x, H = R.y - O.y, I = R.z - O.z;
	return A*E*I - A*F*H - B*D*I - C*E*G + B*F*G + C*D*H;
}
	
int N;
point P[20];
int f[20];
	
void main2(void){
	int i,j;
	
	cin >> N;
	REP(i,N) cin >> P[i].x >> P[i].y >> P[i].z;
	
	REP(i,N) f[i] = i;
	
	do {
		bool good = true;
		
		for(i=3;i<N;i++){
			point H = {P[f[i]].x, P[f[i]].y, 0ll};
			ll V1 = volume(P[f[i]], P[f[i-1]], P[f[i-2]], H);
			
			for(j=0;j<=i-3;j++){
				ll V = volume(P[f[i]], P[f[i-1]], P[f[i-2]], P[f[j]]);
                                cerr << i << ' ' << j << ' ' << V << ' ' << V1 << ' ' << f[i] << ' ' << f[i-1] << ' ' << f[i-2] << ' ' << f[j] << endl;
				if((V > 0) != (V1 > 0)){
					good = false;
					break;
				}
			}
			
			if(!good) break;
		}
		
		if(good){
			REP(i,N){
				printf("%d", f[i] + 1);
				if(i == N-1) printf("\n"); else printf(" ");
			}
			return;
		}
		
	} while(next_permutation(f, f+N));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
