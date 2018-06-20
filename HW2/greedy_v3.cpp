#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int N, M, K, cnt = 0;
struct Tree{
	struct Tree *parent = NULL;
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
	if(K == 0){
		if(M)	printf("-1\n");
		else	printf("%d\n", N);
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
	// for(int i = 1; i <= N; i++){
	// 	printf("depth: %d cannot: %d\n", depth[i].index, tree[depth[i].index].following_cannot);
	// }
	ptr = &depth[1];
	struct Tree *Node;
	for(int i = 0; i < N; i++){
		int idx = (ptr+i)->index;
		Node = &tree[idx];
		if(Node->been)	continue;
		int k = K;
		while(true){
			// printf("index = %lu k = %d\n", Node - &tree[0], k);
			if(k < 0){
				printf("-1\n");
				return 0;
			}
			if(Node->been){
				// printf("------RETURNED------\n");
				break;
			}
			if(!Node)	break;
			if(!Node->cannot){
				if(!Node->parent){
					// printf("cnt++-----1\n");
					cnt++;
					Node->been = 1;
					break;
				}
				else if(Node->following_cannot >= k){
					cnt++;
					// printf("cnt++-----2\n");
					Node->been = 1;
					break;
				}
				else{
					Node->been = 1;
					Node = Node->parent;
					k--;
				}
			}
			else{
				Node->been = 1;
				Node = Node->parent;
				k--;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}