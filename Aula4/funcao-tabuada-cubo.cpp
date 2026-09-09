#include <stdio.h>
#include <locale.h>

void tabuada(int num) {
    printf("\nTabuada do %d:\n", num);
    for (int i=1; i<=10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

int cubo(int num) {
    return num * num * num;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int numero;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    tabuada(numero);
    
    printf("\nO cubo de %d é: %d\n", numero, cubo(numero));
    return 0;
}
