#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10
typedef struct soldados{// definição da struct
	int numero; // numero do soldado
	int status; // verifica se é ativo 1 é ativo 0 é inativo 
} soldados;

void inclui(soldados s[], int n){ 
//pre: recebe a lista de soldados vazia e o numero de soldados a preencher
//pos: retorna a list preenchida e com status 1
	int i; // declara a vairaivel i
	for (i=0;i<MAX;i++){ // faz um loop para incluir todos os soldados
		s[i].numero=i; // insere o numero no capacete
		if (i<n) {
			s[i].status=1; // define status como ativo
		}
		else {
			s[i].status=0; // define o status com inativo 
		}	
	}	
}
int exclui (soldados s[], int inicio, int sorteio){
//pre: recebe a lista de soldados preenchida o valor a valor sorteado para retirar um soldado
//pos: retorna a list preenchida e com 0 no status do soldado sorteado
	int i=0,j=inicio;
	printf("inicio=%d contagem=%d\n", inicio,sorteio);
	while(i<sorteio){ // loop para contar as posições
		if (s[j].status==1) { // verifica se a posição é ativa, caso positivo conta
			i++;
		}
		j++; // passa para a proxima posição
		if (j>=MAX) j=0; // verifica se ja está na ultima posição e caso positivo retorna para a primeira
	}
	//if (i>0) j--;
	while(s[j].status==0){ // verifica se o registro a desativar ja não esta desativado, caso positivo vai para o proximo
		j++; // incrementa o contado
		if (j>=MAX) j=0; // se o contado chegar no valor maximo, retorna para a primeira posição
	}
	s[j].status=0; // define o status como inativo
	printf("Sai o soldado %d\n",s[j].numero); // imprime qual soldado saiu
	return j+1;// retorna o proximo soldado
}
void imprime(soldados s[],int n){
//pre: recebe a lista de soldados preenchida e o numero de soldados
//pos: imprime a lista de soldados com respectivo status
	int i;
	printf("\n-----Lista de soldados-----\n");
	for (i=0;i<n;i++){
		if (s[i].status==1) printf(" %02d\n",s[i].numero);
	}
	//printf("\n");
}
int numeroAtivo(soldados s[]){ 
//pre: Recebe a lista de soldados e conta quantos estão ativos
//pos: Retorna o numero de ativos
	int i,j=0;
	for (i=0;i<MAX;i++){
		if (s[i].status==1) j++;
	}
	return j;
}
int escolhido(soldados s[]){
	int i=0;
	while(s[i].status==0){
		i++;
	}
	return i;
}
int main(){
	soldados s[MAX]; // declaração da lista  de soldados
	int pos,n,n2,i; // declara variaves
	n2=10; // define o numero de soldados
	inclui(s,n2);// 
	printf("Soldados escolhidos!\n"); // informa que os soldados ja foram esclhidos
	imprime(s,n2); // imprime a lista de soldados
	printf("registros ativos - %d\n",numeroAtivo(s)); // conta e imprime o numero de soldados ativos
	printf("\n---------------------------\n");
	srand( (unsigned)time(NULL) ); // define o sorteio aleatório
	pos=rand()%(n2-1); // executa o sorteio da primeira posição
	for (i=0;i<n2-1;i++){ // faz o numero de soldados -1 sorteios, para que resto apenas 1
		n=rand()%9; // sorteia no numero que será contado
		//n=0;
		pos=exclui(s,pos,n); // esclui a posição sorteada + contagem
		imprime(s,n2); // imprime a lista atualizada de soldados
		printf("registros ativos - %d\n",numeroAtivo(s)); // conta e imprime o numero de soldados ativos
		printf("\n---------------------------\n");
	}
	printf("O soldado que restou foi o %02d",escolhido(s)); // imprime o numero do escolhido
	return 0;
}

