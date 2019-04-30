#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20 // numero m�ximo de registros
typedef struct l{// defini��o da struct
	char letras[30]; // string com 30 caracteres
	struct l *prox; // ponteiro para a struct, endere�o do proximo item
} l;
int inclui(l lista[],char nome[], int n){ 
//pre: recebe a lista a ser preenchida, a string a ser escrita e o numero da posi��o de escrita
//pos: preenchea lista com o valor da string e com o endere�o do sucessor ou numo se foi o ultimo registro
	if (n==0){
		strcpy(lista[n].letras,"inicio");
		//lista[n].prox=&lista[n+1];// se n�o for escreve o endere�o do proximo registro
		n++;
	}
	strcpy(lista[n].letras,nome); // faz a copia da string na lista
	lista[n-1].prox=&lista[n];// escreve o endere�o do desse registro no registro anterior
	lista[n].prox=NULL; // escreve como proximo o valor NULL
	n++; // incrementa o contador para preparar para o proximo registro
return n; // retorna o numero do proximo registro
}
void exclui(l lista[], int u, int n){
//pre: recebe a lista a ser preenchida, o numero de registros e o registro a ser excluida
//pos: exclui o registro n
	
	if (n==0){ // verifica se a tentativa � de exclui o indice
		printf("impossivel excluir");	
	}
	else if (u==n){ //exclus�o do ultimo
		lista[n-1].prox=NULL;
	}
	else{
		lista[n-1].prox=&lista[n+1]; // faz a exclus�o de um item na lista
	}
}
void imprime(l *end){
//pre: recebe o endere�o do primeiro registro da lista
//pos: imprime todos os endere�os a partir da ender�o indicado at� achar o ultimo registro (end == NULL)
	int i=0;
	while(end!=NULL){ // Repete ate encontrar o ultimo endre�o (end == NULL)
		printf("%d - %s %p\n",i,(*end).letras,(*end).prox); // imprime na tela o conteudo a string da struct contida no endere�o end.
		end=(*end).prox; // copia o endere�o da proxima entidade contida no ponteiro da struct no endere�o end
		i++;
	}
}

int menu(){ // menu de op��es
	int i;
	fflush(stdin);// limpa buffer de teclado
	printf("Digite a opcaoo desejada\n");
	printf("1) Incluir registro\n");
	printf("2) Excluir um registro\n");
	printf("3) Imprimir lista\n");
	printf("4) Sair do Programa\n");
	scanf("%d",&i);
	return i; // retorna a op��o escolhida
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
			i=inclui(lista,nome,i);	// inclui a string na lista na posi��o i
		}
		else if (n==2){
			printf("Digite a posicao a excluir\n");
			scanf("%d",&j);
			exclui(lista,i-1,j); // exclui o registro j
		}
		else if (n==3){
			imprime(&lista[0]); // chama a fun��o que imprime a lista
		}
		else if (n==4){
			printf("Sair do programa!\n"); // sai do programa
		}
	}
	return 0;
}
