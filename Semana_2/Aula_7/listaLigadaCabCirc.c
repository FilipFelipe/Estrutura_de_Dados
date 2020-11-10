/******************************************************************************
     listaLigadaCabCirc.c
  Este programa gerencia listas lineares ligadas circulares (implementacao 
dinamica) com n� cabe�a no in�cio da lista.
  As listas gerenciadas podem ter um numero arbitrario de elementos.
  O no cabe�a acelera o algoritmo de busta sequencial por reduzir o numero
de comparacoes. Alem disso algumas operacoes ficam mais simples pois a lista
nunca esta "vazia" (sempre haverah o noh cabeca)
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;


typedef struct tempRegistro{
  REGISTRO reg;
  struct tempRegistro* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
  PONT cabeca;
} LISTA;


/* Inicializa��o da lista ligada (a lista jah esta criada e eh apontada 
pelo endereco em l)   
--------------------------------------------------------------------------
**Tipo de método: Void 
**Nome do método: inicializarLista 
**Parametro(s): Ponteiro tipo Lista 
**Retorno: Nenhum 
**Função: Aponta para cabeca
*/
void inicializarLista(LISTA* l){
  l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
  l->cabeca->prox = l->cabeca;  // faz com que a lista seja circular
} 


/* Exibi��o da lista sequencial   
--------------------------------------------------------------------------
**Tipo de método: Void 
**Nome do método: exibirLista 
**Parametro(s): Ponteiro tipo Lista 
**Retorno: Nenhum 
**Função: Mostra na tela a lista inteira
*/
void exibirLista(LISTA* l){
  PONT end = l->cabeca->prox;
  printf("Lista: \" ");
  while (end != l->cabeca){
    printf("%d ", end->reg.chave); // soh lembrando TIPOCHAVE = int
    end = end->prox;
  }
  printf("\"\n");
} 


/* Retornar o tamanho da lista (numero de elementos "validos")  
--------------------------------------------------------------------------
**Tipo de método: int 
**Nome do método: tamanho
**Parametro(s): Ponteiro tipo Lista
**Retorno: valor do tamanho
**Função: Retornar o valor do numero de elemento na lista 
*/
int tamanho(LISTA* l) {
  PONT end = l->cabeca->prox;
  int tam = 0;
 while (end != l->cabeca){
    tam++;
    end = end->prox;
  }
  return tam;
} 


/* Retornar o tamanho em bytes da lista. Neste caso, isto depende do numero
   de elementos que estao sendo usados.   
--------------------------------------------------------------------------
**Tipo de método: int 
**Nome do método: tamanhoEmBytes
**Parametro(s): Ponteiro tipo Lista
**Retorno: Returna o tamanho em bytes da lista 
**Função: Calcular o tamanho da lista 
*/
int tamanhoEmBytes(LISTA* l) {
  return((tamanho(l)+1)*sizeof(ELEMENTO))+sizeof(LISTA); // sizeof(LISTA) = sizeof(PONT) pois a "LISTA" eh um ponteiro para o 1o elemento
} 


/* Busca sequencial sentinela (lista ordenada ou nao)  
--------------------------------------------------------------------------
**Tipo de método: PONT
**Nome do método: buscaSentinela
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:  adiciona um elemento no final da tabela afim de realizar um teste 
*/
PONT buscaSentinela(LISTA* l, TIPOCHAVE ch){
  PONT pos = l->cabeca->prox;
  l->cabeca->reg.chave = ch;
  while (pos->reg.chave != ch) pos = pos->prox;
  if (pos != l->cabeca) return pos;
  return NULL;
}


/* Busca sequencial (lista ordenada)  
--------------------------------------------------------------------------
**Tipo de método: PONT
**Nome do método: buscaSentinelaOrd
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:  adiciona um elemento no final da tabela afim de realizar um teste 
*/
PONT buscaSentinelaOrd(LISTA* l, TIPOCHAVE ch){
  PONT pos = l->cabeca->prox;
  l->cabeca->reg.chave = ch;
  while (pos->reg.chave < ch) pos = pos->prox;
  if (pos != l->cabeca && pos->reg.chave==ch) return pos;
  return NULL;
} 


/* Busca sequencial - funcao de exclusao (retorna no endere�o *ant o indice do
   elemento anterior ao elemento que est� sendo buscado [ant recebe o elemento
   anterior independente do elemento buscado ser ou n�o encontrado]) 
   O n� cabeca pode ser o anterior.   
--------------------------------------------------------------------------
**Tipo de método: int
**Nome do método: buscaSeqExc
**Parametro(s): Ponteiro tipo Lista, int ch e ponteiro int tipo ant
**Retorno: Se remover o item na lista retona true, se não remover, retornar false
**Função:Se ch for encontrado na lista, realiza a alteraçãp do reg anterior pelo ant
*/
PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant){
  *ant = l->cabeca;
  PONT pos = l->cabeca->prox;
  l->cabeca->reg.chave = ch; // utiliza o cabe�a como sentinela
  while (pos->reg.chave<ch){
    *ant = pos;
    pos = pos->prox;
  }
  if ((pos != l->cabeca) && (pos->reg.chave == ch)) return pos;
  return NULL;
} 


/* Exclus�o do elemento de chave indicada  
   --------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: excluirElemLista
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se remover o item na lista retona true, se não remover, retornar false
**Função:Se ch for encontrado na lista, realiza a remoção 
*/
bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
  PONT ant, i;
  i = buscaSeqExc(l,ch,&ant);
  if (i == NULL) return false;  // elemento a ser excluido nao existe
  ant->prox = i->prox;
  free(i);
  return true;
}


/* Destrui��o da lista sequencial 
   libera a memoria de todos os elementos da lista 
--------------------------------------------------------------------------
**Tipo de método: Void
**Nome do método: reinicializarLista
**Parametro(s): Ponteiro tipo Lista
**Retorno: Nenhum
**Função: Resetar a lista e libera memória
*/
void reinicializarLista(LISTA* l) {
  PONT end = l->cabeca->prox;
  while (end != l->cabeca){
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->cabeca->prox = l->cabeca;
} 


/* Inser��o em lista ordenada sem duplica��o  
   --------------------------------------------------------------------------
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: inserirElemListaOrd
**Parametro(s): Ponteiro tipo Lista e valor do registro
**Retorno: Se adicionar o item na lista retona true, se não adicionar ou se o elemento existir, retornar false
**Função: Realizar a inserção na lista atraves de busca sequencial 
*/
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  PONT ant, i;
  i = buscaSeqExc(l,reg.chave,&ant);
  if (i != NULL) return false;
  i = (PONT) malloc(sizeof(ELEMENTO));
  i->reg = reg;
  i->prox = ant->prox;
  ant->prox = i;
  return true;
} 


/* retornarPrimeiro - retorna o endereco do primeiro elemento da lista e (caso
   a lista nao esteja vazia) retorna a chave desse elemento na memoria 
   apontada pelo ponteiro ch  
   --------------------------------------------------------------------------
**Tipo de método: PONT
**Nome do método: retornarPrimeiro
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: o primeiro nó
**Função: Realizar a busca do primeiro elemento na lista 
*/
PONT retornarPrimeiro(LISTA* l, TIPOCHAVE* ch){
  if (l->cabeca->prox != l->cabeca) *ch = l->cabeca->prox->reg.chave;
  return l->cabeca->prox;
} 


/* retornarUltimo - retorna o endereco do ultimo elemento da lista e (caso
   a lista nao esteja vazia) retorna a chave desse elemento na memoria 
   apontada pelo ponteiro ch  
   --------------------------------------------------------------------------
**Tipo de método: PONT
**Nome do método: retornarUltimo
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: o ultimo nó
**Função: Realizar a busca do ultimo elemento na lista 
*/
PONT retornarUltimo(LISTA* l, TIPOCHAVE* ch){
  PONT ultimo = l->cabeca->prox;
  if (ultimo == l->cabeca) return NULL;
  while (ultimo->prox != l->cabeca) ultimo = ultimo->prox;
  *ch = ultimo->reg.chave;
  return ultimo;
} 
