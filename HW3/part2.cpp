#include <stdio.h>

int V;
int matrix[300][300];

int Input() {  
    char cha;  
    unsigned int x = 0;  
    while(cha = getchar())  
        if(cha != ' ' && cha != '\n' || cha == EOF) break;  
    if(cha == EOF) return -1; 
    x = cha-48;  
    while(cha = getchar()) {  
        if(cha == ' ' || cha == '\n') break;  
        x = x*10 + cha-48;  
    }  
    return x;  
}

void warshall(){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			for(int k = 0; k < V; k++){
				if(matrix[j][i] && matrix[i][k]){
					matrix[j][k] -= matrix[j][i]*matrix[i][k];
					while(matrix[j][k] < 0)
						matrix[j][k] += 10;
				}
			}
		}
	}
}

int main(void){
	scanf("%d", &V);
	int tmp = V*V, cnt = 0;
	while(cnt < tmp){
		matrix[cnt/V][cnt%V] = Input();
		cnt++;
	}
	warshall();
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			printf((j == V-1)?"%d\n":"%d ", matrix[i][j]);
	return 0;
}