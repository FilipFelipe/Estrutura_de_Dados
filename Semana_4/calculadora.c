/******************************************************************************
//     usaPilhaDinamica.c
// Este programa interage com o usuario para o gerenciamento de uma pilha.
******************************************************************************/
#include "pilhaDinamica.c"
#include <stdio.h>
#include <stdlib.h>

void calculadora(PILHA *p)
{

  char entrada[10] = "";
  scanf("%s", entrada);
  while (entrada[0] != 'q')
  {
    if(entrada[0] == 'C') {
      reinicializarPilha(p);
    }
    if (entrada[0] == '+' || entrada[0] == '-' || entrada[0] == '*' || entrada[0] == '/')
    {
      TIPOCHAVE res;
      calcula(p, entrada[0]);
      retornarTopo(p, &res);
      printf("Resultado = %.2f\n", res);
    }
    else if (entrada[0] == 'q')
    {
      break;
    }
    else
    {
      float valor = atof(entrada);
      REGISTRO reg;
      reg.chave = valor;
      inserirElemPilha(p, reg);
    }
    scanf("%s", entrada);
  }
}

void inserir(PILHA *l)
{
  TIPOCHAVE ch;
  scanf("%f", &ch);
  REGISTRO reg;
  reg.chave = ch;
  if (inserirElemPilha(l, reg))
    printf("Elemento %f inserido corretamente.\n", ch);
  else
    printf("Nao foi possivel inserir elemento %f.\n", ch);
}

void exibirTopo(PILHA *l)
{
  TIPOCHAVE ch;
  PONT posicao = retornarTopo(l, &ch);
  if (posicao != NULL)
    printf("Elemento %f encontrado no endereco %p.\n", ch, posicao);
  else
    printf("Nao foi possivel encontrar nenhum elemento (pilha vazia).\n");
}

void excluir(PILHA *l)
{
  REGISTRO temp;
  if (excluirElemPilha(l, &temp))
    printf("Elemento %f excluido corretamente.\n", temp.chave);
  else
    printf("Nao foi possivel excluir elemento (pilha vazia).\n");
}

void exibir(PILHA *l)
{
  exibirPilha(l);
}

void meuLog(PILHA *l)
{
  printf("Numero de elementos na pilha: %i.\n", tamanho(l));
  printf("Tamanho da pilha (em bytes): %i.\n", tamanhoEmBytes(l));
}

void help()
{
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1\n");
  printf("   e : excluir topo da pilha\n");
  printf("   p : imprimir pilha\n");
  printf("   d : destruir (zerar) pilha\n");
  printf("   l : exibir log de utilizacao da pilha\n");
  printf("   c : Calculadora\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   0 : exibir a chave e o endereco do primeiro elemento\n");
  printf("   q : sair\n");
}

void destruir(PILHA *l)
{
  reinicializarPilha(l);
  printf("Pilha zerada.\n");
}

int main()
{
  PILHA pilha;
  inicializarPilha(&pilha);
  help();
  char comando = ' ';
  scanf("%c", &comando);
  while (comando != 'q')
  {
    switch (comando)
    {
    case 'i':
      inserir(&pilha);
      break;
    case 'e':
      excluir(&pilha);
      break;
    case 'p':
      exibir(&pilha);
      break;
    case 'd':
      destruir(&pilha);
      break;
    case 'l':
      meuLog(&pilha);
      break;
    case 'c':
      calculadora(&pilha);
      break;
    case 'h':
      help();
      break;
    case '0':
      exibirTopo(&pilha);
      break;

    default:
    {
      while (comando != '\n')
        scanf("%c", &comando);
    };
    }
    scanf("%c", &comando);
  }

  return 0;
}