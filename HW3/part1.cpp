#include <stdio.h>

int V;

int matrix[300][300] = {{0}};

void warshall(){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			for(int k = 0; k < V; k++){
				if(matrix[j][i] && matrix[i][k]){
					matrix[j][k] += matrix[j][i]*matrix[i][k];
					matrix[j][k] %= 10;
				}
			}
		}
	}
}

int main(void){
	scanf("%d", &V);
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			scanf("%d", &matrix[i][j]);
	warshall();
	
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			printf(j == V-1?"%d\n":"%d ", matrix[i][j]);
	return 0;
}