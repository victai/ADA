#include <stdio.h>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

static int N, M;

long long int ans = 0;

struct Edge{
    int a;
    int b;
    int weight;
    int walked;
};

int find(int x, int p[]){
    return x == p[x] ? x : (p[x] = find(p[x], p));
}
void Union(int x, int y, int p[]){
    p[find(x, p)] = find(y, p);
}

int cmp(const void *a, const void* b){
    struct Edge *A = (struct Edge*)a;
    struct Edge *B = (struct Edge*)b;
    return A->weight > B->weight;
}

int main(void){
    scanf("%d%d", &N, &M);
    struct Edge edge[M];
    memset(edge, 0, sizeof(edge));
    for(int i = 0; i < M; i++)
        scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].weight);

    qsort(edge, M, sizeof(struct Edge), cmp);
    int p[N];
    for(int i = 0; i < N; i++)
        p[i] = i;
    for(int i = 0, j = 0; i < N-1 && j < M; ++i){
        while (find(edge[j].a, p) == find(edge[j].b, p)){
            j++;
        }
        edge[j].walked = 1;
        Union(edge[j].a, edge[j].b, p);
        ans += edge[j].weight;
        j++;
    }
    int flag = 0;
    for(int i = 0; i < M; i++){
        if(!edge[i].walked){
            if(flag && edge[i].weight >= 0)    break;
            // if(edge[i].weight < 0){
            ans += edge[i].weight;
            flag = 1;
                // continue;
            // }
            // min = edge[i].weight;
            // break;
        }
    }
    // if(!flag)   min = edge[N-1].weight;
    printf("%lld\n", ans);
    return 0;
}
