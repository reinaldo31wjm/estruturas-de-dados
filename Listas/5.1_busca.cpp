#include <stdio.h>
#include <stdlib.h>

char letra[13];
int posicao;

void exibe() {
    for (posicao = 0; posicao < 13; posicao++) {
        printf("Na posicao %d esta a letra: %c\n", posicao, letra[posicao]);
    }
    system("pause");
}

void ordena() {
    char troca;
    int qtdtrocas = 0;
    bool valida = false;

    do {
        valida = false;
        for (posicao = 0; posicao < 12; posicao++) {
            if (letra[posicao] > letra[posicao + 1]) {
                qtdtrocas++;
                troca = letra[posicao];
                letra[posicao] = letra[posicao + 1];
                letra[posicao + 1] = troca;
                valida = true;
            }
        }
    } while (valida);
    printf("\nQtd. de trocas: %d\n", qtdtrocas);
}

void buscaBinaria() {
    char busca;
    int inicio = 0;
    int fim = 12;
    int meio;
    bool encontrado = false;

    printf("\nInforme a letra que deseja buscar: ");
    scanf(" %c", &busca);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (letra[meio] == busca) {
            printf("\nLetra '%c' encontrada na posicao %d!\n", busca, meio);
            encontrado = true;
            break;
        } else if(letra[meio] < busca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (encontrado == false) {
        printf("\nLetra '%c' nao foi encontrada no vetor.\n", busca);
    }
}

int main() {
    for (posicao = 0; posicao < 13; posicao++) {
        printf("Informe a letra da posicao %d: ", posicao);
        scanf(" %c", &letra[posicao]);
    }

    printf("\n*** Exibe desordenado ***\n");
    exibe();
    ordena();
    printf("\n*** Exibe apos ordenacao ***\n");
    exibe();
    printf("\n*** Executando Busca Binaria ***\n");
    buscaBinaria();
    return 0;
}
