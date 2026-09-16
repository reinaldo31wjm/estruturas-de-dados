#include <stdio.h>
#include <locale.h>

int fsoma(int p1, int p2) {
    return (p1 + p2) + 10;
}
int fmult(int res_soma, int p3) {
    return (res_soma + p3) * 3;
}
int fcubo(int res_mult) {
    return res_mult * res_mult * res_mult;
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    int p1, p2, p3;

    printf("Digite o 1º número: ");
    scanf("%d", &p1);
    printf("Digite o 2º número: ");
    scanf("%d", &p2);
    printf("Digite o 3º número: ");
    scanf("%d", &p3);
    
    int res_s = fsoma(p1, p2);
    int res_m = fmult(res_s, p3);
    int res_c = fcubo(res_m);
    
    printf("O resultado final é: %d\n", res_c);
    return 0;
}
