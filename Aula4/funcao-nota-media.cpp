#include <stdio.h>
#include <locale.h>

float calcular_media(float p1, float p2, float at) {
    return (p1 + p2) * 0.35f + at;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    float p1, p2, at, nota_sub;

    printf("Informe a nota da P1: ");
    scanf("%f", &p1);
    printf("Informe a nota da P2: ");
    scanf("%f", &p2);
    printf("Informe a pontuação das atividades: ");
    scanf("%f", &at);

    float media = calcular_media(p1, p2, at);

    if (media < 6.0f) {
        printf("\nMédia atual: %.2f (Abaixo da média mínima)\n", media);
        
        if (p1 < p2) {
            printf("A prova substitutiva substituirá a P1.\n");
            printf("Informe a nota da substitutiva: ");
            scanf("%f", &nota_sub);
            p1 = nota_sub;
        } else {
            printf("A prova substitutiva substituirá a P2.\n");
            printf("Informe a nota da substitutiva: ");
            scanf("%f", &nota_sub);
            p2 = nota_sub;
        }
        media = calcular_media(p1, p2, at);
    }
    printf("\nRESULTADO FINAL\n");
    printf("Média: %.2f\n", media);
    printf("Status: %s\n", (media >= 6.0f) ? "Aprovado!" : "Reprovado!");
    return 0;
}
