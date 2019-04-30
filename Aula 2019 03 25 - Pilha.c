#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char pilha[100];
int n;
void inicializaPilha(){
	n=0;
}
char pop(){
	if (pilhaVazia()==0){
		printf("A pilha esta vazia, impossivel fazer pop!\n");
		return 0;
	}
	else {
		n--;
		return pilha[n];
	}
			 
}
char consultaPilha(){
	return pilha[n-1];
}
int pilhaVazia(){
	int i;
	if (n==0) i=0;
	else i=n;
	return i; 
}
void push(char t) {
	pilha[n]=t;
	n++;
}
void imprimePilha(){
	int i;
	printf("---Pilha---\n");
	for(i=0;i<n;i++){
		printf("%d ",i);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%c ",pilha[i]);
	}
	printf("\n");
	printf("---Pilha---\n");
}
void pop2(){
	int i=0,s=1;
	char valor;
	while(i<2 && s>0 ){
		if (pilhaVazia()>0){
			valor=pop();
			printf("Valor retirado da pilha %c\n",valor);
		}
		else {
			printf("Nao ha valores na pilha\n");
			s=0;
		}
		i++;
	}
}
void popn(int n){
	int i=0,s=1;
	char valor;
	while(i<n && s>0 ){
		if (pilhaVazia()>0){
			valor=pop();
			printf("Valor retirado da pilha %c\n",valor);
		}
		else {
			printf("Nao ha valores na pilha\n");
			s=0;
		}
		i++;
	}
	
}
int menu(){
	int opcao;
	printf("1)Inicializa pilha\n");
	printf("2)Inclui Item na pilha\n");
	printf("3)Retira item da pilha\n");
	printf("4)Verifica se a pilha esta vazia\n");
	printf("5)Consulta pilha\n");
	printf("6)Retira dois itens da pilha\n");
	printf("7)Retira varias itens da pilha\n");
	printf("8)Finaliza pilha e sai do programa\n");
	fflush(stdin);
	scanf("%d",&opcao);
	return opcao ;
}
int main(){
	int n,opcao;
	char valor;
	inicializaPilha();
	while(opcao!=8 ){
		opcao=menu();
		if (opcao==1){
			inicializaPilha();
		}
		else if (opcao==2){
			printf("Digite a expressao que deseja empilhar:\n");
			fflush(stdin);
			valor=getchar();
			push(valor);
		}
		else if (opcao==3){
			if (pilhaVazia()>0){
				valor=pop();
				printf("Valor retirado da pilha %c\n",valor);
			}
			else printf("Nao ha valores na pilha\n");
		}
		else if (opcao==4){
			if (pilhaVazia()==0) printf("A Pilha esta vazia\n");
			else printf("A pilha nao esta vazia\n");
		}
		else if (opcao==5){
			if (pilhaVazia()>0){
				valor=consultaPilha();
			printf("Valor no topo da pilha e %c\n",valor);
			}
			else printf("Não ha valores na pilha\n");
		}
		else if (opcao==6){
			pop2();
		}
		else if (opcao==7){
			printf("Digite o numero de termos que deseja retirar da pilha\n");
			scanf("%d",&n);
			popn(n);
		}
		else if (opcao==8){
			printf("Encerrando programa!\n");
		}
		else {
			printf("Opçao invalida\n");
		}
		imprimePilha();
		fflush(stdin);
	}

	return 0;
}



