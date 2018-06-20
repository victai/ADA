#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

#define NORMAL 0
#define HAPPY 1

struct Road{
	int dest;
	int special;
};
struct Road road;

struct Visit{
	int mood[2];
	int scc[2];
};
struct Visit visit[10001];

int n, m, cnt, start;
vector<struct Road> forw[10001], backward[10001];
int counted[10001];

int DFS(int now, int mood){
	// printf("=====================\n");
	// printf("now = %d\n", now);
	if(now == start && mood == HAPPY && visit[start].mood[HAPPY]){
		visit[start].scc[HAPPY] = 1;
		// printf("return!!\n");
		return 1;
	}
	if(mood == HAPPY){
		// printf("HAPPY\n");
		int size = backward[now].size();
		for(int i = 0; i < size; i++){
			int dest = backward[now][i].dest;
			// printf("now: %d dest = %d\n", now, dest);
			if(backward[now][i].special){
				if(visit[dest].mood[NORMAL]){
					// printf("%d visited %d : NORMAL\n", now, dest);
					if(visit[dest].scc[NORMAL]){
						// printf("NORMAL %d is scc\n", dest);
						if(counted[now])	continue;
						visit[now].scc[HAPPY] = 1;
						cnt++;
						counted[now] = 1;
						// printf("add %d!!!!!\n", now);
					}
					continue;
				}
				visit[dest].mood[NORMAL] = 1;
				if(DFS(backward[now][i].dest, NORMAL)){
					if(counted[now])	continue;
					visit[now].scc[HAPPY] = 1;
					cnt++;
					counted[now] = 1;
					// printf("add %d!!!!!\n", now);
				}
			}
			else{
				if(visit[dest].mood[HAPPY]){
					// printf("%d visited %d : HAPPY\n", now, dest);
					if(visit[dest].scc[HAPPY]){
						// printf("HAPPY %d is scc\n", dest);
						if(counted[now])	continue;
						visit[now].scc[HAPPY] = 1;
						cnt++;
						counted[now] = 1;
						// printf("add %d!!!!!\n", now);
					}
					continue;
				}
				visit[dest].mood[HAPPY] = 1;
				if(DFS(backward[now][i].dest, HAPPY)){
					if(counted[now])	continue;
					visit[now].scc[HAPPY] = 1;
					cnt++;
					counted[now] = 1;
					// printf("add %d!!!!!\n", now);
				}
			}
		}
		// printf("after visit\n");
		// printf("%d happy\n", now);
		if(visit[now].scc[HAPPY]){
			if(!counted[now]){
				// printf("add %d!!!!!\n", now);
				cnt++;
			}
			counted[now] = 1;
			return 1;
		}
		else	return 0;
	}
	else{
		// printf("NORMAL\n");
		int size = forw[now].size();
		for(int i = 0; i < size; i++){
			int dest = forw[now][i].dest;
			// printf("now: %d dest = %d\n", now, dest);
			if(forw[now][i].special){
				if(visit[dest].mood[HAPPY]){
					// printf("%d visited %d : HAPPY\n", now, dest);
					if(visit[dest].scc[HAPPY]){
						// printf("HAPPY %d is scc\n", dest);
						if(counted[now])	continue;
						visit[now].scc[NORMAL] = 1;
						cnt++;
						counted[now] = 1;
						// printf("add %d!!!!!\n", now);
					}
					continue;
				}
				visit[dest].mood[HAPPY] = 1;
				if(DFS(forw[now][i].dest, HAPPY)){
					if(counted[now])	continue;
					visit[now].scc[NORMAL]= 1;
					cnt++;
					counted[now] = 1;
					// printf("add %d!!!!!\n", now);
				}
			}
			else{
				if(visit[dest].mood[NORMAL]){	
					// printf("%d visited %d : NORMAL\n", now, dest);
					if(visit[dest].scc[NORMAL]){
						// printf("NORMAL %d is scc\n", dest);
						if(counted[now])	continue;
						visit[now].scc[NORMAL] = 1;
						cnt++;
						counted[now] = 1;
						// printf("add %d!!!!!\n", now);
					}
					continue;
				}
				visit[dest].mood[NORMAL] = 1;
				if(DFS(forw[now][i].dest, NORMAL)){
					if(counted[now])	continue;
					visit[now].scc[NORMAL] = 1;
					cnt++;
					counted[now] = 1;
					// printf("add %d!!!!!\n", now);
				}
			}
		}
		// printf("after visit\n");
		// printf("%d normal\n", now);
		if(visit[now].scc[NORMAL]){
			if(!counted[now]){
				// printf("add %d!!!!!\n", now);
				cnt++;
			}
			counted[now] = 1;
			return 1;
		}
		else	return 0;
	}
	return 0;
}

int main(void){
	scanf("%d%d", &n, &m);
	int a, b, s;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &s);
		road.dest = b, road.special = s;
		forw[a].push_back(road);
		road.dest = a, road.special = s;
		backward[b].push_back(road);
	}

	for(start = 1; start <= n; start++){
		memset(visit, 0, sizeof(visit));
		memset(counted, 0, sizeof(counted));
		counted[start] = 1;
		cnt = 1;
		DFS(start, HAPPY);
		printf("%d\n", cnt);	
	}

	return 0;
}