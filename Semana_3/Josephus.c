#include "listaLigadaCabCirc.c"
#include <stdio.h>
#include <locale.h>

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
    setlocale(LC_ALL, "Portuguese");
    inicializarLista(&lista_soldados);
    printf("Número de participante na roda: ");
    scanf("%i", &Soldados);
    elementos(Soldados);
    printf("Posições: ");
    exibirLista(&lista_soldados);
    josepheus(&lista_soldados);
    return 0;
}
