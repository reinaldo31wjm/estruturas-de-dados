# Aula: Lista Encadeada em C++ (Ficha de Clientes)

Nov 4, 2026 · @Moriarty

## Objetivos da aula

Ao final, o aluno sabe montar uma fila de clientes com lista encadeada em C++, mostrar os dados de cada cliente e remover o primeiro da fila.

- Criar uma `struct` com vários campos (nome, CPF, RG e código).
- Usar ponteiros para ligar uma ficha à outra.
- Alocar memória com `new` e liberar com `delete`.
- Percorrer a lista com um laço `while`.
- Inserir no final da fila e remover do início.

## Conceitos-chave

Antes do código, a turma precisa dominar cinco ideias. Cada linha da tabela é retomada na explicação linha a linha.

| Conceito | O que é | Analogia para a turma |
| --- | --- | --- |
| `struct` | Tipo criado pelo programador, com vários campos juntos | Uma ficha de papel com espaços para nome, CPF, RG e código |
| Ponteiro | Variável que guarda o endereço de memória de outra | O número da casa, não a casa |
| `NULL` | Ponteiro que não aponta para nada | Um bilhete que diz "não há próximo" |
| Lista encadeada | Fichas ligadas: cada uma guarda o endereço da próxima | Uma fila de pessoas, cada uma segurando o ombro da seguinte |
| `new` / `delete` | Reserva e libera memória durante a execução | Alugar uma sala e devolver a chave |

Diferença importante: em um vetor, os itens ficam lado a lado na memória. Na lista encadeada, as fichas ficam espalhadas e só o ponteiro `proximo` mantém a ordem.

## Código completo

Este é o programa `Exemplo03_Ficha_CamposExtras.cpp`. A explicação linha a linha usa os mesmos números de linha.

```cpp
1   #include <stdio.h>
2   #include <stdlib.h>
3   #include <iostream>
4   #include <string.h>
5
6   struct ficha
7   {
8     char nome[40];
9     char cpf[15];
10    char rg[15];
11    int codigo;
12    ficha *proximo;
13  };
14
15  typedef ficha* endmem;
16
17  void ExibeFicha(endmem f)
18  {
19    printf("Codigo: %d\n", f->codigo);
20    printf("Nome: %s\n", f->nome);
21    printf("CPF: %s\n", f->cpf);
22    printf("RG: %s\n", f->rg);
23  }
24
25  void Exibe(endmem primeiro)
26  {
27    endmem aux;
28    aux = primeiro;
29    while (aux != NULL)
30    {
31      ExibeFicha(aux);
32      printf("--------------------\n");
33      aux = aux->proximo;
34    }
35  }
36
37  endmem ApagaPrimeiro(endmem primeiro)
38  {
39    endmem aux;
40    if (primeiro != NULL)
41    {
42      aux = primeiro;
43      primeiro = primeiro->proximo;
44      delete aux;
45    }
46    return primeiro;
47  }
48
49  int main()
50  {
51    endmem inicioFila, fichaAnterior, auxiliarFicha;
52    char cliente[40];
53    char cpf[15];
54    char rg[15];
55    int codigo;
56    char resp = 'S';
57
58    inicioFila = NULL;
59    fichaAnterior = NULL;
60
61    while (resp == 'S')
62    {
63      printf("\nInforme o nome do cliente: \n");
64      scanf("%s", cliente);
65      printf("Informe o CPF: \n");
66      scanf("%s", cpf);
67      printf("Informe o RG: \n");
68      scanf("%s", rg);
69      printf("Informe o codigo: \n");
70      scanf("%d", &codigo);
71
72      auxiliarFicha = new ficha;
73      strcpy(auxiliarFicha->nome, cliente);
74      strcpy(auxiliarFicha->cpf, cpf);
75      strcpy(auxiliarFicha->rg, rg);
76      auxiliarFicha->codigo = codigo;
77      auxiliarFicha->proximo = NULL;
78      if (inicioFila == NULL)
79      {
80        inicioFila = auxiliarFicha;
81      }
82      else
83      {
84        fichaAnterior->proximo = auxiliarFicha;
85      }
86      fichaAnterior = auxiliarFicha;
87
88      printf("\nRegistro inserido:\n");
89      ExibeFicha(auxiliarFicha);
90
91      printf("\nInforme S para continuar \n ");
92      scanf(" %c", &resp);
93    }
94
95    printf("\nRegistros cadastrados:\n");
96    Exibe(inicioFila);
97
98    printf("\nDeseja apagar o primeiro registro? (S/N): \n");
99    scanf(" %c", &resp);
100   if (resp == 'S')
101   {
102     inicioFila = ApagaPrimeiro(inicioFila);
103     printf("\nPrimeiro registro apagado.\n");
104   }
105
106   printf("\nRegistros atuais:\n");
107   Exibe(inicioFila);
108
109   system("pause");
110   return 0;
111 }
```

## Explicação linha a linha

O programa tem quatro partes: bibliotecas, a estrutura de dados, três funções e o `main`. Cada tabela abaixo cobre uma parte.

### Linhas 1 a 4: bibliotecas

| Linha | Código | Função |
| --- | --- | --- |
| 1 | `#include <stdio.h>` | Traz `printf` (escreve na tela) e `scanf` (lê do teclado). |
| 2 | `#include <stdlib.h>` | Traz `system`, usado no final para `system("pause")`. |
| 3 | `#include <iostream>` | Biblioteca de entrada e saída do C++. O programa não a usa; ela veio do exemplo original. |
| 4 | `#include <string.h>` | Traz `strcpy`, que copia textos. |

### Linhas 6 a 13: a estrutura `ficha`

| Linha | Código | Função |
| --- | --- | --- |
| 6 | `struct ficha` | Cria um tipo novo chamado `ficha`: a "folha de cadastro". |
| 8 | `char nome[40];` | Guarda o nome: até 39 letras, mais o `\0` que marca o fim do texto. |
| 9 | `char cpf[15];` | Guarda o CPF: até 14 caracteres, por exemplo `123.456.789-00`. |
| 10 | `char rg[15];` | Guarda o RG, com o mesmo tamanho do CPF. |
| 11 | `int codigo;` | Guarda o código do cliente, que é um número inteiro. |
| 12 | `ficha *proximo;` | Guarda o endereço da próxima ficha. É esse campo que forma a fila. Na última ficha vale `NULL`. |
| 13 | `};` | Fecha a estrutura. O ponto e vírgula é obrigatório. |

### Linha 15: o apelido `endmem`

| Linha | Código | Função |
| --- | --- | --- |
| 15 | `typedef ficha* endmem;` | Cria o apelido `endmem` para "ponteiro para ficha". Assim, `endmem x;` equivale a `ficha *x;`. |

### Linhas 17 a 23: função `ExibeFicha`

Mostra os dados de **uma** ficha. Ela existe para não repetir os quatro `printf` em dois lugares do programa.

| Linha | Código | Função |
| --- | --- | --- |
| 17 | `void ExibeFicha(endmem f)` | `void`: não devolve nada. Recebe o endereço de uma ficha em `f`. |
| 19 | `printf("Codigo: %d\n", f->codigo);` | Mostra o código. `%d` é o espaço do número inteiro e `\n` pula a linha. O `->` acessa um campo através de um ponteiro. |
| 20 a 22 | `printf("Nome: %s\n", f->nome);` e as duas seguintes | Mostram nome, CPF e RG. `%s` é o espaço de um texto. |

### Linhas 25 a 35: função `Exibe`

Percorre a fila inteira, da primeira à última ficha.

| Linha | Código | Função |
| --- | --- | --- |
| 25 | `void Exibe(endmem primeiro)` | Recebe o endereço da primeira ficha da fila. |
| 27 e 28 | `endmem aux; aux = primeiro;` | Cria um ponteiro auxiliar que começa na primeira ficha. Ele anda pela fila sem perder o início. |
| 29 | `while (aux != NULL)` | Repete enquanto `aux` apontar para uma ficha real. Ao passar da última, `aux` vira `NULL` e o laço termina. |
| 31 | `ExibeFicha(aux);` | Mostra os dados da ficha atual. |
| 32 | `printf("--------------------\n");` | Desenha uma linha para separar os clientes. |
| 33 | `aux = aux->proximo;` | Avança para a próxima ficha. Sem esta linha, o laço nunca termina. |

### Linhas 37 a 47: função `ApagaPrimeiro`

| Linha | Código | Função |
| --- | --- | --- |
| 37 | `endmem ApagaPrimeiro(endmem primeiro)` | Devolve o **novo início** da fila depois da remoção. |
| 40 | `if (primeiro != NULL)` | Só apaga se a fila não estiver vazia. Sem isso o programa travaria numa fila vazia. |
| 42 | `aux = primeiro;` | Guarda o endereço da ficha que será apagada. |
| 43 | `primeiro = primeiro->proximo;` | Faz o início apontar para a segunda ficha. Se não houver segunda, vira `NULL`. |
| 44 | `delete aux;` | Libera a memória da ficha antiga. A ordem importa: apagar antes de avançar faria perder o endereço da segunda ficha. |
| 46 | `return primeiro;` | Devolve o novo início. É necessário porque o parâmetro é uma **cópia**: mudar `primeiro` aqui não muda `inicioFila` no `main`. |

### Linhas 49 a 59: função `main`, declarações

| Linha | Código | Função |
| --- | --- | --- |
| 49 | `int main()` | Ponto de partida: o programa começa a executar aqui. |
| 51 | `endmem inicioFila, fichaAnterior, auxiliarFicha;` | `inicioFila` aponta para a primeira ficha. `fichaAnterior` aponta para a última ficha inserida. `auxiliarFicha` aponta para a ficha recém-criada. |
| 52 a 54 | `char cliente[40]; char cpf[15]; char rg[15];` | Variáveis temporárias que recebem o que o usuário digita, antes de irem para a ficha. |
| 55 | `int codigo;` | Variável temporária para o código. |
| 56 | `char resp = 'S';` | Começa em `'S'` para o laço de cadastro rodar pelo menos uma vez. |
| 58 e 59 | `inicioFila = NULL; fichaAnterior = NULL;` | A fila começa vazia. Ponteiro sem valor definido é perigoso, então sempre se inicializa. |

### Linhas 61 a 70: leitura dos dados

| Linha | Código | Função |
| --- | --- | --- |
| 61 | `while (resp == 'S')` | Repete o cadastro enquanto o usuário responder `S`. |
| 63 e 64 | `printf(...)` e `scanf("%s", cliente);` | Pede e lê o nome. O `%s` lê uma palavra e para no primeiro espaço. |
| 65 a 68 | `scanf("%s", cpf);` e `scanf("%s", rg);` | Leem o CPF e o RG da mesma forma. |
| 69 e 70 | `scanf("%d", &codigo);` | Lê o código. O `&` informa o endereço da variável, porque o `scanf` precisa gravar o número nela. |

### Linhas 72 a 77: criação da ficha

| Linha | Código | Função |
| --- | --- | --- |
| 72 | `auxiliarFicha = new ficha;` | Reserva memória para uma ficha nova e guarda o endereço dela. |
| 73 a 75 | `strcpy(auxiliarFicha->nome, cliente);` e as duas seguintes | Copiam nome, CPF e RG para dentro da ficha. Vetores de `char` não aceitam `=`, por isso o `strcpy`. |
| 76 | `auxiliarFicha->codigo = codigo;` | O número é copiado com atribuição simples (`=`). |
| 77 | `auxiliarFicha->proximo = NULL;` | Toda ficha nova entra no final, então ainda não tem ninguém depois dela. |

### Linhas 78 a 86: encaixe na fila

Este é o trecho mais importante da aula.

| Linha | Código | Função |
| --- | --- | --- |
| 78 a 81 | `if (inicioFila == NULL) { inicioFila = auxiliarFicha; }` | Se a fila está vazia, a ficha nova vira a primeira. |
| 82 a 85 | `else { fichaAnterior->proximo = auxiliarFicha; }` | Senão, a última ficha existente passa a apontar para a nova, que fica encaixada no fim. |
| 86 | `fichaAnterior = auxiliarFicha;` | A ficha nova agora é a última e será a "anterior" na próxima volta. |

### Linhas 88 a 93: exibição após inserir e continuação

| Linha | Código | Função |
| --- | --- | --- |
| 88 e 89 | `printf("Registro inserido")` e `ExibeFicha(auxiliarFicha);` | Mostra na hora os dados da ficha que acabou de entrar na fila. |
| 91 e 92 | `scanf(" %c", &resp);` | Lê a resposta de continuação. O espaço antes de `%c` descarta o Enter que sobrou da leitura anterior. |
| 93 | `}` | Fim do laço. Qualquer resposta diferente de `S` encerra o cadastro. |

### Linhas 95 a 111: exibição, exclusão e final

| Linha | Código | Função |
| --- | --- | --- |
| 95 e 96 | `Exibe(inicioFila);` | Mostra todos os registros, na ordem em que foram digitados. |
| 98 e 99 | `printf(...)` e `scanf(" %c", &resp);` | Pergunta se o usuário quer apagar o primeiro registro. Reaproveita a variável `resp`. |
| 100 a 104 | `if (resp == 'S') { inicioFila = ApagaPrimeiro(inicioFila); ... }` | Se a resposta for `S`, chama a função e guarda o novo início em `inicioFila`. |
| 106 e 107 | `Exibe(inicioFila);` | Mostra a fila de novo, agora sem o primeiro, ou igual se o usuário respondeu que não. |
| 109 | `system("pause");` | Mantém a janela aberta no Windows até apertar uma tecla. |
| 110 | `return 0;` | Informa ao sistema que o programa terminou sem erro. |

## Aprofundamento: o que acontece por trás do código

As tabelas anteriores dizem **o que** cada linha faz. Esta seção explica **por quê**, com os pontos que costumam gerar dúvidas na turma.

### Onde cada coisa fica na memória

O programa usa duas áreas da memória, e entender a diferença explica o `new`.

| Área | O que fica nela | Quando some |
| --- | --- | --- |
| Pilha (stack) | Variáveis declaradas no código: `inicioFila`, `fichaAnterior`, `auxiliarFicha`, `cliente`, `cpf`, `rg`, `codigo`, `resp` | Sozinhas, quando a função termina |
| Heap | As fichas criadas com `new ficha` | Só quando o programador chama `delete` |

Por isso `inicioFila` é pequena: ela guarda só um endereço (o "número da casa"), enquanto as fichas, com nome, CPF, RG e código, ficam no heap. Se o programa só usasse variáveis comuns, o tamanho da fila teria que ser decidido antes de rodar. Com `new`, a fila cresce conforme o usuário digita.

### Por que `->` e não `.`

Quando se tem a ficha em si, acessa-se o campo com ponto: `minhaFicha.nome`. Quando se tem apenas o endereço da ficha (um ponteiro), usa-se a seta: `auxiliarFicha->nome`.

| Escrita com seta | Escrita equivalente | Significa |
| --- | --- | --- |
| `aux->nome` | `(*aux).nome` | Vá até o endereço guardado em `aux` e pegue o campo `nome` |
| `aux->proximo` | `(*aux).proximo` | Vá até a ficha de `aux` e pegue o endereço da próxima |

A seta é só uma forma mais curta e legível de escrever `(*aux).campo`.

### Os códigos de formato do `printf` e do `scanf`

| Código | Tipo | Exemplo no programa | Precisa de `&` no `scanf`? |
| --- | --- | --- | --- |
| `%s` | Texto (vetor de `char`) | `scanf("%s", cliente);` | Não, pois o nome do vetor já é um endereço |
| `%d` | Número inteiro | `scanf("%d", &codigo);` | Sim, o `scanf` precisa saber onde gravar |
| `%c` | Um único caractere | `scanf(" %c", &resp);` | Sim, pelo mesmo motivo |

Pergunta para a turma: por que `scanf("%s", cliente)` não tem `&`, e `scanf("%d", &codigo)` tem? A resposta é que `cliente` é um vetor, e o nome de um vetor já representa o endereço do seu primeiro elemento.

### Por que `fichaAnterior` existe

Para inserir no final da fila, é preciso saber quem é a última ficha. Há duas formas de resolver:

| Solução | Como funciona | Custo |
| --- | --- | --- |
| Percorrer a fila inteira a cada inserção | Começa em `inicioFila` e anda até achar a ficha com `proximo == NULL` | Quanto maior a fila, mais lenta cada inserção |
| Guardar a última ficha em `fichaAnterior` (solução do programa) | A inserção usa direto `fichaAnterior->proximo = auxiliarFicha;` | Uma única variável a mais, e a inserção é sempre rápida |

O nome é "anterior" porque, no momento de inserir uma ficha nova, a última ficha existente é a **anterior** a ela.

### Por que `strcpy` e não `=`

O nome de um vetor de `char` é um endereço fixo, não uma variável que aceita atribuição. Escrever `auxiliarFicha->nome = cliente;` não compila. O `strcpy(destino, origem)` copia letra por letra, incluindo o `\0` final.

Já o `codigo` é um `int`, que cabe numa única variável, e por isso aceita `=` diretamente (linha 76).

### Passagem por valor: por que `ApagaPrimeiro` devolve o início

Em C++, quando uma função recebe um parâmetro, ela trabalha com uma **cópia**. Veja o que acontece na chamada `inicioFila = ApagaPrimeiro(inicioFila);`:

1. O valor de `inicioFila` (o endereço de Ana) é copiado para o parâmetro `primeiro`.
2. Dentro da função, `primeiro` passa a valer o endereço de Bruno. A variável `inicioFila` do `main` continua valendo o endereço de Ana.
3. A função devolve o endereço de Bruno com `return primeiro;`.
4. O `main` guarda esse valor em `inicioFila`, que só então passa a apontar para Bruno.

Se o `main` apenas chamasse `ApagaPrimeiro(inicioFila);` sem guardar o retorno, `inicioFila` ficaria apontando para uma ficha já apagada, e o programa quebraria ao exibir a fila.

### O problema do Enter no `scanf`

Quando o usuário digita `S` e aperta Enter, o `scanf` consome o `S`, mas o Enter (`\n`) fica esperando no teclado. Se a próxima leitura fosse `scanf("%c", &resp)`, ela leria esse Enter em vez de uma resposta nova.

O espaço em `" %c"` manda o `scanf` ignorar espaços, tabulações e Enters antes de ler o caractere. As leituras com `%s` e `%d` já ignoram esses espaços sozinhas.

### Rastreio de variáveis (teste de mesa)

Execução com dois clientes: Ana (código 1) e Bruno (código 2). A tabela mostra o valor de cada ponteiro depois das linhas indicadas. As letras A e B representam os endereços das fichas de Ana e de Bruno.

| Momento | `inicioFila` | `fichaAnterior` | `auxiliarFicha` | Ficha de Ana: `proximo` | Ficha de Bruno: `proximo` |
| --- | --- | --- | --- | --- | --- |
| Linhas 58 e 59 | `NULL` | `NULL` | indefinido | não existe | não existe |
| Linha 77, Ana | `NULL` | `NULL` | A | `NULL` | não existe |
| Linha 86, Ana | A | A | A | `NULL` | não existe |
| Linha 77, Bruno | A | A | B | `NULL` | `NULL` |
| Linha 84, Bruno | A | A | B | B | `NULL` |
| Linha 86, Bruno | A | B | B | B | `NULL` |
| Linha 43 (apagar o primeiro) | B | B | B | A será apagada | `NULL` |

Observação: na linha 77 de Ana, `inicioFila` ainda vale `NULL`. Ela só passa a valer A na linha 80, dentro do `if`.

## Simulação passo a passo

Sugestão: desenhe cada passo no quadro enquanto a turma acompanha o código. Exemplo com três clientes: Ana (código 1), Bruno (código 2) e Carla (código 3).

**Passo 1: a fila está vazia (linhas 58 e 59)**

```
inicioFila → NULL
```

**Passo 2: entra Ana (linha 80, pois `inicioFila == NULL`)**

```
inicioFila → [Ana | NULL]
fichaAnterior → [Ana | NULL]
```

**Passo 3: entra Bruno (linha 84, ramo `else`)**

```
inicioFila → [Ana | •] → [Bruno | NULL]
fichaAnterior → [Bruno | NULL]
```

**Passo 4: entra Carla (linha 84 de novo)**

```
inicioFila → [Ana | •] → [Bruno | •] → [Carla | NULL]
fichaAnterior → [Carla | NULL]
```

**Passo 5: o usuário apaga o primeiro (linhas 42 a 44)**

```
aux = Ana
inicioFila passa para Bruno
delete aux libera a memória de Ana

inicioFila → [Bruno | •] → [Carla | NULL]
```

O símbolo `•` representa o endereço guardado em `proximo`. Pergunta para a turma: o que aconteceria se a linha 44 viesse antes da linha 43? A resposta é que o endereço de Bruno seria perdido e a fila inteira ficaria inacessível.

## Erros comuns e pontos de atenção

| Erro | Consequência | Como evitar |
| --- | --- | --- |
| Digitar nome com 40 caracteres ou mais | O texto passa do vetor `nome[40]` e corrompe a memória | Limitar a leitura, por exemplo `scanf("%39s", cliente);` |
| Usar espaço em nome, CPF ou RG | O `scanf("%s")` para no espaço e o restante atrapalha as próximas leituras | Digitar sem espaços, ou usar `fgets` |
| Esquecer `proximo = NULL` na ficha nova | O ponteiro fica com lixo e `Exibe` pode travar | Sempre inicializar (linha 77) |
| Esquecer `aux = aux->proximo` no laço | Laço infinito | Conferir a linha 33 |
| Apagar sem verificar fila vazia | O programa fecha com erro | Manter o `if (primeiro != NULL)` (linha 40) |
| Não liberar as fichas no final | Vazamento de memória: as fichas restantes nunca recebem `delete` | Percorrer a fila com `delete` antes de encerrar |

Observação para a turma: `scanf("%s", &resp)`, como estava no exemplo original, grava além do `char`. Por isso o código usa `scanf(" %c", &resp)`.

## Exercícios propostos

1. Mostre a fila e pergunte ao usuário se quer apagar **o último** registro. Qual dificuldade aparece, já que a lista só tem ponteiro para o próximo?
2. Crie uma função `Conta(endmem primeiro)` que devolve quantas fichas existem na fila.
3. Crie uma função que recebe um código e procura o cliente na fila, mostrando os dados ou avisando "não encontrado".
4. Ao final do programa, percorra a fila e aplique `delete` em todas as fichas para não deixar vazamento de memória.
5. Troque o `scanf("%s")` do nome por `fgets`, para aceitar nomes com espaço, como "Ana Paula".
6. Desafio: permita apagar o registro que tenha um determinado código, em qualquer posição da fila.
