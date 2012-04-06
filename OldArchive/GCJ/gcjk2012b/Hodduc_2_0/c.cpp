#include<stdio.h>
#include<memory.h>
#define MOD 32749
int d[2005][2005], T, B, W, N, J;
int comb[2005][2005];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, i, j, k;

	comb[0][0] = 1;
	comb[1][0] = comb[1][1] = 1;
	for(i = 2; i <= 2000; i++){
		comb[i][0] = comb[i][i] = 1;
		for(j = 1; j < i; j++) comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
	}

	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		scanf("%d %d %d %d", &B, &W, &N, &J);
		if(B-J+1 >= 0 && W-J+1 >= 0 && B-J+1 + W-J+1 == N-J){
			// impossible
			printf("Case #%d: 0\n", t);
			continue;
		}
		if(N-J < B-J+1 && N-J < W-J+1){
			// impossible
			printf("Case #%d: 0\n", t);
			continue;
		}
		memset(d, 0, sizeof(d));
		if(B-J+1 >= 0 && N-J >= B-J+1){
			d[B-J+1][(N-J)-(B-J+1) + 1] += comb[N-J][B-J+1];
			d[B-J+1][(N-J)-(B-J+1) + 1] %= MOD;
		}
		if(W-J+1 >= 0 && N-J >= W-J+1){
			d[(N-J)-(W-J+1) + 1][W-J+1] += comb[N-J][W-J+1];
			d[(N-J)-(W-J+1) + 1][W-J+1] %= MOD;
		}
		for(k = J - 1; k >= 2; k--)
		{
			for(i = 0, j = (N - k); i <= N - k; i++, j--)
			{
				// 맞추면 안됨 이제!
				if(d[i][j] == 0) continue;
				if(i+1 <= B && (i+1) < B-(k-1)+1 && j < W-(k-1)+1){
					d[i+1][j] += d[i][j];
					if(d[i+1][j] > MOD) d[i+1][j] -= MOD;
				}
				if(j+1 <= W && i < B-(k-1)+1 && (j+1) < W-(k-1)+1){
					d[i][j+1] += d[i][j];
					if(d[i][j+1] > MOD) d[i][j+1] -= MOD;
				}
			}
		}
		for(; k >= 1; k--){
			for(i = 0, j = (N - k); i <= N - k; i++, j--)
			{
				if(i+1 <= B){
					d[i+1][j] += d[i][j];
					if(d[i+1][j] > MOD) d[i+1][j] -= MOD;
				}
				if(j+1 <= W){
					d[i][j+1] += d[i][j];
					if(d[i][j+1] > MOD) d[i][j+1] -= MOD;
				}
			}
		}
		int tot = 0;
		for(i = 0; i <= N; i++){
			tot += d[i][N-i];
			if(tot > MOD) tot -= MOD;
		}
		printf("Case #%d: %d\n", t, tot);
	}
	return 0;
}

/*
#include<stdio.h>
#include<memory.h>
#define MOD 32749
int d[2005][2005], T, B, W, N, J;
int tot;
int color[25];
void bt(int x){
	if(x == N+1){
		int b = 0, w = 0, i;

		for(i = 1; i <= N; i++)
		{
			if(color[i]) w++;
			else b++;
		}
		if(w > W || b > B) return;
		for(i = N; i >= 1; i--){
			if(color[i]) w--;
			else b--;

			if(b == B-(N-i) || w == W-(N-i)) break;
		}
		if((N-i+1) == J) tot ++;
		return;
	}
	color[x] = 0;
	bt(x+1);
	color[x] = 1;
	bt(x+1);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output_real.txt", "w", stdout);

	int t, i, j, k;

	scanf("%d", &T);
	for(t = 1; t <= T; t++){
		tot = 0;
		scanf("%d %d %d %d", &B, &W, &N, &J);
		bt(1);
		printf("Case #%d: %d\n", t, tot % 32749);
		fprintf(stderr, "%d\n", t);
	}
	return 0;
}*/