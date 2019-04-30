#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10
typedef struct soldados{// definição da struct
	int numero; // numero do soldado
	int status; // verifica se é ativo 1 é ativo 0 é inativo 
	//struct soldado *prox; // ponteiro para a struct, endereço do proximo item
} soldado;

void inclui(soldados s[], int n){ 
//pre: recebe a lista de soldados vazia e o numero de soldados a preencher
//pos: retorna a list preenchida e com status 1
	int i;
	for (i=0;i<MAX;i++){
		s[i].numero=i;
		if (i<n) {
			s[i].status=1;
		}
		else {
			s[i].status=0;
		}
		
	}	
}
int exclui (soldados s[], int inicio, int sorteio){
//pre: recebe a lista de soldados preenchida o valor a valor sorteado para retirar um soldado
//pos: retorna a list preenchida e com 0 no status do soldado sorteado
	int i=0,j=inicio;
	printf("inicio=%d contagem=%d\n", inicio,sorteio);
	while(i<sorteio){
		if (s[j].status==1) {
			i++;
		}
		j++;
		if (j>=MAX) j=0;
	}
	//if (i>0) j--;
	while(s[j].status==0){
		j++;
		if (j>=MAX) j=0;
	}
	s[j].status=0;
	printf("Sai o soldado %d\n",s[j].numero);
	return j+1;
}
void imprime(soldado s[],int n){
//pre: recebe a lista de soldados preenchida e o numero de soldados
//pos: imprime a lista de soldados com respectivo status
	int i;
	printf("-----Lista de soldados-----\n");
	for (i=0;i<n;i++){
		printf(" %02d %d\n",s[i].numero,s[i].status);
	}
	printf("\n");
}
int numeroAtivo(soldado s[]){
	int i,j=0;
	for (i=0;i<MAX;i++){
		if (s[i].status==1) j++;
	}
	return j;
}
int main(){
	soldados s[MAX]; // declaração da lista  de soldados
	int pos,n,n2,i;
	n2=10;
	printf("Soldados escolhidos!\n");
	inclui(s,n2);
	imprime(s,n2);
	srand( (unsigned)time(NULL) );
	pos=rand()%(n2-1);
	for (i=0;i<n2-1;i++){
		n=rand()%9;
		//n=0;
		pos=exclui(s,pos,n);
		imprime(s,n2);
		printf("registros ativos - %d\n",numeroAtivo(s));
	}
	
}

