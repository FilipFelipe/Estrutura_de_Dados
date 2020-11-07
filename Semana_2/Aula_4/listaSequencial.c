/******************************************************************************
//     listaSequencialOrdenada.c
******************************************************************************/
#include <stdio.h>
#define MAX 50
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


/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posi��es) 
   considerando o arranjo ordenado 
   --------------------------------------------------------------------------
**Tipo de método: int 
**Nome do método: buscaSentinelaOrdenada
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:  adiciona um elemento no final da tabela afim de realizar um teste 
*/
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave < ch) i++;
  if (i == l->nroElem || l->A[i].chave != ch) return ERRO; // n�o achou
  else return i;
} 


/* Busca binaria em lista ordenada 
--------------------------------------------------------------------------
**Tipo de método: int 
**Nome do método: buscaBinaria
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:  Realiza a divisão da lista no meio até encontrar o valor  
*/
int buscaBinaria(LISTA* l, TIPOCHAVE ch){
  int esq, dir, meio;
  esq = 0;
  dir = l->nroElem-1;
  while(esq <= dir) {
    meio = ((esq + dir) / 2);
    if(l->A[meio].chave == ch) return meio; // achou
    else {
      if(l->A[meio].chave < ch) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return ERRO;
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


/* Exclus�o do elemento cuja chave seja igual a ch em lista ordenada
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: excluirElemListaOrd
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se remover o item na lista retona true, se não remover, retornar false
**Função: Fazer o busca binária para verifar se há na lista, se tiver remove e realoca a lista 
*/
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaBinaria(l,ch);
  if(pos == ERRO) return false; // n�o existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} 


/* Inser��o em lista ordenada usando busca bin�ria permitindo duplica��o 
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: inserirElemListaOrd
**Parametro(s): Ponteiro tipo Lista e valor do registro
**Retorno: Se adicionar o item na lista retona true, se não adicionar, retornar false
**Função: Realizar a inserção na lista atraves de busca binária 
*/
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= MAX) return false; // lista cheia
  int pos = l->nroElem;
  while(pos > 0 && l->A[pos-1].chave > reg.chave) {
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  return true;
} /* fazer */



/* Inser��o em lista ordenada usando busca bin�ria sem duplica��o 
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: inserirElemListaOrdSemDup
**Parametro(s): Ponteiro tipo Lista e valor do registro
**Retorno: Se adicionar o item na lista retona true, se não adicionar ou se o elemento existir, retornar false
**Função: Realizar a inserção na lista atraves de busca binária 
*/
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= MAX) return false; // lista cheia
  int pos;
  pos = buscaBinaria(l,reg.chave);
  if(pos != ERRO) return false; // elemento j� existe
  pos = l->nroElem-1;
  while(pos>0 && l->A[pos].chave > reg.chave) {
    l->A[pos+1] = l->A[pos];
    pos--;
  }
  l->A[pos+1] = reg;
  l->nroElem++;
  return true;
} /* FAZER */



int main(){
  LISTA lista;
  inicializarLista(&lista);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  REGISTRO reg;
  reg.chave = 9;
  inserirElemListaOrd(&lista,reg);
  exibirLista(&lista);
  reg.chave=3;
  inserirElemListaOrd(&lista,reg);
  reg.chave=4;
  inserirElemListaOrd(&lista,reg);
  reg.chave=1;
  inserirElemListaOrd(&lista,reg);
  reg.chave=12;
  inserirElemListaOrd(&lista,reg);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSequencial(&lista,4));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaBinaria(&lista,4));
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
Lista: " 1 3 4 9 12 "
Numero de elementos na lista: 5.
Tamanho da lista (em bytes): 208.
Chave 4 encontrada na posicao: 2 do arranjo A.
Chave 4 encontrada na posicao: 2 do arranjo A.
Chave 4 encontrada na posicao: 2 do arranjo A.
Exclusao bem sucedida: 4.
Exclusao bem sucedida: 9.
Lista: " 1 3 12 "
Numero de elementos na lista: 3.
Tamanho da lista (em bytes): 208.
Lista: " "
Numero de elementos na lista: 0.
Tamanho da lista (em bytes): 208.
*/
