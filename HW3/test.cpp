#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;

int N, M;
long long int ans = 0;

struct Edge{
    int a;
    int b;
    long long int weight;
    // int walked;
    bool operator<(const struct Edge &tmp) const{
        return weight > tmp.weight;
    }
};

struct Vertex{
    int adjacent;
    int walked;
    long long int weight;
};

struct Vertex matrix[15000][15000];
int main(void){
    scanf("%d%d", &N, &M);
    priority_queue<struct Edge> edge;
    struct Vertex **matrix = (struct Vertex**)malloc(N*sizeof(void*));
    struct Vertex *pData = (struct Vertex*)malloc(N*N*sizeof(struct Vertex));
    for(int i = 0; i < N; i++, pData += N*sizeof(struct Vertex))
     matrix[i] = pData;
    struct Vertex **matrix = (struct Vertex**)malloc(N*sizeof(struct Vertex*) + N*N*sizeof(struct Vertex));
    struct Vertex matrix[1000][1000];
    memset(matrix, 0, sizeof(matrix));
    int a, b;
    long long c;
    for(int i = 0; i < M; i++){
        scanf("%d%d%lld", &a, &b, &c);
        matrix[a][b].adjacent = 1;
        matrix[a][b].weight = c;
        matrix[b][a].adjacent = 1;
        matrix[b][a].weight = c;
    }
    long long ans = 0;
    int visited[11000] = {0};
    visited[0] = 1;
     int flag = 0;
    long long min = 100000000000;
    int start = 0;
    int cnt = 1;
    while(cnt < N){
        for(int i = 0; i < N; i++){
         if(i != start && matrix[start][i].adjacent){
             if(!visited[i]){
                 struct Edge X;
                 X.a = start, X.b = i, X.weight = matrix[start][i].weight;
                 printf("%d %d %lld\n", start, i, matrix[start][i].weight);
                 edge.push(X);
             }
             else{
                 if(!matrix[start][i].walked){
                     if(matrix[start][i].weight < min){
                         flag = 1;
                         min = matrix[start][i].weight;
                         printf("min = %lld\n", min);
                     }
                 }
             }
         }
        }
        while(1){
         struct Edge tmp = edge.top();
         if(visited[tmp.b]){
             if(tmp.weight < min){
                 flag = 1;
                 min = tmp.weight;
             }
             edge.pop();
         }
         else{
             start = tmp.b;
             ans += tmp.weight;
             printf("add: %lld\n", tmp.weight);
             edge.pop();
             cnt++;
             visited[tmp.b] = 1;
             matrix[tmp.a][tmp.b].walked = 1;
             matrix[tmp.b][tmp.a].walked = 1;
             break;
         }
        }
    }
    if(!flag){
     struct Edge tmp2 = edge.top();
     min = tmp2.weight;
    }
    printf("%d\n", cnt);
    printf("%lld\n", min);
    printf("%lld\n", ans + min);
    return 0;
}
