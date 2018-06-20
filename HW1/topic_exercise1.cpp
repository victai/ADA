#include <bits/stdc++.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	long long int array[n] = {0};
	for(int i = 0; i < n; i++)
		scanf("%lld", &array[i]);
	long long int min = 0;
	long long int max = array[0];
	long long int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += array[i];
		if(sum - min > max)	max = sum - min;
		if(sum < min)	min = sum;
	}
	printf("%lld\n", max);
	return 0;
}