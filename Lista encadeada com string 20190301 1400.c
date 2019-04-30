#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // numero máximo de registros conforme enunciado
typedef struct l{// definição da struct
	char letras[50]; // string com 50 caracteres
	struct l *prox; // ponteiro para a struct, endereço do proximo item
} l;
void inclui(l lista[],char nome[], int n){ 
//pre: recebe a lista a ser preenchida, a string a ser escrita e o numero da posição de escrita
//pos: preenche a lista com o valor da string e com o endereço do sucessor sempre preenche endereço do ultimo registro como NULL
	strcpy(lista[n].letras,nome); // faz a copia da string na lista
	//printf("%s",nome);
	lista[n].prox=NULL;// Preeenche o endereço da proxima como NULL, pois considera que este é o ultimo registro
	if (n!=0){ // Verifica se não é a primeira entidade da lista
		lista[n-1].prox=&lista[n]; // Caso não seja a primeira entidade, aponta para a proxima entidade para fazer o encadeamento
		printf("%p %p", lista[n-1].prox,&lista[n]);
	}
}
void imprime(l *end){
//pre: recebe o endereço do primeiro registro da lista
//pos: imprime todos os endereços a partir da enderço indicado até achar o ultimo registro (end == NULL)
	while(end!=NULL){ // Repete ate encontrar o ultimo endreço (end == NULL)
		printf("%p",end);
		printf("%s\n",(*end).letras); // imprime na tela o conteudo a string da struct contida no endereço end.
		end=(*end).prox; // copia o endereço da proxima entidade contida no ponteiro da struct no endereço end
	}
}
int main() {
	int i=0,cont=1; // declara i para contar o numero de strings digitadas;
	l *lista,*l1; // declara um ponteiro para a struct do tipo l
	char nome[30];// declara a string que sera copiada para a struct lista
	while(cont){ // laço para ler o teclado e escrever as strings na struct até cont==0
		printf("Digite uma string ou digite enter para sair:\n"); // mensage para o usuário
		gets(nome); // leitura do teclado
		if (strlen(nome)==0) {// verifica se é igual 0 de comprimento
			cont=0;// se verdadeiro faz cont=0 para sair do while
		}
		else{ // senão
		lista = malloc (sizeof (l));
		if (i==0) l1=lista;
		inclui(lista,nome,i); // chama a função de copia da string para a struct
		i++;//incrementa 1 no contador de entradas
		}
	}
	printf("Imprimindo String\n");// mensagem para o usuário
	imprime(l1); // chama a função que imprime na tela todas as strings a partir do endereço enviado, no caso o edereço do primeiro item
	return 0; // retorna 0
}
