#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define NORMAL 0
#define HAPPY 1

int n, m;

int visit[20001] = {0}, low[20001], t = 0;
int stack[20001], top = 0;
bool instack[20001];
int contract[20001];
int ans[20001] = {0};

vector<int> go[20001];

void DFS(int cur)
{
   	visit[cur] = low[cur] = ++t;
	stack[top++] = cur;
	instack[cur] = true;
	int size = go[cur].size();
    for (int i = 0; i < size; ++i){
    	int dest = go[cur][i];
   		if(!visit[dest]) DFS(dest);
   		if(instack[dest])
			low[cur] = min(low[cur], low[dest]);
    }  
    if(visit[cur] == low[cur]){
    	int j;
    	do{
    		j = stack[--top];
    		instack[j] = false;
    		contract[j] = cur;
    		ans[cur]++;
    	}while(j != cur);
    }
}

void tarjan(){
	for(int i = 1; i <= n; i++)
		if(!visit[i])
			DFS(i);
}

int main(void){
	scanf("%d%d", &n, &m);
	int a, b, s;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &s);
		if(s){
			go[a+n].push_back(b);
			go[b].push_back(a+n);
		}
		else{
			go[a+n].push_back(b+n);
			go[b].push_back(a);
		}
	}

	tarjan();
	for(int i = 1; i <= n; i++){
		if(contract[i] == contract[i+n])	ans[contract[i]]--;
	}
	for(int i = 1; i <= n; i++)
		printf("%d\n", ans[contract[i]]);
	return 0;
}