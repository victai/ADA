#include <stdio.h>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <list>
using namespace std;

#define INF INT_MAX

int N, M, A, B;

struct Vertex{
	int parent;
	int number;
	int layer;
};
struct Vertex vertex;

queue<struct Vertex> Q;
int Dis[100001] = {0};
vector<int> conn[100001];
list<int> visit;

bool cmp(int i, int j){	return(i < j);}

void BFS(){
	while(Q.size()){
		struct Vertex now = Q.front();
		int num = now.number;
		if(A*now.layer < Dis[num] || num == 1){
			Dis[num] = A*now.layer;
			int size = conn[num].size();
			if(A*(now.layer+1) < B){
				for(int i = 0; i < size; i++){
					vertex.parent = num;
					vertex.number = conn[num][i];
					vertex.layer = now.layer+1;
					if(vertex.number == now.parent)	continue;
					if(A*vertex.layer > Dis[vertex.number])	continue;
					Q.push(vertex);
				}
			}
		}
		Q.pop();
	}
}
void BFS2(){
	while(Q.size()){
		struct Vertex now = Q.front();
		int num = now.number;
		if(B*now.layer < Dis[num] || num == 1){
			Dis[num] = B*now.layer;
			if(B*(now.layer+1) < A){	
				int tmp = 0;
				list<int>::iterator it;
				for(it = visit.begin(); it != visit.end(); it++){
					while(tmp < conn[num].size() && *it > conn[num][tmp])	tmp++;
					if(tmp < conn[num].size() && *it == conn[num][tmp]){
						tmp++;
						continue;
					}
					vertex.parent = num;
					vertex.number = *it;
					vertex.layer = now.layer+1;
					visit.erase(it);
					it--;
					if(vertex.number == now.parent)	continue;
					if(B*vertex.layer >= Dis[vertex.number])	continue;
					Q.push(vertex);
				}
			}
		}
		Q.pop();
	}
}

int main(void){
	scanf("%d%d%d%d", &N, &M, &A, &B);
	int a, b;
	int flag = 0;
	for(int i = 2; i <= N; i++)
		Dis[i] = B;
	for(int i = 0; i < M; i++){
		scanf("%d%d", &a, &b);
		if(B/A >= 2){
			conn[a].push_back(b);
			conn[b].push_back(a);
		}
		else if(A/B >= 2){
			flag = 1;
			conn[a].push_back(b);
			conn[b].push_back(a);
		}
		else{
			if(a == 1)	Dis[b] = A;
			if(b == 1)	Dis[a] = A;
			flag = 2;
		}
	}
	vertex.parent = 1;
	vertex.number = 1;
	vertex.layer = 0;
	Q.push(vertex);
	if(flag == 2){
		for(int i = 1; i <= N; i++)
			printf("%d ", Dis[i]);
		puts("");
		return 0;
	}
	else if(flag == 1){
		for(int i = 1; i <= N; i++){
			Dis[i] = A;
			sort(conn[i].begin(), conn[i].end(), cmp);
			visit.push_back(i);
		}
		BFS2();
	}
	else{
		for(int i = 1; i <= N; i++){
			Dis[i] = B;
		}
		BFS();
	}
	for(int i = 1; i <= N; i++)
		printf("%d ", Dis[i]);
	puts("");
return 0;
}