#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int N, M, K, cnt = 0;
struct Tree{
	struct Tree *parent = NULL;
	int AID = 0;
	int cannot = 0;
};
struct Tree tree[100001], *tmp;
int leaf[100001] = {0};

void Greedy(struct Tree *Node, int k){
	if(!Node)	return;
	tmp = Node->parent;
	int tmp_k = 0;
	printf("index = %lu k = %d\n", Node - &tree[0], k);
	while(tmp != NULL){
		if(tmp_k > K){
			printf("-1\n");
			exit(0);
		}
		if(!tmp->cannot)	break;
		else{
			tmp_k++;
			tmp = tmp->parent;
		}	
	}
	printf("tmp_k = %d k = %d\n", tmp_k, k);
	if(Node->AID)	return;
	else if(!Node->cannot){
		if(!Node->parent){
			Node->AID = 1;
			cnt++;
			printf("cnt++-----1\n");
			return;
		}
		if(tmp_k >= k){
			Node->AID = 1;
			cnt++;
			printf("cnt++-----2\n");
			Greedy(tmp, K-tmp_k);
		}
		else	Greedy(Node->parent, k-1);
	}
	else	Greedy(Node->parent, k-1);
	return;
}

int main(void){
	scanf("%d%d%d", &N, &M, &K);
	int p, m;
	for(int i = 2; i <= N; i++){
		scanf("%d", &p);
		tree[i].parent = tree + p;
		leaf[p] = 1;
	}
	for(int i = 0; i < M; i++){
		scanf("%d", &m);
		if(m == 1){
			printf("-1\n");
			return 0;
		}
		tree[m].cannot = 1;
	}
	if(K == 0 && M){
		printf("-1\n");
		return 0;
	}
	if(tree[1].cannot){
		printf("-1\n");
		return 0;
	}
	for(int i = 2; i <= N; i++)
		if(!leaf[i])
			Greedy(&tree[i], K);
	printf("%d\n", cnt);
	return 0;
}