#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void estatica(int vetor[10],int n){
	int i ,matriz[n];
	for(i=0;i<n;i++){
		matriz[i]=vetor[i];
	}
	for (i=0;i<n;i++){
		printf("%d) %d - %p\n",i,matriz[i],&matriz[i]);
	}
}
void dinamica(int vetor[],int n){
	int i=0;
	int *j;
	j=&vetor[i];
	while(i<n){
		printf("%d) %d - %p\n",i,*j,j);
		i++;
		j=&vetor[i];	
	}
}
void sequencial(int vetor[],int n){
	int i=0;
	int *j;
	j=&vetor[i];
	while(i<n){
		printf("%d) %d - %p\n",i,*j,j);
		i++;
		j++;	
	}
}
void encadeada(int vetor[], int n){
	int i=0;
	int matriz[n+1][2];
	for(i=0;i<n;i++){
		matriz[i][0]=vetor[i];
		matriz[i][1]=&matriz[i+1][0];
	}
	for(i=0;i<n;i++){
		printf("%d) %d - %p\n",i,matriz[i][0],matriz[i][1]);
	}
}
int main(){

	int v[10]={1,3,5,2,1,0};
	int n=6;
	printf("Estatica\n");
	estatica(v,n);
	printf("Dinamica\n");
	dinamica(v,n);
	printf("Sequencial\n");
	sequencial(v,n);
	printf("Encadeada\n");
	encadeada(v,n);
	return 0;
}
