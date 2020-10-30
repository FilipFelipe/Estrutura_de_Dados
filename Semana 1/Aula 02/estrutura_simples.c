//Código da aula 2 
//estrutura_simples.c
#include <stdio.h>                                                      //Importa a lib stdio.h
#define alturaMaxima 225                                                //Define a variável como 255

typedef struct                                                          //Criação da estrtura 
{
    int peso;   // peso em quilogramas                                  //Declara a variável int peso na estrutura 
    int altura; // altura em centimetros                                //Declara a variável int altura na estrutura 

} PesoAltura;                                                           //Nome da estrutura 

int main()                                                              //Método Principal do programa
{
    int x;                                                              //Declara a variável int x
    PesoAltura pessoa1;                                                 //Declara variável do tipo PesoAltura  
    pessoa1.peso = 80;                                                  //Atribui pessoa1.peso = 80  
    pessoa1.altura = 185;                                               //Atribui pessoa1.altura = 185  
    printf("Peso: %i, Altura %i. ", pessoa1.peso, pessoa1.altura);      //Mostra na tela os valores do Peso e da Altura 
    if (pessoa1.altura > alturaMaxima){                                 //Verifica se altura é maior que alturaMaxima(255)
        printf("Altura acima da maxima.\n");                            //Se for maior, mostra na tela "Altura acima da maxima"
    }
    else{                                                              
        printf("Altura abaixo da maxima.\n");                           //Se a altura não maior, mostra na tela "Altura abaixo da maxima."
    }
    printf("%p %p %p\n", &x, &pessoa1, &(pessoa1.altura));              //Mostra na tela os endereços de memória da variável X, Pessoa1 e Pessoa1.altura
    return 0;
}
