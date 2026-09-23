#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vtCodigo[100];
float vtValor[100];
int vtEstoque[100];
char vtProduto[100][20];
int vtCodigoVenda[100];
int vtQtdVenda[100];
int qtdItens;

void fExibe() {
    int posicao;
    printf("******** Função Exibe ***************\n");
    for (posicao = 0; posicao < qtdItens; posicao++) {
        printf("O código do produto da posição %d é: %d\n", posicao, vtCodigo[posicao]);
        printf("O valor do produto da posição %d é: R$ %.2f\n", posicao, vtValor[posicao]);
        printf("A quantidade em estoque do produto da posição %d é: %d\n", posicao, vtEstoque[posicao]);
        printf("O nome do produto da posição %d é: %10s\n", posicao, vtProduto[posicao]);
    }     
}

void fVenda(int codigoBusca, int posicao) {
    int qtdCompra;
    printf("********** Função Venda *********\n");
    printf("Informe a quantidade para compra: ");
    scanf("%d", &qtdCompra);
    if (qtdCompra > vtEstoque[posicao]) {
        printf("Estoque menor que a quantidade informada.\n");        
    } else {
        printf("A quantidade comprada foi: %d\n", qtdCompra);
        vtCodigoVenda[posicao] = vtCodigo[posicao];
        vtQtdVenda[posicao] = qtdCompra;
        vtEstoque[posicao] = vtEstoque[posicao] - qtdCompra;   
    }           
}

void fBuscaCodigo() {
    int posicao;
    int codigoBusca;
    printf("*************** Função Busca *********\n");
    printf("Informe o código do produto: ");
    scanf("%d", &codigoBusca);
    for (posicao = 0; posicao < qtdItens; posicao++) {
        if (codigoBusca == vtCodigo[posicao]) {
            printf("O código do produto da posição %d é: %d\n", posicao, vtCodigo[posicao]);
            printf("O valor do produto da posição %d é: R$ %.2f\n", posicao, vtValor[posicao]);
            printf("A quantidade em estoque do produto da posição %d é: %d\n", posicao, vtEstoque[posicao]);
            printf("O nome do produto da posição %d é: %10s\n", posicao, vtProduto[posicao]);
            system("cls");
            fVenda(codigoBusca, posicao);
            fExibe();
        }
    }
}

void fInsere() {
    int posicao;
    printf("********** Função Insere ***********\n");
    for (posicao = 0; posicao < qtdItens; posicao++) {
        printf("Informe o código do produto da posição %d: ", posicao);
        scanf("%d", &vtCodigo[posicao]);
        printf("Informe o valor do produto da posição %d: ", posicao);
        scanf("%f", &vtValor[posicao]);
        printf("Informe a quantidade de estoque do produto da posição %d: ", posicao);
        scanf("%d", &vtEstoque[posicao]);
        printf("Informe o nome do produto da posição %d: ", posicao);
        scanf("%s", vtProduto[posicao]);
    }     
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("Informe a quantidade de itens: ");
    scanf("%d", &qtdItens);
    fInsere();
    fExibe();
    fBuscaCodigo();
    system("pause");   
    return 0;
}
