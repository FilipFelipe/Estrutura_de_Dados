//Código da aula 2 
//testa_estrutura.c
#include <stdio.h>									//Importa a lib stdio.h
#include <malloc.h>									//Importa a lib malloc.h

typedef struct										//Criação da estrutura 
{
  int c1;											//Declara a variável int peso na estrutura 
  int c2;											//Declara a variável int peso na estrutura 
} TESTE, *PONT;										//Nome da estrutura 

PONT copiar(TESTE t1){								//Método copiar receber uma estrutura tipo TESTE
	PONT x = (PONT) malloc(sizeof(TESTE));			//Declara a variável do tipo TESTE alocando na memória
	*x = t1;										//Copia t1
	return x;										//retorna um tipo PONT
}

int main(){											//Método Principal do programa
	TESTE y;										//Declara variável do tipo TESTE
	y.c1 = 10;										//Atribui c1 = 10
	y.c2 = 22;										//Atribui c2 = 22
	PONT w = copiar(y);								//Declara variável w recebendo os dados através do metódo copiar

	printf("c1: %i, c2: %i\n", w->c1, w->c2);		//Mostra na tela os valores de c1 e c2
	return 0;
}




