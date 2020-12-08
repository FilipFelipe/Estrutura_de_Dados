#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include "filaDinamica.c"

void menu(FILA *filaV, REGISTRO *reg)
{
    system("clear||cls");

    printf("----------------------------------------\n");
    printf("              FILA VIRTUAL              \n");
    printf("----------------------------------------\n\n");

    printf("S - Pegar Senha\n");
    printf("C - Chamar Próximo\n");
    printf("M - Mostrar Fila\n");
    printf("E - Reiniciar Fila\n");
    printf("Q - Sair do Programa\n\n");

    REGISTRO ch;
    retornarPrimeiro(filaV, &ch);
    if (reg->chave)
    {
        printf("Senha atual: %c%i\n", reg->tipo, reg->chave);
    }
    if (tamanho(filaV) > 0)
    {
        printf("Próxima senha: %c%i\n", ch.tipo, ch.chave);
    }
    else {
        printf("Final da fila\n");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    FILA filaV;
    char comando = ' ';

    inicializarFila(&filaV);

    REGISTRO reg;
    reg.chave = 0;
    REGISTRO aux;

    menu(&filaV, &reg);

    while (comando != 'Q')
    {
        REGISTRO senha;
        scanf(" %c", &comando);
        switch (comando)
        {
        case 's':
        case 'S':
            senha = inserirNaFila2(&filaV, 'N');
            printf("Sua senha foi gerada! Anote-a: %c%i\n", senha.tipo, senha.chave);
            sleep(2);
            menu(&filaV, &reg);
            break;

        case 'c':
        case 'C':
            excluirDaFila(&filaV, &reg);
            printf("Senha atual: %c%i\n", reg.tipo, reg.chave);
            menu(&filaV, &reg);
            break;

        case 'm':
        case 'M':
            menu(&filaV, &reg);
            exibirFila(&filaV);
            break;

        case 'e':
        case 'E':
            destruirFila(&filaV);
            menu(&filaV, &reg);
            break;

        case 'q':
        case 'Q':
            break;

        default:
            printf("Comando inválido!!!\n");
            break;
        }
    }

    return 0;
}
