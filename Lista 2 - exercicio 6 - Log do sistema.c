#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10
typedef struct log{// definição da struct
	char nomeUsuario[20]; // nome usuário
	int datalogin;// data do login sem formato 01/01/2010 = 1012010
	int horalogin;// hora do login sem formato 13:10 = 1310 e 00:30 = 30
	int datalogoff;// data do logoff sem formato 01/01/2010 = 1012010
	inf datalogoff;// hora do Logoff sem formato 13:10 = 1310 e 00:30 = 30
} log;



