#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // numero m�ximo de registros conforme enunciado
typedef struct l{// defini��o da struct
	char letras[50]; // string com 50 caracteres
	struct l *prox; // ponteiro para a struct, endere�o do proximo item
} l;
void inclui(l lista[],char nome[], int n){ 
//pre: recebe a lista a ser preenchida, a string a ser escrita e o numero da posi��o de escrita
//pos: preenche a lista com o valor da string e com o endere�o do sucessor sempre preenche endere�o do ultimo registro como NULL
	strcpy(lista[n].letras,nome); // faz a copia da string na lista
	//printf("%s",nome);
	lista[n].prox=NULL;// Preeenche o endere�o da proxima como NULL, pois considera que este � o ultimo registro
	if (n!=0){ // Verifica se n�o � a primeira entidade da lista
		lista[n-1].prox=&lista[n]; // Caso n�o seja a primeira entidade, aponta para a proxima entidade para fazer o encadeamento
		printf("%p %p", lista[n-1].prox,&lista[n]);
	}
}
void imprime(l *end){
//pre: recebe o endere�o do primeiro registro da lista
//pos: imprime todos os endere�os a partir da ender�o indicado at� achar o ultimo registro (end == NULL)
	while(end!=NULL){ // Repete ate encontrar o ultimo endre�o (end == NULL)
		printf("%p",end);
		printf("%s\n",(*end).letras); // imprime na tela o conteudo a string da struct contida no endere�o end.
		end=(*end).prox; // copia o endere�o da proxima entidade contida no ponteiro da struct no endere�o end
	}
}
int main() {
	int i=0,cont=1; // declara i para contar o numero de strings digitadas;
	l *lista,*l1; // declara um ponteiro para a struct do tipo l
	char nome[30];// declara a string que sera copiada para a struct lista
	while(cont){ // la�o para ler o teclado e escrever as strings na struct at� cont==0
		printf("Digite uma string ou digite enter para sair:\n"); // mensage para o usu�rio
		gets(nome); // leitura do teclado
		if (strlen(nome)==0) {// verifica se � igual 0 de comprimento
			cont=0;// se verdadeiro faz cont=0 para sair do while
		}
		else{ // sen�o
		lista = malloc (sizeof (l));
		if (i==0) l1=lista;
		inclui(lista,nome,i); // chama a fun��o de copia da string para a struct
		i++;//incrementa 1 no contador de entradas
		}
	}
	printf("Imprimindo String\n");// mensagem para o usu�rio
	imprime(l1); // chama a fun��o que imprime na tela todas as strings a partir do endere�o enviado, no caso o edere�o do primeiro item
	return 0; // retorna 0
}
