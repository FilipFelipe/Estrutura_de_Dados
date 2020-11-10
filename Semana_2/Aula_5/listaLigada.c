/******************************************************************************
//     listaLigadaEstatica.c
// Este programa gerencia listas lineares ligadas (implementacao estatica).
// As listas gerenciadas podem ter MAX elementos (posicoes de 0 a MAX-1 no
//   arranjo A). N�o usaremos sentinela nesta estrutura.
******************************************************************************/
#include <stdio.h>
#define MAX 50
#define INVALIDO -1
#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct{
  REGISTRO reg;
  int prox;
} ELEMENTO;

typedef struct {
  ELEMENTO A[MAX];
  int inicio;
  int dispo;
} LISTA;


/* Inicialização da lista sequencial (a lista já está criada e é apontada 
pelo endereço em l)
--------------------------------------------------------------------------
**Tipo de método: Void 
**Nome do método: inicializarLista 
**Parametro(s): Ponteiro tipo Lista 
**Retorno: Nenhum 
**Função: Atribui os valores na lista
*/
void inicializarLista(LISTA* l){
  int i;
  l->inicio=INVALIDO;
  l->dispo=0;
  for (i=0; i<MAX-1; i++)
    l->A[i].prox = i + 1;
  l->A[MAX-1].prox = INVALIDO;
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
  int i = l->inicio;
  printf("Lista: \" ");
  while (i != INVALIDO){
    printf("%d ", l->A[i].reg.chave); // soh lembrando TIPOCHAVE = int
    i = l->A[i].prox;
  }
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
  int i = l->inicio;
  int tam = 0;
  while (i != INVALIDO){
    tam++;
    i = l->A[i].prox;
  }
  return tam;
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


/* Busca sequencial em lista ordenada ou não SEM SENTINELA 
--------------------------------------------------------------------------
**Tipo de método: int
**Nome do método: buscaSeq
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se achar o item na lista retona o valor, se não achar, retornar erro
**Função:Fazer o busca sequencial para verifar se há na lista 
 */
int buscaSeq(LISTA* l, TIPOCHAVE ch){
  int i = l->inicio;
  while (i != INVALIDO){
    if (l->A[i].reg.chave == ch) return i;
    i = l->A[i].prox;
  }
  return INVALIDO;
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
int buscaSeqExc(TIPOCHAVE ch, LISTA* l, int *ant){
  *ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<ch)){
    *ant = i;
    i = l->A[i].prox;
  }
  if ((i != INVALIDO) && (l->A[i].reg.chave == ch)) return i;
  return INVALIDO;
} 


/* Obter n� dispon�vel e marc�-lo como n�o dispon�vel - esta opera��o ser� usada
  junto com inser��es, por exemplo
     --------------------------------------------------------------------------
**Tipo de método: int
**Nome do método: obterNo
**Parametro(s): Ponteiro tipo Lista
**Retorno: inteiro
**Função:Atribuir nó como disponível para inserções
*/
int obterNo(LISTA* l){
  int resultado = l->dispo;
  if (l->dispo != INVALIDO) l->dispo = l->A[l->dispo].prox;
  return resultado;
} 


/* Devolver n� da posi��o j para a lista de n�s dispon�veis - coloca-se o n� j
   como primeiro na lista de dispon�veis      
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: devolverNo
**Parametro(s): Ponteiro tipo Lista
**Retorno: nenhum
**Função:Atribui nó j como disponível para inserções
*/
void devolverNo(LISTA* l, int j){
     l->A[j].prox = l->dispo;
     l->dispo = j;
} 


/* Exclusão do elemento da lista 
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: excluirElemLista
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se remover o item na lista retona true, se não remover, retornar false
**Função:Se ch for encontrado na lista, realiza a remoção 
*/
bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
  int ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<ch)){
    ant = i;
    i = l->A[i].prox;
  }
  if (i==INVALIDO || l->A[i].reg.chave!=ch) return false;
  if (ant == INVALIDO) l->inicio = l->A[i].prox;
  else l->A[ant].prox = l->A[i].prox;
  devolverNo(l,i);
  return true;
} 


/* Exclus�o do elemento de chave indicada 
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: excluirElemLista2
**Parametro(s): Ponteiro tipo Lista e int ch
**Retorno: Se remover o item na lista retona true, se não remover, retornar false
**Função:Se ch for encontrado na lista, realiza a remoção
*/
bool excluirElemLista2(LISTA* l, TIPOCHAVE ch){
  int ant, i;
  i = buscaSeqExc(ch, l, &ant);
  if (i == INVALIDO) return false;
  if (ant == INVALIDO) l->inicio = l->A[i].prox;
  else l->A[ant].prox = l->A[i].prox;
  devolverNo(l,i);
  return true;
} 


/* Reinicializar a estrutura 
--------------------------------------------------------------------------
**Tipo de método: Void
**Nome do método: reinicializarLista
**Parametro(s): Ponteiro tipo Lista
**Retorno: Nenhum
**Função: Resetar a lista chamando o método inicializarLista(l)
*/
void reinicializarLista(LISTA* l) {
  inicializarLista(l);
}


/* Inser��o em lista ordenada usando busca bin�ria sem duplica��o 
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: inserirElemListaOrd
**Parametro(s): Ponteiro tipo Lista e valor do registro
**Retorno: Se adicionar o item na lista retona true, se não adicionar ou se o elemento existir, retornar false
**Função: Realizar a inserção na lista atraves de busca sequencial 
*/
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if (l->dispo == INVALIDO) return false; // se lista cheia, n�o � poss�vel inserir
   int ant, i;
  i = buscaSeqExc(reg.chave, l, &ant);
  if (i!=INVALIDO) return false;
  i = obterNo(l);
  l->A[i].reg = reg;
  if (ant == INVALIDO) { // o novo elemento ser� o 1o da lista (a lista podia estar vazia ou n�o)
    l->A[i].prox = l->inicio;
    l->inicio = i;
  } else {  // inser��o ap�s um elemento j� existente
    l->A[i].prox = l->A[ant].prox;
    l->A[ant].prox = i;
  }  
  return true;
} 


/* Inser��o em lista ordenada sem duplica��o - n�o utilize o m�todo auxiliar 
--------------------------------------------------------------------------
**Tipo de método: bool
**Nome do método: inserirElemListaOrd2
**Parametro(s): Ponteiro tipo Lista e valor do registro
**Retorno: Se adicionar o item na lista retona true, se não adicionar ou se o elemento existir, retornar false
**Função: Realizar a inserção na lista sem método auxiliar 
*/
bool inserirElemListaOrd2(LISTA* l, REGISTRO reg) {
  if (l->dispo == INVALIDO) return false; // se lista cheia, n�o � poss�vel inserir
  int ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<reg.chave)){
    ant = i;
    i = l->A[i].prox;
  }
  if (i!=INVALIDO && l->A[i].reg.chave==reg.chave) return false;
  i = obterNo(l);
  l->A[i].reg = reg;
  if (ant == INVALIDO) { // o novo elemento ser� o 1o da lista (a lista podia estar vazia ou n�o)
    l->A[i].prox = l->inicio;
    l->inicio = i;
  } else {  // inser��o ap�s um elemento j� existente
    l->A[i].prox = l->A[ant].prox;
    l->A[ant].prox = i;
  }  
  return true;
} 
