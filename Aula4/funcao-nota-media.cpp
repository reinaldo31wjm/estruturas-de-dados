#include <stdio.h>
#include <locale.h>

double calc_media(double p1, double p2, double at) {
    return (p1 + p2) * 0.35 + at;
}

void exibir(double m) {
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Média: %.2f\n", m);
    printf("Status: %s\n", (m >= 6.0) ? "Aprovado" : "Reprovado");
}

void substitutiva(double *p1, double *p2, double at) {
    double *menor = (*p1 < *p2) ? p1 : p2;

    printf("A substitutiva substituirá a %s.\n", (*p1 < *p2) ? "P1" : "P2");
    printf("Digite a nota da substitutiva: ");
    scanf("%lf", menor);

    exibir(calc_media(*p1, *p2, at));
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    double p1, p2, at;

    printf("Digite a nota da P1: ");
    scanf("%lf", &p1);
    printf("Digite a nota da P2: ");
    scanf("%lf", &p2);
    printf("Digite a nota das atividades: ");
    scanf("%lf", &at);

    double m = calc_media(p1, p2, at);

    if (m < 6.0) {
        printf("\nMédia atual: %.2f (Abaixo do mínimo 6.0)\n", m);
        substitutiva(&p1, &p2, at);
    } else {
        exibir(m);
    }

    return 0;
}
