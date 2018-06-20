#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <assert.h>

int N, M, K, cnt = 0;
struct Tree{
	struct Tree *parent = NULL;
	int AID = 0;
	int cannot = 0;
	int following_cannot = 0;
	int been = 0;
};
struct Tree tree[100001], *tmp;

struct Depth{
	int index;
	int d = 0;
};
struct Depth depth[100001], *ptr;

bool cmp(Depth A, Depth B){	return (A.d > B.d); }

void Greedy(struct Tree *Node, int k){
	// printf("index = %lu k = %d\n", Node - &tree[0], k);
	if(!Node)	return;
	if(k < 0){
		printf("-1\n");
		exit(0);
	}
	if(Node->been){
	// printf("------RETURNED------\n");
		return;	
	}
	else if(!Node->cannot){
		if(!Node->parent){
			Node->AID = 1;
			cnt++;
			Node->been = 1;
			// printf("cnt++-----1\n");
			return;
		}
		else if(Node->following_cannot >= k){
			Node->AID = 1;
			cnt++;
			Node->been = 1;
			// printf("cnt++-----2\n");
			return;
		}
		else{
			Node->been = 1;
			// if(Node->parent->AID)	return;
			Greedy(Node->parent, k-1);
		}
	}
	else{
		Node->been = 1;
		Greedy(Node->parent, k-1);
	}
	return;
}

int main(void){
	scanf("%d%d%d", &N, &M, &K);
	int p, m;
	depth[1].d = 1, depth[1].index = 1;
	for(int i = 2; i <= N; i++){
		scanf("%d", &p);
		tree[i].parent = tree + p;
		depth[i].d += depth[p].d + 1;
		depth[i].index = i;
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
	std::sort(&depth[1], &depth[N+1], cmp);
	for(int i = 1; i <= N; i++){
		tmp = tree[depth[i].index].parent;
		if(tree[depth[i].index].cannot)	continue;
		while(tmp != NULL){
			if(tree[depth[i].index].following_cannot > K){
				printf("-1\n");
				return 0;
			}
			if(tmp->cannot){
				tree[depth[i].index].following_cannot++;
				tmp = tmp->parent;
			}
			else	break;
		}
	}
	ptr = &depth[1];
	for(int i = 0; i < N; i++){
	    if(tree[(ptr+i)->index].parent && tree[(ptr+i)->index].parent->AID)    continue;
		Greedy(&tree[(ptr+i)->index], K);
	}
	printf("%d\n", cnt);
	return 0;
}