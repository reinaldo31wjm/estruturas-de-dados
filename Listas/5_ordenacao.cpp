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
    return 0;
}
