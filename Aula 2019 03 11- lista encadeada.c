#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6 // numero m�ximo de registros conforme enunciado
typedef struct l{// defini��o da struct
	char letras[30]; // string com 30 caracteres
	struct l *prox; // ponteiro para a struct, endere�o do proximo item
} l;
int inclui(l lista[],char nome[], int n){ 
//pre: recebe a lista a ser preenchida, a string a ser escrita e o numero da posi��o de escrita
//pos: preenchea lista com o valor da string e com o endere�o do sucessor ou numo se foi o ultimo registro
	if (n==0){
		strcpy(lista[n].letras,"inicio");
		lista[n].prox=&lista[n+1];// se n�o for escreve o endere�o do proximo registro
		n++;
	}
	strcpy(lista[n].letras,nome); // faz a copia da string na lista
	if (n==MAX-1) { // verifica se � o ultimo registro
		lista[n].prox=NULL; // se for o ultimo escreve nulo
		n++;
	}
	else {
		lista[n].prox=&lista[n+1];// se n�o for escreve o endere�o do proximo registro
		n++;
	}
return n;
}
void exclui(l lista[], int n){
	if (n==0){
		printf("impossivel excluir");	
	}
	else{
		lista[n-1].prox=&lista[n+1];
	}
}
void imprime(l *end){
//pre: recebe o endere�o do primeiro registro da lista
//pos: imprime todos os endere�os a partir da ender�o indicado at� achar o ultimo registro (end == NULL)
	while(end!=NULL){ // Repete ate encontrar o ultimo endre�o (end == NULL)
			printf("%s %p\n",(*end).letras,(*end).prox); // imprime na tela o conteudo a string da struct contida no endere�o end.
		end=(*end).prox; // copia o endere�o da proxima entidade contida no ponteiro da struct no endere�o end
	}
}

int menu(){
	int i;
	printf("Digite a op��o desejada\n");
	printf("1) Incluir registro\n");
	printf("2) Excluir um registro\n");
	printf("3) Imprimir lista\n");
	printf("4) Sair do Programa\n");
	scanf("%d",&i);
	return i;
}
int main(){
	int i,n,j; // declara i para contar o numero de strings digitadas;
	l lista[MAX]; // declara lista
	char nome[30]; // declara string
	i=0;
	while(n!=4){
		n=menu();
		if (n==1){
			while(i<MAX){
				printf("Digite uma string:\n");
				scanf("%s",&nome);// le a string
				i=inclui(lista,nome,i);	// inclui a string na lista
			}
		}
		else if (n==2){
			printf("Digite a posi��o a excluir\n");
			scanf("%d",&i);
			exclui(lista,i);
		}
		else if (n==3){
			imprime(&lista[0]);
		}
		else if (n==4){
			printf("Sair do programa!\n");
		}
	}
	return 0;
}
