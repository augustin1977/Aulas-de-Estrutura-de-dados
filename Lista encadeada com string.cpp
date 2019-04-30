#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
typedef struct l{
	char letras[30];
	struct l *prox;
} l;
void inclui(l lista[],char nome[], int n){
	strcpy(lista[n].letras,nome);
	if (n==MAX-1) {
		lista[n].prox=NULL;
	}
	else {
		lista[n].prox=&lista[n+1];
	}
}

void imprime(l *end){
	l lista;
	while(end!=NULL){
		strcpy(lista.letras,end->letras);
		end=end->prox;
		printf("%s\n",lista.letras);
	}
}
int main(){
	int i,n;
	l lista[MAX]; 
	char nome[30];
	for(i=0;i<MAX;i++){
	printf("Digite uma string:\n");
	scanf("%s",&nome);
	inclui(lista,nome,i);	
	}
	printf("Imprimindo String\n");
	imprime(&lista[0]);
	return 0;
}
