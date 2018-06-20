#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
int N;
vector<long long> A;

vector<long long> Karatsuba(vector<long long> X, vector<long long> Y, int length)
{
	// printf("------------------------\n");
	// for(int i = 0; i < length; i++)
	// 	printf("X[%d]: %lld ", i, X[i]);
	// puts("");
	// for(int i = 0; i < length; i++)
	// 	printf("Y[%d]: %lld ", i, Y[i]);
	// puts("");
	// printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	vector<long long> mul(length<<1);
	// mul.reserve(2*length);
	if(length <= 64)
	{
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				mul[i+j] += X[i]*Y[j];
				mul[i+j] %= mod;
			}
		}
		return mul;
	}
	vector<long long> x1(X.begin(), X.begin()+length/2), x2(X.begin()+length/2, X.end());
	vector<long long> y1(Y.begin(), Y.begin()+length/2), y2(Y.begin()+length/2, Y.end());
	vector<long long> P1 = Karatsuba(x1, y1, length/2);
	vector<long long> P2 = Karatsuba(x2, y2, length/2);
	int size = x1.size();
	for(int i = 0; i < size; i++)
	{
		x1[i] += x2[i];//, x1[i] %= mod;
		y1[i] += y2[i];//, y1[i] %= mod;
		if(x1[i] >= mod) x1[i] -= mod;
		if(y1[i] >= mod) y1[i] -= mod;
	}
	vector<long long> P3 = Karatsuba(x1, y1, length/2);
	// for(int i = 0; i < length; i++)
	// 	printf("P1[%d]: %lld ", i, P1[i]);
	// puts("");
	// for(int i = 0; i < length; i++)
	// 	printf("P2[%d]: %lld ", i, P2[i]);
	// puts("");
	// for(int i = 0; i < length; i++)
	// 	printf("P3[%d]: %lld ", i, P3[i]);
	// puts("");
	// printf("size: %d\n", (int)mul.size());
	// printf("%lu %lu %lu\n", P1.size(), P2.size(), P3.size());
	for(int i = 0; i < length; i++)
	{
		mul[i] += P1[i];
		if(mul[i] >= mod) mul[i] -= mod;
		mul[i+length] += P2[i];
		if(mul[i+length] >= mod) mul[i+length] -= mod;
		mul[i+length/2] += P3[i];// - P1[i] - P2[i];
		if(mul[i+length/2] >= mod)	mul[i+length/2] -= mod;
		mul[i+length/2] -= P1[i];
		if(mul[i+length/2] < 0)	mul[i+length/2] += mod;
		mul[i+length/2] -= P2[i];
		if(mul[i+length/2] < 0)	mul[i+length/2] += mod;
		// mul[i] %= mod, mul[i+length] %= mod, mul[i+length/2] %= mod;
		// while(mul[i+length/2] < 0)	mul[i+length/2] += mod;
	}
	// for(int i = 0; i < mul.size(); i++)
	// 	printf("mul[%d]: %lld ", i, mul[i]);
	// puts("");
	return mul;
}

vector<long long> Divide(int index, int length)
{
	// printf("index:%d length:%d\n", index, length);
	vector<long long> X, Y, vec;
	if(length == 1)
	{
		// printf("A[%d]= %lld\n", index, A[index]);
		vec.push_back(1), vec.push_back(A[index]);
		return vec;
	}
	X = Divide(index, length/2);
	Y = Divide(index + length/2, length/2);
	// for(int i = 0; i < length; i++)
	// 	printf("X[%d]: %lld ", i, X[i]);
	// puts("");
	// for(int i = 0; i < length; i++)
	// 	printf("Y[%d]: %lld ", i, Y[i]);
	// puts("");
	return Karatsuba(X, Y, length);
}

int main(void)
{
	scanf("%d", &N);
	int x = 1;
	while(x < N)	x <<= 1;
	long long int a;
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &a);
		A.push_back(a);
	}
	for(int i = 0; i < x-N; i++)	A.push_back(0);
	vector<long long> ans = Divide(0, x);
	int size = ans.size();
	// printf("size: %d, x: %d\n", size, x);
	printf("0 ");
	for(int i = 0; i < size && ans[i]; i++)
		printf("%lld ", ans[i]);
	putchar('\n');
	return 0;
}