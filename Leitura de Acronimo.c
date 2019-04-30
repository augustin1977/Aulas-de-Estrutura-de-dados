#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // numero máximo de registros conforme enunciado

int acronimo(char texto[MAX]) {
	int i=0,j=0;
	char ac[MAX];
	while(texto[i]>0 && i<MAX){
		if (texto[i]>64 && texto[i]<91){
			ac[j]=texto[i];
			j++;
		}
		i++;
	}
	printf("%s\n",texto);
	printf("%s\n",ac);
	return 0; // retorna 0
}
int main(){
	char texto[MAX];
	strcpy(texto,"Organizacao das Nacoes Unidas");
	acronimo(texto);
	strcpy(texto,"Joint Photographic Experts Group");
	acronimo(texto);
	strcpy(texto,"Institute of Electrical and Electronics Engineers");
	acronimo(texto);
	strcpy(texto,"Organizacao do Tratado do Atlantico Norte");
	acronimo(texto);
	return 0;
}



