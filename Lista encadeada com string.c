#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5 // numero máximo de registros conforme enunciado
typedef struct l{// definição da struct
	char letras[30]; // string com 30 caracteres
	struct l *prox; // ponteiro para a struct, endereço do proximo item
} l;
void inclui(l lista[],char nome[], int n){ 
//pre: recebe a lista a ser preenchida, a string a ser escrita e o numero da posição de escrita
//pos: preenchea lista com o valor da string e com o endereço do sucessor ou numo se foi o ultimo registro
	strcpy(lista[n].letras,nome); // faz a copia da string na lista
	if (n==MAX-1) { // verifica se é o ultimo registro
		lista[n].prox=NULL; // se for o ultimo escreve nulo
	}
	else {
		lista[n].prox=&lista[n+1];// se não for escreve o endereço do proximo registro
	}
}

void imprime(l *end){
//pre: recebe o endereço do primeiro registro da lista
//pos: imprime todos os endereços a partir da enderço indicado até achar o ultimo registro (end == NULL)
	while(end!=NULL){ // Repete ate encontrar o ultimo endreço (end == NULL)
			printf("%s\n",(*end).letras); // imprime na tela o conteudo a string da struct contida no endereço end.
		end=(*end).prox; // copia o endereço da proxima entidade contida no ponteiro da struct no endereço end
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
