#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20 // numero máximo de registros
typedef struct l{// definição da struct
	char letras[30]; // string com 30 caracteres
	struct l *prox; // ponteiro para a struct, endereço do proximo item
} l;
int inclui(l lista[],char nome[], int n){ 
//pre: recebe a lista a ser preenchida, a string a ser escrita e o numero da posição de escrita
//pos: preenchea lista com o valor da string e com o endereço do sucessor ou numo se foi o ultimo registro
	if (n==0){
		strcpy(lista[n].letras,"inicio");
		//lista[n].prox=&lista[n+1];// se não for escreve o endereço do proximo registro
		n++;
	}
	strcpy(lista[n].letras,nome); // faz a copia da string na lista
	lista[n-1].prox=&lista[n];// escreve o endereço do desse registro no registro anterior
	lista[n].prox=NULL; // escreve como proximo o valor NULL
	n++; // incrementa o contador para preparar para o proximo registro
return n; // retorna o numero do proximo registro
}
void exclui(l lista[], int u, int n){
//pre: recebe a lista a ser preenchida, o numero de registros e o registro a ser excluida
//pos: exclui o registro n
	
	if (n==0){ // verifica se a tentativa é de exclui o indice
		printf("impossivel excluir");	
	}
	else if (u==n){ //exclusão do ultimo
		lista[n-1].prox=NULL;
	}
	else{
		lista[n-1].prox=&lista[n+1]; // faz a exclusão de um item na lista
	}
}
void imprime(l *end){
//pre: recebe o endereço do primeiro registro da lista
//pos: imprime todos os endereços a partir da enderço indicado até achar o ultimo registro (end == NULL)
	int i=0;
	while(end!=NULL){ // Repete ate encontrar o ultimo endreço (end == NULL)
		printf("%d - %s %p\n",i,(*end).letras,(*end).prox); // imprime na tela o conteudo a string da struct contida no endereço end.
		end=(*end).prox; // copia o endereço da proxima entidade contida no ponteiro da struct no endereço end
		i++;
	}
}

int menu(){ // menu de opções
	int i;
	fflush(stdin);// limpa buffer de teclado
	printf("Digite a opcaoo desejada\n");
	printf("1) Incluir registro\n");
	printf("2) Excluir um registro\n");
	printf("3) Imprimir lista\n");
	printf("4) Sair do Programa\n");
	scanf("%d",&i);
	return i; // retorna a opção escolhida
}
int main(){
	int i,n,j; // declara i para contar o numero de strings digitadas;
	l lista[MAX]; // declara lista
	char nome[30]; // declara string
	i=0; // faz contador igual a zero
	while(n!=4){
		n=menu();
		if (n==1){
			printf("Digite uma string:\n");
			scanf("%s",&nome);// le a string
			i=inclui(lista,nome,i);	// inclui a string na lista na posição i
		}
		else if (n==2){
			printf("Digite a posicao a excluir\n");
			scanf("%d",&j);
			exclui(lista,i-1,j); // exclui o registro j
		}
		else if (n==3){
			imprime(&lista[0]); // chama a função que imprime a lista
		}
		else if (n==4){
			printf("Sair do programa!\n"); // sai do programa
		}
	}
	return 0;
}
