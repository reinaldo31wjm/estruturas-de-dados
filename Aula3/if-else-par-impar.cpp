#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int num;

    cout << "Digite um número: ";
    cin >> num;

    if (num == 0)
        cout << "O número é zero";
    else if (num % 2 == 0)
        cout << "O número é par";
    else
        cout << "O número é ímpar";
    
    return 0;
}
