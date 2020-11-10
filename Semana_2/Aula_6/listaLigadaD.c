/******************************************************************************
//     listaLigadaD.c
// Este programa gerencia listas lineares ligadas (implementacao dinamica).
// As listas gerenciadas podem ter um numero arbitrario de elementos.
// N�o usaremos sentinela nesta estrutura.
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
  PONT inicio;
} LISTA;


/* Inicializa��o da lista ligada (a lista jah esta criada e eh apontada 
pelo endereco em l)    
--------------------------------------------------------------------------
**Tipo de método: Void 
**Nome do método: inicializarLista 
**Parametro(s): Ponteiro tipo Lista 
**Retorno: Nenhum 
**Função: Atribui inicio = NULL
*/
void inicializarLista(LISTA* l){
  l->inicio = NULL;
} /* inicializarLista */


/* Exibi��o da lista seq�encial    
--------------------------------------------------------------------------
**Tipo de método: Void 
**Nome do método: exibirLista 
**Parametro(s): Ponteiro tipo Lista 
**Retorno: Nenhum 
**Função: Mostra na tela a lista inteira
*/
void exibirLista(LISTA* l){
  PONT end = l->inicio;
  printf("Lista: \" ");
  while (end != NULL){
    printf("%d ", end->reg.chave); // soh lembrando TIPOCHAVE = int
    end = end->prox;
  }
  printf("\"\n");
} 


/* Retornar o tamanho da lista (numero de elementos)    
--------------------------------------------------------------------------
**Tipo de método: int 
**Nome do método: tamanho
**Parametro(s): Ponteiro tipo Lista
**Retorno: valor do tamanho
**Função: Retornar o valor do numero de elemento na lista 
*/
int tamanho(LISTA* l) {
  PONT end = l->inicio;
  int tam = 0;
  while (end != NULL){
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
  return(tamanho(l)*sizeof(ELEMENTO))+sizeof(LISTA); // sizeof(LISTA) = sizeof(PONT) pois a "LISTA" possui apenas um ponteiro para o 1o elemento
} 


/* Busca sequencial (lista ordenada ou nao)    
--------------------------------------------------------------------------
**Tipo de método: int
**Nome do método: buscaSequencial
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:Fazer o busca sequencial para verifar se há na lista 
 */
PONT buscaSequencial(LISTA* l, TIPOCHAVE ch){
  PONT pos = l->inicio;
  while (pos != NULL){
    if (pos->reg.chave == ch) return pos;
    pos = pos->prox;
  }
  return NULL;
} 


/* Busca sequencial (lista ordenada)    
--------------------------------------------------------------------------
**Tipo de método: PONT
**Nome do método: buscaSeqOrd
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:Fazer o busca sequencial ordenada para verifar se há na lista 
 */
PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch){
  PONT pos = l->inicio;
  while (pos != NULL && pos->reg.chave < ch) pos = pos->prox;
  if (pos != NULL && pos->reg.chave == ch) return pos;
  return NULL;
} 


/* Busca sequencial - funcao de exclusao (retorna no endere�o *ant o indice do
   elemento anterior ao elemento que est� sendo buscado [ant recebe o elemento
   anterior independente do elemento buscado ser ou n�o encontrado])    
--------------------------------------------------------------------------
**Tipo de método: int
**Nome do método: buscaSeqExc
**Parametro(s): Ponteiro tipo Lista, int ch e ponteiro int tipo ant
**Retorno: Se remover o item na lista retona true, se não remover, retornar false
**Função:Se ch for encontrado na lista, realiza a alteraçãp do reg anterior pelo ant
*/
PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant){
  *ant = NULL;
  PONT atual = l->inicio;
  while (atual != NULL && atual->reg.chave<ch){
    *ant = atual;
    atual = atual->prox;
  }
  if ((atual != NULL) && (atual->reg.chave == ch)) return atual;
  return NULL;
}


/* Exclus�o do elemento de chave indicada 
**Tipo de método: bool
**Nome do método: excluirElemLista
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se remover o item na lista retona true, se não remover, retornar false
**Função:Se ch for encontrado na lista, realiza a remoção 
*/
bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
  PONT ant, i;
  i = buscaSeqExc(l,ch,&ant);
  if (i == NULL) return false;
  if (ant == NULL) l->inicio = i->prox;
  else ant->prox = i->prox;
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
  PONT end = l->inicio;
  while (end != NULL){
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->inicio = NULL;
} 


/* Inser��o em lista ordenada sem duplica��o   
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: inserirElemListaOrd
**Parametro(s): Ponteiro tipo Lista e valor do registro
**Retorno: Se adicionar o item na lista retona true, se não adicionar ou se o elemento existir, retornar false
**Função: Realizar a inserção na lista atraves de busca sequencial 
*/
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  TIPOCHAVE ch = reg.chave;
  PONT ant, i;
  i = buscaSeqExc(l,ch,&ant);
  if (i != NULL)  return false;
  i = (PONT) malloc(sizeof(ELEMENTO));
  i->reg = reg;
  if (ant == NULL) { // o novo elemento serah o 1o da lista
    i->prox = l->inicio;
    l->inicio = i;
  } else {  // inser��o ap�s um elemento j� existente
    i->prox = ant->prox;
    ant->prox = i;
  }  
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
PONT retornarPrimeiro(LISTA* l, TIPOCHAVE *ch){
  if (l->inicio != NULL) *ch = l->inicio->reg.chave;
  return l->inicio;
} /* retornarPrimeiro */


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
PONT retornarUltimo(LISTA* l, TIPOCHAVE *ch){
  PONT ultimo = l->inicio;
  if (l->inicio == NULL) return NULL;
  while (ultimo->prox != NULL) ultimo = ultimo->prox;
  *ch = ultimo->reg.chave;
  return ultimo;
}



