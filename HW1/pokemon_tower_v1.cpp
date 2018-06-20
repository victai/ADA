#include <bits/stdc++.h>

#define mod 1000000007
#define max 131074
int N;
long long int cnt[max];
long long int methods = 0;
int Chosen_floors[max] = {0};

void PMGO(int A[], int floor, int k, int flag)
{
	// printf("floor: %d k: %d, flag: %d\n", floor, k, flag);
	if(flag)	Chosen_floors[floor-1] = 1;
	else if(!flag)	{Chosen_floors[floor-1] = 0;}
	flag = 0;
	if(N - floor < k)	{return;}
	if(k == 0)
	{
		long long int a = 1;
		for(int i = 0; i < N; i++)
		{
			// printf("chosen[%d]: %d\n", i, Chosen_floors[i]);
			if(Chosen_floors[i])	a *= A[i];
			if(a > mod)	a %= mod;
		}
			// printf("a: %lld\n", a);
		methods += a;
		// memset(Chosen_floors, 0, 4*N);
		Chosen_floors[floor-1] = 0;
		return;
	}
	PMGO(A, floor+1, k, 0);
	PMGO(A, floor+1, k-1, 1);
}

int main(void)
{
	scanf("%d", &N);
	int A[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	printf("0 1 ");
	for(int i = 0; i < N; i++)
	{
		PMGO(A, 0, i+1, 0);
		printf("%lld ", methods % mod);
		methods = 0;
	}
	return 0;
}