#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[100];
    char conc[150];
    char alt[100];
    char cif[100];

    printf("Informe uma frase qualquer: ");
    scanf("%[^\n]", frase);
    int qtd_carac = strlen(frase);

    int qtd_vog = 0;
    int qtd_con = 0;
    int qtd_pala = 0;
    int em = 0;

    for (int i=0; i<qtd_carac; i++) {
        char c= tolower(frase[i]);

        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            qtd_vog++;
        } else if (c>='a' && c<='z'){
            qtd_con++;
        }

        if (frase[i] != ' ' && em == 0){
            em = 1;
            qtd_pala++;
        } else if (frase[i] == ' '){
            em = 0;
        }

        if (c=='a' || c=='e' || c=='i') {
            alt[i] = 'b';
        } else if (c=='o' || c =='u') {
            alt[i] = '3';
        } else {
            alt[i] = frase[i];
        }

        if (i<5){
            cif[i] = frase[i] + 3;
        } else {
            cif[i] = frase[i] - 5;
        }
    }

    alt[qtd_carac] = '\0';
    cif[qtd_carac] = '\0';

    strcpy(conc, frase);
    strcat(conc, " chuva nao");

    printf("\nRESULTADOS\n");
    printf("(02) Qtd. de caracteres: %d\n", qtd_carac);
    printf("(03) Qtd. de vogais: %d\n", qtd_vog);
    printf("(04) Qtd. de consoantes: %d\n", qtd_con);
    printf("(05) Qtd. de palavras: %d\n", qtd_pala);
    printf("(07) Frase concatenada: %s\n", conc);
    printf("(09) Frase alterada: %s\n", alt);

    printf("\n(11) RESUMO\n");
    printf("Original:    %s\n", frase);
    printf("Concatenada: %s\n", conc);
    printf("Alterada:    %s\n", alt);
    printf("Cifrada:     %s\n", cif);
    return 0;
}
