#include <stdio.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

int v, e;
vector<int> dest[100001];
int visit[100001] = {0};
int ans = 0;
vector<int> longest;
int timeout = 0;
time_t t1, t2;
int deg[100001];

void DFS(int node, int depth, vector<int> path){
	path.push_back(node);
	time(&t2);
	if(t2 - t1 > 3.99){
		timeout = 1;
		return;
	}
	visit[node] = 1;
	if(depth > ans){
		ans = depth;
		longest = path;
	}
	int size = dest[node].size();
	for(int i = 0; i < size; i++){
		if(!visit[dest[node][i]]){
			DFS(dest[node][i], depth+1, path);
		}
	}
}

int main(void){
	time(&t1);
	scanf("%d%d", &v, &e);
	int a, b;
	for(int i = 0; i < e; i++){
		scanf("%d%d", &a, &b);
		dest[a].push_back(b);
		dest[b].push_back(a);
	}
	vector<int> nothing;
	for(int i = 0; i < v; i++){
		memset(visit, 0, sizeof(visit));
		nothing.clear();
		DFS(i, 1, nothing);
		if(timeout)	break;
	}
	printf("%d\n", ans);
	for(int i = 0; i < longest.size(); i++)
		printf("%d ", longest[i]);
	puts("");
	// printf("%d\n", ans);
	// for(int i = 0; i < arr[ans_node].path.size(); i++)
	// 	printf("%d ", arr[ans_node].path[i]);
	// puts("");
	return 0;
}