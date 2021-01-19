#include <stdio.h>
#include <stdlib.h>

void gnome_sort(int *vetor, int tamanho)
{
    int temporario;
    for (int i = 1; i < tamanho;)
    {
        if (vetor[i - 1] <= vetor[i])
            ++i;
        else
        {
            temporario = vetor[i];
            vetor[i] = vetor[i - 1];
            vetor[i - 1] = temporario;
            --i;
            if (i == 0)
                i = 1;
        }
    }
}

int imprime_vetor(int *vetor, int tamanho, int inicio)
{

    if (inicio == 0){
        printf("Vetor Original:\n");
    }
    else if (inicio == 1){
        printf("Vetor Ordenada:\n");
    }
    for (int i = 0; i < n; i++){
        printf("%d%s", vetor[i], i == tamanho - 1 ? "\n\n" : " ");
    }
    return 0;
}

int main(void)
{
    //Define o Vetor com os elementos
    int vetor[] = {5, -1, 101, -4, 0, 1, 8, 6, 2, 3};
    //Calcula o tamanho do Vetor
    size_t tamanho = sizeof(vetor) / sizeof(vetor[0]);

    imprime_Vetor(vetor, tamanho, 0);

    gnome_sort(vetor, tamanho);

    imprime_Vetor(vetor, tamanho, 1);
    return 0;
}
