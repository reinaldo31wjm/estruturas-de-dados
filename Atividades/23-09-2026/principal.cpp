#include <stdio.h>
#include <stdlib.h>
#include "variaveis.h"
#include "soma.h"
#include "sub.h"
#include "div.h"
#include "mult.h"
#include "cubo.h"

int main(){
    printf("informe o codigo: ");
    scanf("%i", &codigo);
    printf("informe o valor: ");
    scanf("%i", &valor);
    printf("%i %i\n", codigo, valor);
	
	printf("\n--- RESULTADOS ---\n");
    printf("Valores informados: %i e %i\n\n", codigo, valor);
    printf("Soma: %i\n", fsoma(codigo, valor));
    printf("Subtracao: %i\n", fsub(codigo, valor));
    printf("Multiplicacao: %i\n", fmult(codigo, valor));
    printf("Divisao: %i\n", fdiv(codigo, valor));
    printf("Cubo do valor: %i\n", fcubo(codigo, valor));
    
    system("pause");
    return 0;
}
