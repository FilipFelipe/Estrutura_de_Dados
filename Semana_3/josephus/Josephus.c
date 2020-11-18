#include "listaLigadaCabCirc.c"
#include <stdio.h>

LISTA lista_soldados;
int Soldados;

void elementos(int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        REGISTRO reg;
        reg.chave = i + 1;
        inserirElemListaOrd(&lista_soldados, reg);
    }
}
int main()
{
    inicializarLista(&lista_soldados);
    printf("Numero de participante na roda: ");
    scanf("%i", &Soldados);
    elementos(Soldados);
    printf("Posicoes: ");
    exibirLista(&lista_soldados);
    josepheus(&lista_soldados);
    return 0;
}
