#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double celsius, fahrenheit;

    cout << "Informe a temperatura em graus Fahrenheit: ";
    cin >> fahrenheit;

    celsius = ((fahrenheit - 32) * 5) / 9;

    cout << "\nA temperatura em graus Celsius é: " << celsius;
    return 0;
}

