#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 120 // numero máximo de registros
#define L 50
int g=0;


typedef struct arvore{// definição da struct
	int letra; // int
	struct arvore *direita; // endereço arvore direita
	struct arvore *esquerda; // endereço arvore esquerda
} arvore;

void imprime(arvore *a,int n){
	int i;
	n++;
	if (a != NULL) {
      imprime (a->direita,n);
      for (i=0;i<n;i++){
      	printf("	");
	  }
      printf ("%i-%d \n",n,a->letra);
      imprime (a->esquerda,n); 
   }	
}
void insere(int letra,arvore **a){
	//printf("passei\n");
	if (*a==NULL) {
		*a = (arvore*)malloc(sizeof(arvore));
		(*(*a)).letra=letra;
		(*(*a)).direita=NULL;
		(*(*a)).esquerda=NULL;
	}
	
	else {
		if (letra>(*a)->letra){
			insere(letra,&(*(*a)).direita);
		}
		else{
			insere(letra,&(*(*a)).esquerda );	
		}
	}
}
void dicotomia(int vaux[MAX],int vetor[MAX], int a, int b){
	if ((b-a)>1){
		vaux[g]=vetor[(a+b)/2];
		//printf("%d %c\n",g,vaux[g]);
		g++;
		dicotomia(vaux,vetor,a,(a+b)/2);
		dicotomia(vaux,vetor,(a+b)/2,b);	
	}
		
}

void copia(int vaux[],int vetor[],int n){
	int i;
	vaux[L-1]=vetor[0];	
	for (i=0;i<n;i++){
		vetor[i]=vaux[i];
		printf("%d ",vetor[i]);
	}
}	
void organiza(int vetor[MAX], int n){
	int i,j;
	int aux;
	int vaux[MAX];
	for (i=0;i<n-1;i++){
		for (j=i;j<n;j++){
			if (vetor[i]>vetor[j]){
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
	dicotomia(vaux,vetor,0,n);
	copia(vaux,vetor,L);
	
	printf("\n");
}

int main(){
	int i,n,j; // declara i para contar o numero de strings digitadas;
	int entrada[MAX];
	i=L;// remover
	srand(time(NULL));
	arvore *a=NULL; // declara lista
	int letra; // declara string
	for (i=0;i<L;i++){
		letra=rand()%2000;
		entrada[i]=letra;
	}
	
	organiza(entrada,i);
	i=0; // faz contador igual a zero
	while(i!=L){
		insere(entrada[i],&a);
		i++;	
	}
	printf("---------------------\n");
	printf("|Imprimindo em ordem|\n");
	printf("---------------------\n");
	imprime(&(a[0]),0);
	return 0;
}
