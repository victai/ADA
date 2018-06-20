#include <bits/stdc++.h>

#define mod 1000000007
#define max 131074
int N;
long long int cnt[max] = {1};
long long int tmp[max] = {1};

void PMGO(int A[], int floor)
{
	if(floor == N)	return;
	for(int i = 0; i <= floor+1; i++)
		tmp[i] = cnt[i];
	for(int i = 1; i <= floor+1; i++)
	{
		cnt[i] += tmp[i-1] * A[floor] % mod;
		cnt[i] %= mod;
	}
	PMGO(A, floor+1);
}

int main(void)
{
	scanf("%d", &N);
	int A[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	PMGO(A, 0);
	printf("0 ");
	for(int i = 0; i <= N; i++)
		printf("%lld ", cnt[i]);
	return 0;
}