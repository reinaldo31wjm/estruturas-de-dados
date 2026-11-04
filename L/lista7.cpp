#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

struct ficha
{
  char nome[40];
  char cpf[15];
  char rg[15];
  int codigo;
  ficha *proximo;
};

typedef ficha* endmem;

void ExibeFicha(endmem f)
{
  printf("Codigo: %d\n", f->codigo);
  printf("Nome: %s\n", f->nome);
  printf("CPF: %s\n", f->cpf);
  printf("RG: %s\n", f->rg);
}

void Exibe(endmem primeiro)
{
  endmem aux;
  aux = primeiro;
  while (aux != NULL)
  {
    ExibeFicha(aux);
    printf("--------------------\n");
    aux = aux->proximo;
  }
}

endmem ApagaPrimeiro(endmem primeiro)
{
  endmem aux;
  if (primeiro != NULL)
  {
    aux = primeiro;
    primeiro = primeiro->proximo;
    delete aux;
  }
  return primeiro;
}

int main()
{
  endmem inicioFila, fichaAnterior, auxiliarFicha;
  char cliente[40];
  char cpf[15];
  char rg[15];
  int codigo;
  char resp = 'S';

  inicioFila = NULL;
  fichaAnterior = NULL;

  while (resp == 'S')
  {
    printf("\nInforme o nome do cliente: \n");
    scanf("%s", cliente);
    printf("Informe o CPF: \n");
    scanf("%s", cpf);
    printf("Informe o RG: \n");
    scanf("%s", rg);
    printf("Informe o codigo: \n");
    scanf("%d", &codigo);

    auxiliarFicha = new ficha;
    strcpy(auxiliarFicha->nome, cliente);
    strcpy(auxiliarFicha->cpf, cpf);
    strcpy(auxiliarFicha->rg, rg);
    auxiliarFicha->codigo = codigo;
    auxiliarFicha->proximo = NULL;
    if (inicioFila == NULL)
    {
      inicioFila = auxiliarFicha;
    }
    else
    {
      fichaAnterior->proximo = auxiliarFicha;
    }
    fichaAnterior = auxiliarFicha;

    printf("\nRegistro inserido:\n");
    ExibeFicha(auxiliarFicha);

    printf("\nInforme S para continuar \n ");
    scanf(" %c", &resp);
  }

  printf("\nRegistros cadastrados:\n");
  Exibe(inicioFila);

  printf("\nDeseja apagar o primeiro registro? (S/N): \n");
  scanf(" %c", &resp);
  if (resp == 'S')
  {
    inicioFila = ApagaPrimeiro(inicioFila);
    printf("\nPrimeiro registro apagado.\n");
  }

  printf("\nRegistros atuais:\n");
  Exibe(inicioFila);

  system("pause");
  return 0;
}
