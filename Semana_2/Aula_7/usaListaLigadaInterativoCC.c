/******************************************************************************
//     usaListaLigadaInterativoCC.c
// Este programa interage com o usuario para o gerenciamento de uma lista.
******************************************************************************/
#include "listaLigadaCabCirc.c"
#include <stdio.h>

/* 
--------------------------------------------------------------------------
Programa inclui a listaLigadaCabCirc.c e realiza o gerenciamento de uma lista
--------------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: inserir
**Parametro(s): Ponteiro tipo Lista 
**Retorno: printf
**Função: Realizar a inserção na lista atraves do método inserirElemListaOrd
*/
void inserir(LISTA *l){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElemListaOrd(l,reg)) printf("Elemento %i inserido corretamente.\n",ch);
  else printf("Nao foi possivel inserir elemento %i.\n",ch);
}


/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: buscar
**Parametro(s): Ponteiro tipo Lista 
**Retorno: printf
**Função: Realizar a busca na lista atraves do método buscaSeqOrd
*/
void buscar(LISTA *l){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  PONT posicao = buscaSentinela(l,ch);
  if (posicao != NULL) printf("Elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar elemento %i.\n",ch);
}


/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: exibirPrimeiro
**Parametro(s): Ponteiro tipo Lista 
**Retorno: printf
**Função: Realizar a busca do primeiro elemento na lista atraves do método retornarPrimeiro
*/
void exibirPrimeiro(LISTA *l){
  TIPOCHAVE ch;
  PONT posicao = retornarPrimeiro(l,&ch);
  if (posicao != NULL) printf("Primeiro elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o primeiro elemento (lista vazia).\n");
}


/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: exibirUltimo
**Parametro(s): Ponteiro tipo Lista 
**Retorno: printf
**Função: Realizar a busca do ultimo elemento na lista atraves do método retornarUltimo
*/
void exibirUltimo(LISTA *l){
  TIPOCHAVE ch;
  PONT posicao = retornarUltimo(l,&ch);
  if (posicao != NULL) printf("Ultimo elemento %i encontrado no endereco %p.\n",ch,posicao);
  else printf("Nao foi possivel encontrar o ultimo elemento (lista vazia).\n");
}


/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: excluir
**Parametro(s): Ponteiro tipo Lista 
**Retorno: printf
**Função: Realizar a remoção na lista atraves do método excluirElemLista
*/
void excluir(LISTA *l){
  TIPOCHAVE ch;
  scanf("%i",&ch);
  if (excluirElemLista(l,ch)) printf("Elemento %i excluido corretamente.\n",ch);
  else printf("Nao foi possivel excluir elemento %i.\n",ch);
}


/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: exibir
**Parametro(s): Ponteiro tipo Lista 
**Retorno: exibirLista
**Função: Mostrar a lista inteira
*/
void exibir(LISTA *l){
  exibirLista(l);
}


/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: meuLog
**Parametro(s): Ponteiro tipo Lista 
**Retorno: printf
**Função: Mostra o tamanho e o tamanhoembytes
*/
void meuLog(LISTA *l){
  printf("Numero de elementos na lista: %i.\n",tamanho(l));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(l));
}


/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: help
**Parametro(s): Nenhum
**Retorno: printf
**Função: Inicia o menu
*/
void help(){
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1\n");
  printf("   e <chave1>: excluir elemento com chave=chave1\n");
  printf("   p : imprimir lista\n");
  printf("   d : destruir (zerar) lista\n");
  printf("   l : exibir log de utilizacao da lista\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   b <chave1>: exibir posicao do elemento com chave=chave1\n");
  printf("   0 : exibir a chave e o endereco do primeiro elemento\n");
  printf("   u : exibir a chave e o endereco do ultimo elemento\n");
}


/*
--------------------------------------------------------------------------
**Tipo de método: void
**Nome do método: destruir
**Parametro(s): Ponteiro tipo Lista 
**Retorno: printf
**Função: Realizar a descontrução da lista atraves do método reinicializarLista
*/
void destruir(LISTA *l){
     reinicializarLista(l);
     printf("Lista zerada.\n");
}


/*
-------------------------MAIN-------------------------------------------
*/
int main(){
  LISTA lista;
  inicializarLista(&lista);
  help();
  char comando = ' ';
  scanf("%c",&comando);
  while (comando != 'q'){
    switch (comando) {
      case 'i' : inserir(&lista); break;
      case 'e' : excluir(&lista); break;
      case 'p' : exibir(&lista); break;
      case 'd' : destruir(&lista); break;
      case 'l' : meuLog(&lista); break;
      case 'h' : help(); break;
      case 'b' : buscar(&lista); break;
      case '0' : exibirPrimeiro(&lista); break;
      case 'u' : exibirUltimo(&lista); break;

      default: {while (comando != '\n') scanf("%c",&comando);};
    } 
    scanf("%c",&comando);
  }

  return 0;
}
