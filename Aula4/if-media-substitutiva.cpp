#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    float p1, p2, at, media;

    printf("Informe a nota da P1: ");
    scanf("%f", &p1);
    printf("Informe a nota da P2: ");
    scanf("%f", &p2);
    printf("Informe a pontuação das atividades: ");
    scanf("%f", &at);

    media = p1 * 0.35 + p2 * 0.35 + at;
    printf("\nMédia: %.2f\n", media);

    if (media >= 6){
        printf("Aluno Aprovado!\n");
    } else if (p2 > p1){
        printf("Prova substitutiva referente à P1.\n");
    } else {
        printf("Prova substitutiva referente à P2.\n");
    }
    return 0;
}

