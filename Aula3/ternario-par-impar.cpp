#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero;

    cout << "Digite um número: ";
    cin >> numero;

    string paridade = (numero % 2 == 0) ? "par" : "impar";
    cout << "O número é " << paridade << endl;

    return 0;
}
