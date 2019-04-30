#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5 // numero m�ximo de registros conforme enunciado
typedef struct l{// defini��o da struct
	char letras[30]; // string com 30 caracteres
	struct l *prox; // ponteiro para a struct, endere�o do proximo item
} l;
void inclui(l lista[],char nome[], int n){ 
//pre: recebe a lista a ser preenchida, a string a ser escrita e o numero da posi��o de escrita
//pos: preenchea lista com o valor da string e com o endere�o do sucessor ou numo se foi o ultimo registro
	strcpy(lista[n].letras,nome); // faz a copia da string na lista
	if (n==MAX-1) { // verifica se � o ultimo registro
		lista[n].prox=NULL; // se for o ultimo escreve nulo
	}
	else {
		lista[n].prox=&lista[n+1];// se n�o for escreve o endere�o do proximo registro
	}
}

void imprime(l *end){
//pre: recebe o endere�o do primeiro registro da lista
//pos: imprime todos os endere�os a partir da ender�o indicado at� achar o ultimo registro (end == NULL)
	while(end!=NULL){ // Repete ate encontrar o ultimo endre�o (end == NULL)
			printf("%s\n",(*end).letras); // imprime na tela o conteudo a string da struct contida no endere�o end.
		end=(*end).prox; // copia o endere�o da proxima entidade contida no ponteiro da struct no endere�o end
	}
}
int main(){
	int i; // declara i para contar o numero de strings digitadas;
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
