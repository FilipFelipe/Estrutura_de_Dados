#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;
typedef struct tempRegistro
{
  REGISTRO reg;
  struct tempRegistro *prox;
} ELEMENTO;
typedef ELEMENTO *PONT;
typedef struct
{
  PONT cabeca;
} LISTA;
void inicializarLista(LISTA *l)
{
  l->cabeca = (PONT)malloc(sizeof(ELEMENTO));
  l->cabeca->prox = l->cabeca;
}
void exibirLista(LISTA *l)
{
  PONT end = l->cabeca->prox;
  printf("Lista: \" ");
  while (end != l->cabeca)
  {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}
int tamanho(LISTA *l)
{
  PONT end = l->cabeca->prox;
  int tam = 0;
  while (end != l->cabeca)
  {
    tam++;
    end = end->prox;
  }
  return tam;
}
PONT buscaSeqExc(LISTA *l, TIPOCHAVE ch, PONT *ant)
{
  *ant = l->cabeca;
  PONT pos = l->cabeca->prox;
  l->cabeca->reg.chave = ch;
  while (pos->reg.chave < ch)
  {
    *ant = pos;
    pos = pos->prox;
  }
  if ((pos != l->cabeca) && (pos->reg.chave == ch))
    return pos;
  return NULL;
}
bool inserirElemListaOrd(LISTA *l, REGISTRO reg)
{
  PONT ant, i;
  i = buscaSeqExc(l, reg.chave, &ant);
  if (i != NULL)
    return false;
  i = (PONT)malloc(sizeof(ELEMENTO));
  i->reg = reg;
  i->prox = ant->prox;
  ant->prox = i;
  return true;
}
PONT retornarPrimeiro(LISTA *l, TIPOCHAVE *ch)
{
  if (l->cabeca->prox != l->cabeca)
    *ch = l->cabeca->prox->reg.chave;
  return l->cabeca->prox;
}
void josepheus(LISTA *l)
{
  TIPOCHAVE chave;
  PONT excluir = NULL;
  PONT elemento = l->cabeca->prox;
  while (tamanho(l) > 1)
  {
    excluir = elemento->prox;
    if (excluir == l->cabeca)
    {
      excluir = l->cabeca->prox;
      l->cabeca->prox = excluir->prox;
    }
    else
    {
      elemento->prox = excluir->prox;
    }
    free(excluir);
    if (elemento->prox == l->cabeca)
    {
      elemento = l->cabeca->prox;
    }
    else
    {
      elemento = elemento->prox;
    }
  }
  retornarPrimeiro(l, &chave);
  printf("\n--------------------------------------------------------------\n", chave);
  printf("Voce deve sentar na cadeira %i para sobreviver\n", chave);
  printf("--------------------------------------------------------------", chave);
}
