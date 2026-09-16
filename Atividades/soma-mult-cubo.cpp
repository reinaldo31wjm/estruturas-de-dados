#include <stdio.h>
#include <locale.h>

float fsoma(float p1, float p2) {
    return (p1 + p2) + 10.0;
}
float fmult(float res_soma, float p3) {
    return (res_soma + p3) * 3.0;
}
float fcubo(float res_mult) {
    return res_mult * res_mult * res_mult;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    float p1, p2, p3;

    printf("Digite o 1º número: ");
    scanf("%f", &p1);
    printf("Digite o 2º número: ");
    scanf("%f", &p2);
    printf("Digite o 3º número: ");
    scanf("%f", &p3);
    
    float res_s = fsoma(p1, p2);
    float res_m = fmult(res_s, p3);
    float res_c = fcubo(res_m);

    printf("O resultado final é: %.2f\n", res_c);
    return 0;
}
