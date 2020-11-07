/******************************************************************************
//     listaSequencial.c
// Este programa gerencia listas lineares sequenciais.
// As listas gerenciadas podem ter MAX elementos (posicoes de 0 a MAX-1 no
//   arranjo A). Alocamos MAX+1 posicoes no arranjo para possibilitar a 
//   criacao de um elemento sentinela.
******************************************************************************/
#include <stdio.h>
#define MAX 150
#define ERRO -1
#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
  REGISTRO A[MAX+1];
  int nroElem;
} LISTA;


/* Inicialização da lista sequencial (a lista já está criada e é apontada 
pelo endereço em l)
--------------------------------------------------------------------------
**Tipo de método: Void 
**Nome do método: inicializarLista 
**Parametro(s): Ponteiro tipo Lista 
**Retorno: Nenhum 
**Função: Atribui 0 no valor do primeiro elemento
*/
void inicializarLista(LISTA* l){
  l->nroElem = 0;
}


/* Inicialização da lista sequencial (a lista já está criada e é apontada 
pelo endereço em l) 
--------------------------------------------------------------------------
**Tipo de método: Void 
**Nome do método: exibirLista 
**Parametro(s): Ponteiro tipo Lista 
**Retorno: Nenhum 
**Função: Mostra na tela a lista inteira
*/
void exibirLista(LISTA* l){
  int i;
  printf("Lista: \" ");
  for (i=0; i < l->nroElem; i++)
    printf("%i ", l->A[i].chave); // só lembrando TIPOCHAVE = int
  printf("\"\n");
}


/* Retornar o tamanho da lista (numero de elementos "validos") 
--------------------------------------------------------------------------
**Tipo de método: int 
**Nome do método: tamanho
**Parametro(s): Ponteiro tipo Lista
**Retorno: valor do nroElem (int)
**Função: Retornar o valor do numero de elemento na lista 
*/
int tamanho(LISTA* l) {
  return l->nroElem;
} 


/* Retornar o tamanho em bytes da lista. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados, pois a alocacao de memoria eh estatica.
   A priori, nao precisariamos do ponteiro para a lista, vamos utiliza-lo apenas
   porque teremos as mesmas funcoes para listas ligadas.   
   --------------------------------------------------------------------------
**Tipo de método: int 
**Nome do método: tamanhoEmBytes
**Parametro(s): Ponteiro tipo Lista
**Retorno: Returna o tamanho em bytes da lista 
**Função: Calcular o tamanho da lista 
*/
int tamanhoEmBytes(LISTA* l) {
  return sizeof(LISTA);
} 


/* Retornar a chave do primeiro elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja 
   --------------------------------------------------------------------------
**Tipo de método:TIPOCHAVE (int) - declarado no typedef 
**Nome do método: primeiroElem
**Parametro(s): Ponteiro tipo Lista
**Retorno: Retorna a chave do primeiro elemento caso exista, caso não, retorna erro.
**Função: Verificar se é o primeiro elemento, caso nao, retorna erro.
 */
TIPOCHAVE primeiroElem(LISTA* l){
  if(l->nroElem > 0) return l->A[0].chave;
  else return ERRO; // lista vazia
} 


/* Retornar a chave do ultimo elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia 
   --------------------------------------------------------------------------
**Tipo de método: TIPOCHAVE (int) - declarado no typedef 
**Nome do método: ultimoElem
**Parametro(s): Ponteiro tipo Lista
**Retorno: Retorna a chave do ultimo elemento caso exista, caso não, retorna erro.
**Função: Verificar se é o ultimo elemento, caso nao, retorna erro.
*/
TIPOCHAVE ultimoElem(LISTA* l) {
  if(l->nroElem > 0) return l->A[l->nroElem-1].chave;
  else return ERRO; // lista vazia
} 


/* Retornar a chave do elemento que est� na posi��o n da LISTA. Lembre-se que as posicoes do
   arranjo A vao de 0 a MAX-1  
   --------------------------------------------------------------------------
**Tipo de método: TIPOCHAVE (int) - declarado no typedef 
**Nome do método: enesimoElem
**Parametro(s): Ponteiro tipo Lista e valor da posição (int)
**Retorno: Retorna o valor da chave do elemento ou caso de erro retorna ERRO
**Função: Verifica se está entre 0 e o ultimo elemento, se tiver, retorna o elemento do N. Caso não satisfaça retorna erro 
*/
TIPOCHAVE enesimoElem(LISTA* l, int n) {
  if( (n >= 0) && (n < l->nroElem)) return l->A[n].chave ;
  else return ERRO;
} 


/* Reinicializar a estrutura 
--------------------------------------------------------------------------
**Tipo de método: Void
**Nome do método: reinicializarLista
**Parametro(s): Ponteiro tipo Lista
**Retorno: Nenhum
**Função: Resetar a lista colocando 0 no nroElem
*/
void reinicializarLista(LISTA* l) {
  l->nroElem = 0;
} 


/* Inserção "direta" na iésima posição (posicao i do arranjo A).
   Funciona da mesma maneira de um insertionSort: deve-se deslocar todos os
   elementos a partir da iesima posicao e entao se insere o novo elemento. *. 
   --------------------------------------------------------------------------
**Tipo de método: bool 
**Nome do método: inserirElemLista
**Parametro(s): Ponteiro tipo Lista, Valor do Reg e endereço
**Retorno: Retorna true se inserir na lista ou caso de erro retorna false
**Função: receber o valor e endereço que será inserido na lista realocando os outros itens
*/
bool inserirElemLista(LISTA* l, REGISTRO reg, int i){
  int j;
  if ((l->nroElem >= MAX) || (i < 0) || (i > l->nroElem)) 
     return(false); // lista cheia ou indice inválido
  for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1];
  l->A[i] = reg;
  l->nroElem++;
  return true;
} 


/* Busca sequencial em lista ordenada ou não SEM SENTINELA 
--------------------------------------------------------------------------
**Tipo de método: int
**Nome do método: buscaSequencial
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:Fazer o busca sequencial para verifar se há na lista 
 */
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  while (i < l->nroElem){
    if(ch == l->A[i].chave) return i; // achou
    else i++;
  }
  return ERRO; // não achou
} 


/* Exclusão do elemento cuja chave seja igual a ch 
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: excluirElemLista
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se remover o item na lista retona true, se não remover, retornar false
**Função: Fazer o busca sequencial para verifar se há na lista, se tiver remove e realoca a lista 
*/
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaSequencial(l,ch);
  if(pos == ERRO) return false; // não existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} 


/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições)
--------------------------------------------------------------------------
**Tipo de método: int 
**Nome do método: buscaSentinela
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:  adiciona um elemento no final da tabela afim de realizar um teste 
*/
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave != ch) i++;
  if (i > l->nroElem -1) return ERRO; // não achou
  else return i;
} 


int main(){
  LISTA lista;
  inicializarLista(&lista);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  REGISTRO reg;
  reg.chave = 9;
  inserirElemLista(&lista,reg,0);
  exibirLista(&lista);
  reg.chave=3;
  inserirElemLista(&lista,reg,1);
  reg.chave=4;
  inserirElemLista(&lista,reg,2);
  reg.chave=1;
  inserirElemLista(&lista,reg,3);
  reg.chave=12;
  inserirElemLista(&lista,reg,2);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSequencial(&lista,4));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSentinela(&lista,4));
  if (excluirElemLista(&lista,4)) printf("Exclusao bem sucedida: 4.\n");
  if (excluirElemLista(&lista,8)) printf("Exclusao bem sucedida: 8.\n");
  if (excluirElemLista(&lista,9)) printf("Exclusao bem sucedida: 9.\n");
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  reinicializarLista(&lista);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  return 0;
}
    
/* SAIDA DO PROGRAMA:
Lista: " "
Numero de elementos na lista: 0.
Tamanho da lista (em bytes): 208.
Lista: " 9 "
Lista: " 9 3 12 4 1 "
Numero de elementos na lista: 5.
Tamanho da lista (em bytes): 208.
Chave 4 encontrada na posicao: 3 do arranjo A.
Chave 4 encontrada na posicao: 3 do arranjo A.
Exclusao bem sucedida: 4.
Exclusao bem sucedida: 9.
Lista: " 3 12 1 "
Numero de elementos na lista: 3.
Tamanho da lista (em bytes): 208.
Lista: " "
Numero de elementos na lista: 0.
Tamanho da lista (em bytes): 208.
*/
