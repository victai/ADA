#include <stdio.h>
#include <algorithm>

int DP[101][101] = {{0}};

int W(int n, int k){
	if(n == 1)	return k;
	if(k <= 1)	return 1;
	if(DP[n][k])	return DP[n][k];
	int min = k;
	for(int i = 1; i < k; i++){
		min = std::min(min,std::max(W(n, k-i), W(n-1, i-1)) + 1);
		// printf("DP[%d][%3d] = max( DP[%d][%3d] = %3d --- DP[%d][%3d] = %3d )\n", n, k, n, k-i, DP[n][k-i], n-1, i-1, DP[n-1][i-1]);
		// if(tmp < min)	min = tmp;
	}
	DP[n][k] = min;
	return min;
}

int main(void){
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n",W(n, k));
	// printf("%d\n", DP[n][k]);
	// for(int i = 0; i < 4; i++){
	// 	for(int j = 0; j <= 10; j++)
	// 		printf("%d ", DP[i][j]);
	// 	puts("");
	// }
	return 0;
}