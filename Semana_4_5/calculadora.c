/******************************************************************************
//     usaPilhaDinamica.c
// Este programa interage com o usuario para o gerenciamento de uma pilha.
******************************************************************************/
#include "pilhaDinamica.c"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calculadora(PILHA *p)
{
  system("cls||clear");
  inicio_calculadora(0);
  char entrada[10] = "";
  scanf("%s", entrada);
  while (entrada[0] != 'q')
  {
    system("cls||clear");
    inicio_calculadora(1);
     if(entrada[0] == 'C') {
      reinicializarPilha(p);
    }
else if(entrada[0] == 'm') {
       exibirPilha(p);
    }
    else if (entrada[0] == '+' || entrada[0] == '-' || entrada[0] == '*' || entrada[0] == '/')
    {
      TIPOCHAVE res;
      calcula(p, entrada[0]);
      retornarTopo(p, &res);
      printf("\nResultado = %.2f\n", res);
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

void exibir(PILHA *l)
{
  exibirPilha(l);
}



void help()
{
  printf("**** Calculadora HP Financeira ****\n");
  printf(" \n\n");
  printf("   c : Calculadora\n");
  printf("   q : sair\n\n");
  printf("                                             \n");
  printf("Digite uma fun��o:");
}

void inicio_calculadora(int op){
    if (op ==0){
        printf("**** Modo Calculadora ****\n\n");
        printf("   Opera��es: + - * / \n");
        printf("   Valores: de 3,4E-38 at� 3.4E+38 \n");
        printf("   q : sair \n\n");
        printf("----------------------------------------\n");
        printf("Digite uma fun��o:");
    }
    else if (op == 1){
        printf("**** Modo Calculadora ****\n\n");
        printf("   Opera��es: + - * / \n");
        printf("   Valores: de 3,4E-38 at� 3.4E+38 \n");
        printf("   m : Mostrar pilha da calculadora \n");
        printf("   q : sair \n\n");
        printf("* Registrado com sucesso! *\n\n");
        printf("----------------------------------------\n");
        printf("Digite uma fun��o:");
    }
    else {
        printf("ERRO\n\n");
    }
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  PILHA pilha;
  inicializarPilha(&pilha);
  help();
  char comando = ' ';
  scanf("%c", &comando);
  while (comando != 'q')
  {
    switch (comando)
    {
    case 'c':
      calculadora(&pilha);
      break;
     case 'q':
      calculadora(&pilha);
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
