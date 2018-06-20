#include <bits/stdc++.h>

int cnt = 1;

void Hanoi(int n, char src[100], char buffer[100], char dest[100])
{
	if(n == 1)
		printf("%d: move #%d disk from rod %s to rod %s\n", cnt++, n, src, dest);
	else
	{
		Hanoi(n-1, src, dest, buffer);
		printf("%d: move #%d disk from rod %s to rod %s\n", cnt++, n, src, dest);
		Hanoi(n-1, buffer, src, dest);
	}
	return;
}

int main(void)
{
	int n, T = 2;
	char a[100], b[100], c[100];
	scanf("%d %s %s %s", &n, a, b, c);
	for(int i = 1; i < n; i++)	T *= 2;
	printf("%d\n", T-1);
	Hanoi(n, a, b, c);
	return 0;
}