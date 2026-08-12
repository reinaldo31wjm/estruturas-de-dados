#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float a, b, soma, sub, div, mul;
    
    cout << "Informe o valor de A: ";
    cin >> a;
    cout << "Informe o valor de B: ";
    cin >> b;
    
    soma = a + b;
    sub = a - b;
    div = a / b;
    mul = a * b;
    
    cout << "\nA soma de A e B é: " << soma;
    cout << "\nA subtração de A e B é: " << sub;
    cout << "\nA divisão de A por B é: " << div;
    cout << "\nA multi de A por B é: " << mul;
    
}

    
    
    
