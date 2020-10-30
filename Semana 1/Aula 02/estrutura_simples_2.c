//Código da aula 2 
//estrutura_simples2.c
#include <stdio.h>                                                            //Importa a lib stdio.h
#include <malloc.h>                                                           //Importa a lib malloc.h
#define alturaMaxima 225                                                      //Define a variável como 255

typedef struct                                                                //Criação da estrtura 
{
    int peso;   // peso em quilogramas                                        //Declara a variável int peso na estrutura 
    int altura; // altura em centimetros                                      //Declara a variável int altura na estrutura 
} PesoAltura;                                                                 //Nome da estrutura 

int main()                                                                    //Método Principal do programa
{
    int x;                                                                    //Declara a variável int x
    PesoAltura *pessoa1;                                                      //Declara um ponteiro do tipo PesoAltura  
    printf("Valor inicial do endereco: %p\n", pessoa1);                       //Mostra na tela o endereço de pessoa1
    pessoa1 = (PesoAltura *)malloc(sizeof(PesoAltura));                       //Aloca na memória o ponteiro
    printf("Peso: %i, Altura %i. ", pessoa1->peso, pessoa1->altura);          //Mostra na tela valor do peso e altura através do ponteiro 
    pessoa1->peso = 80;                                                       //Atribui peso=80 através do ponteiro
    pessoa1->altura = 185;                                                    //Atribui altura = 185 através do ponteiro

    printf("Peso: %i, Altura %i. ", pessoa1->peso, pessoa1->altura);          //Mostra na tela valor do peso e altura através do ponteiro 
    if (pessoa1->altura > alturaMaxima)                                       //Verifica se altura é maior que alturaMaxima(255)
    {
        printf("Altura acima da maxima.\n");                                  //Se for maior, mostra na tela "Altura acima da maxima"
    }
    else{
        printf("Altura abaixo da maxima.\n");                                 //Se a altura não maior, mostra na tela "Altura abaixo da maxima."
    }
        
    printf("Enderecos: %p %p %p\n", &x, &pessoa1, pessoa1);                   //Mostra na tela os endereços de memória
    return 0;
}










