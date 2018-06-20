#include <bits/stdc++.h>

typedef struct tree
{
	struct tree *left = NULL, *right = NULL;
	long long int cnt = 0;
}Tree;

Tree tree[1000000], *ptr = tree;
long long int N;
int K;
long long int x = 0;

int Count(Tree *node, int len)
{
		// printf("%lld\n", node->cnt);
	if(len == K)
	{
		x += node->cnt * (node->cnt-1) / 2 * (long long)len;
		return node->cnt;
	}
	else
	{
		long long int left_cnt = 0, right_cnt = 0;
		if(node->left != NULL)
			left_cnt = Count(node->left, len+1);
		if(node->right != NULL)	
			right_cnt = Count(node->right, len+1);
		// printf("%lld %lld %lld\n", node->cnt, left_cnt, right_cnt);
		x += left_cnt * right_cnt * len;
		return node->cnt;
	}
}

int main(void)
{
	//(Tree *)malloc(sizeof(Tree));
	ptr++;
	scanf("%lld %d", &N, &K);
	char s[N][K];
	for(int i = 0; i < N; i++)
	{
		Tree *root = &tree[0];
		scanf("%s", s[i]);
		for(int j = 0; j < K; j++)
		{
			if(s[i][j] == 'P')
			{
				if(!root->left)	root->left = ptr++;
				root->left->cnt++;
				root = root->left;
			}
			else if(s[i][j] == 'C')
			{
				if(!root->right)	root->right = ptr++;
				root->right->cnt++;
				root = root->right;
			}
		}
	}
	Count(&tree[0], 0);
	// printf("%lld %lld\n", x, (N*(N-1))/2);
	printf("%.10f\n", (double)x/(N*(N-1)/2));
	return 0;
}