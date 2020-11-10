/******************************************************************************
//     exemploDoisRetornos.c
// Exemplo de funcao que retorna um valor, mas, antes disso, passa outro valor
// para o endereco de memoria apontado por um dos parametros da funcao.
******************************************************************************/
#include <stdio.h>

/* funcao que retorna o quadrado do primeiro parametro e coloca no endereco
   apontado pelo segundo parametro o valor do cubo do primeiro parametro    */
/*
**Tipo de método: int
**Nome do método: funcaoQuadradoCubo
**Parametro(s): Ponteiro tipo Lista e valor do registro
**Retorno: Se adicionar o item na lista retona true, se não adicionar ou se o elemento existir, retornar false
**Função: Atribui o quadrado do primeiro parametro e coloca no endereco apontado e retorna o segundo parametro ao cuboo  
*/
int funcaoQuadradoCubo(int x, int* y){
	*y = x*x*x;
	return x*x;
}

int main(){
  int a = 3;
  int cubo;
  int quadrado = funcaoQuadradoCubo(a, &cubo);
  printf("valor: %i; valor ao quadrado: %i; valor ao cubo: %i\n", a, quadrado, cubo);
  return 0;
}

/* SAIDA:
valor: 3; valor ao quadrado: 9; valor ao cubo: 27
*/
